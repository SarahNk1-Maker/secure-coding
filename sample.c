#include <stdio.h>
#include <stdlib.h>
#include <string.h>    

#define BUFSIZE 256
                                
int read_file(const char *filename) {
    FILE* ptr = fopen(filename, "r");
                                
    if (ptr == NULL) {
        printf("File cannot be opened.\n");
        return(-1);
    }
                                
    char buff[BUFSIZE];
                                
    while (fgets(buff, BUFSIZE, ptr) != NULL) {
        printf("%s", buff);
    }
        
    return 0; 
}
