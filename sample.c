#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 256

int main(int argc,char** argv) {

if (argc!=2) {
fprintf(stderr,"please provide the address of the file as an input.\n");
return -1;

}
char cmd[BUFSIZE] = "wc -c <";

strcat(cmd,argc[1]);
system(cmd);
}
