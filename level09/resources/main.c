#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void main(int args, void **argv) {
    int i = 0;
    char *str = argv[1];
    char *decrypt = (char *)malloc(sizeof(char) * strlen(str));
    while (str[i] != 0) {
        decrypt[i] = str[i] - i;
        i++;
    }
    decrypt[i] = 0;
    printf("%s\n", decrypt);
    free(decrypt);
}