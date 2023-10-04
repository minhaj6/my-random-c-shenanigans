
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>  // -lcurl
#include <stdbool.h>

const int PROG_BAR_LENGTH = 40;

typedef struct {
    long total_bytes;

} statusinfo;

void update_bar(int prog, statusinfo *sinfo);
size_t got_data_cb(char *buffer, size_t itemsize, size_t n_items, void* stinfo);
bool download_url(char *url, statusinfo *sinfo);

int main(void) {
    char *urls[] = {
        "https://minhaj6.github.io/assets/img/avatar/cropped_photo.jpg",
        "https://minhaj6.github.io/assets/img/icons/iut_cropped.png",
        "https://minhaj6.github.io/assets/pdf/minhaj_cv.pdf"
    };

    const int num_urls = (sizeof(urls)/sizeof(urls[0]));
    statusinfo sinfo;
    sinfo.total_bytes = 0;

    update_bar(0, &sinfo);
    for (int i=0; i < num_urls; i++) {
        download_url(urls[i], &sinfo);
        update_bar(((i+1)*100)/num_urls, &sinfo);
    }
    
    return EXIT_SUCCESS;
}

size_t got_data_cb(char *buffer, size_t itemsize, size_t n_items,
                                                void* stinfo) {
    statusinfo *status = stinfo;
    

    // itemsize is always 1
    size_t bytes = itemsize * n_items;
    // printf("New chunk (%zu bytes)\n", bytes);

    status->total_bytes += bytes;

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
    
    printf("] %d%% Done (%ld) Bytes", percent_done, sinfo->total_bytes);
    fflush(stdout);
}


bool download_url(char *url, statusinfo *sinfo) {
    CURL *curl = curl_easy_init();

    if (!curl) {
        fprintf(stderr, "Init failed!\n");
        return EXIT_FAILURE;
    }
    
    /* set options */
    // curl_easy_setopt(curl, CURLOPT_URL, "https://thebestmotherfucking.website");
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