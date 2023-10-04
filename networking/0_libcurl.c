#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>  // -lcurl

size_t got_data_cb(char *buffer, size_t itemsize, size_t n_items, void* ignorethis);

int main(void) {
    CURL *curl = curl_easy_init();

    if (!curl) {
        fprintf(stderr, "Init failed!\n");
        return EXIT_FAILURE;
    }
    
    // set options
    // curl_easy_setopt(curl, CURLOPT_URL, "https://thebestmotherfucking.website");
    curl_easy_setopt(curl, CURLOPT_URL, "ftp://demo:password@test.rebex.net/readme.txt");
        // write to got_data instead of stdout
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, got_data_cb);

    // perform operations
    CURLcode result = curl_easy_perform(curl);

    if (result != CURLE_OK) {
        fprintf(stderr, "Download problem: %s\n", curl_easy_strerror(result));
    }
    

    curl_easy_cleanup(curl);
    
    
    return EXIT_SUCCESS;
}

size_t got_data_cb(char *buffer, size_t itemsize, size_t n_items,
                                                void* ignorethis) {
    // itemsize is always 1
    size_t bytes = itemsize * n_items;
    printf("New chunk (%zu bytes)\n", bytes);
    
    int line_number = 1;
    printf("%d:\t", line_number);
    
    for (int i=0; i<bytes; i++) {
        printf("%c", buffer[i]);
        if (buffer[i] == '\n') {
            line_number++;
            printf("%d:\t", line_number);
        }
    }
    
    printf("\n\n");

    return bytes; // i processed all the bytes in the buffer
}