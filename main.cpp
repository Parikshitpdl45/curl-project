#pragma comment(lib, "libcurl.lib")

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curl/curl.h>

// Prevent libcurl from printing HTTP response to console
static size_t discard_callback(void* ptr, size_t size, size_t nmemb, void* userdata)
{
    (void)ptr; (void)userdata;
    return size * nmemb;
}

void sendData(const char* postFields)
{
    CURL* curl = curl_easy_init();
    if (!curl) {
        printf("Failed to init curl\n");
        return;
    }

    curl_easy_setopt(curl, CURLOPT_URL,
        "http://shell.puv.fi/~e2401825/receiver.php");

    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postFields);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, discard_callback);

    CURLcode res = curl_easy_perform(curl);

    if (res != CURLE_OK) {
        fprintf(stderr, "curl error: %s\n", curl_easy_strerror(res));
    }
    else {
        long http_code = 0;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
        printf("HTTP response code: %ld\n", http_code);
    }

    curl_easy_cleanup(curl);
}

int main()
{
    srand((unsigned)time(NULL));

    int v1 = rand() % 101;
    int v2 = rand() % 101;

    char data[128];
    sprintf_s(data, "user=student&v1=%d&v2=%d", v1, v2);

    sendData(data);
    printf("Sent data: %s\n", data);

    return 0;
}
