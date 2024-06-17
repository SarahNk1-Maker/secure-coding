#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 256

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return -1;
    }

    // Validate and sanitize input (only allow alphanumeric and safe characters for file path)
    // Ensure input is safe to use as a filename
    char safe_characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_-./";
    size_t len = strlen(argv[1]);
    for (size_t i = 0; i < len; ++i) {
        if (strchr(safe_characters, argv[1][i]) == NULL) {
            fprintf(stderr, "Invalid characters in filename.\n");
            return -1;
        }
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Move file pointer to end to get file size
    fseek(fp, 0L, SEEK_END);
    long file_size = ftell(fp);

    if (file_size == -1) {
        perror("Error getting file size");
        fclose(fp);
        return -1;
    }

    printf("File size: %ld bytes\n", file_size);

    fclose(fp);
    return 0;
}

