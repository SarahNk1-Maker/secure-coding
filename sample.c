#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 256

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "please provide the address of the file as an input.\n");
        return -1;
    }

    char cmd[BUFSIZE];
    snprintf(cmd, sizeof(cmd), "wc -c < %s", argv[1]);

    // Validate that the input does not contain any characters that could lead to command injection
    if (strpbrk(argv[1], "&;`'\"|*?~<>^()[]{}$\\") != NULL) {
        fprintf(stderr, "Invalid characters in input.\n");
        return -1;
    }

    system(cmd);

    return 0;
}


