#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 256

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "please provide the address of the file as an input.\n");
        return -1;
    }

    // Validate that the input file name is safe
    if (strpbrk(argv[1], "&;`'\"|*?~<>^()[]{}$\\") != NULL) {
        fprintf(stderr, "Invalid characters in input.\n");
        return -1;
    }

    // Construct the command using snprintf for safety
    char cmd[BUFSIZE];
    snprintf(cmd, sizeof(cmd), "wc -c < %s", argv[1]);

    // Use popen to safely execute the command and read the output
    FILE *fp;
    char result[BUFSIZE];

    if ((fp = popen(cmd, "r")) == NULL) {
        fprintf(stderr, "Error opening pipe.\n");
        return -1;
    }

    // Read the output of the command
    if (fgets(result, sizeof(result), fp) != NULL) {
        printf("%s", result);
    } else {
        fprintf(stderr, "Error reading result.\n");
        pclose(fp);
        return -1;
    }

    // Close the pipe
    pclose(fp);
    return 0;
}
