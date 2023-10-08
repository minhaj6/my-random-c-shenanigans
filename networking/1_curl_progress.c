
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>  // -lcurl
#include <stdbool.h>

const int PROG_BAR_LENGTH = 40;

typedef struct {
    long total_bytes;
    long total_expected;
    double exp_byte_per_url;
    long current_bytes;
    long urls_so_far;
    long total_urls;
} statusinfo;

/* exponentially weighted moving average predictor */
const double PREDICT_WEIGHT = 0.4;

void update_bar(int prog, statusinfo *sinfo);
size_t got_data_cb(char *buffer, size_t itemsize, size_t n_items, void* stinfo);
bool download_url(char *url, statusinfo *sinfo);
double predict_next(double last_prediction, double actual);

int main(void) {
    char *urls[] = {
        "https://minhaj6.github.io/assets/img/avatar/cropped_photo.jpg",
        "https://minhaj6.github.io/assets/img/icons/iut_cropped.png",
        "https://minhaj6.github.io/assets/pdf/minhaj_cv.pdf"
    };

    const int num_urls = (sizeof(urls)/sizeof(urls[0]));
    statusinfo sinfo;
    sinfo.total_bytes = 0;
    sinfo.urls_so_far = 0;
    sinfo.total_urls = num_urls;
    sinfo.exp_byte_per_url = 150000; // 150KByte

    update_bar(0, &sinfo);
    for (int i=0; i < num_urls; i++) {
        sinfo.current_bytes = 0;
        download_url(urls[i], &sinfo);
        sinfo.urls_so_far++;
        sinfo.exp_byte_per_url = predict_next(sinfo.exp_byte_per_url, sinfo.current_bytes);
    }
    update_bar(100, &sinfo);
    
    return EXIT_SUCCESS;
}

double predict_next(double last_prediction, double actual) {
    return ((last_prediction * (1-PREDICT_WEIGHT)) + (actual * PREDICT_WEIGHT));
}

size_t got_data_cb(char *buffer, size_t itemsize, size_t n_items,
                                                void* stinfo) {
    statusinfo *status = stinfo;
    
    // itemsize is always 1
    size_t bytes = itemsize * n_items;
    // printf("New chunk (%zu bytes)\n", bytes);

    status->current_bytes += bytes;
    status->total_bytes += bytes;
    long urls_left = (status->total_urls - status->urls_so_far);
    long estimate_current = status->exp_byte_per_url;
    
    if (status->current_bytes > status->exp_byte_per_url) {
        estimate_current = (status->current_bytes * 4)/3;
    }

    double guess_next_prediction = predict_next(status->exp_byte_per_url,
                                            estimate_current);

    long estimated_total = status->total_bytes + (estimate_current - status->current_bytes)
                                + (urls_left-1) * guess_next_prediction;

    long percent_done = (status->total_bytes * 100) / estimated_total;

    update_bar(percent_done, status);

    return bytes; // i processed all the bytes in the buffer
}

void update_bar(int percent_done, statusinfo *sinfo) {
    int num_char = (percent_done * PROG_BAR_LENGTH) / 100;
    printf("\r[");
    for (int i=0; i<num_char; i++) {
        printf("#");
    }
    
    for (int i=0; i < (PROG_BAR_LENGTH - num_char); i++) {
        printf(" ");
    }
    
    printf("] %d%% Done (%ld) KBytes", percent_done, sinfo->total_bytes/1000);
    fflush(stdout);
}


bool download_url(char *url, statusinfo *sinfo) {
    CURL *curl = curl_easy_init();

    if (!curl) {
        fprintf(stderr, "Init failed!\n");
        return EXIT_FAILURE;
    }
    
    /* set options */
    // curl_easy_setopt(curl, CURLOPT_URL, "ftp://demo:password@test.rebex.net/readme.txt");
    curl_easy_setopt(curl, CURLOPT_URL, url);

    // write to got_data instead of stdout
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, got_data_cb);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, sinfo);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1); // follow redirect urls

    /* perform operations */
    CURLcode result = curl_easy_perform(curl);

    curl_easy_cleanup(curl);

    if (result != CURLE_OK) {
        fprintf(stderr, "Download problem: %s\n", curl_easy_strerror(result));
        return false;
    }

    return true;
}