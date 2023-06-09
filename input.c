#include "input.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

#define SIZE_INCREMENT 1

void printHelp() {
    printf("\n Используйте команду:\n");
    printf("\tpalindrome <текстовый документ>\n\n");
}

int isSuffix(char *substring, char *string) {
    int n1 = strlen(substring), n2 = strlen(string);
    if (n1 > n2) {
        return -1;
    }
    for (int i=0; i<n1; i++) {
        if (substring[n1 - i - 1] != string[n2 - i - 1]) {
            return -1;
        }
    }
    return 0;
}

int checkArgs(int argc, char **argv) {
    if(argc != 2 || isSuffix(".txt", argv[1]) != 0) {
        printHelp();
        return -1;
    }
    return 0;
}

wchar_t *getInput(char *filename, int *lengthCount) {
    *lengthCount = 0;
    wchar_t buffer;
    int size = SIZE_INCREMENT;
    wchar_t *words = (wchar_t*)malloc(size * sizeof(wchar_t));
    if(words == NULL) {
        printf("Ошибка при выделении памяти для массива\n");
        free(words);
        return NULL;
    }
    FILE *input = fopen(filename, "r");
    if(input == NULL) {
        free(words);
        return NULL;
    }
    while(1) {
        buffer = fgetwc(input);
        if(feof(input)){
            break;
        }
        if(buffer == '\n'){
            continue;
        }
        if(*lengthCount >= size)  {
            size += SIZE_INCREMENT;
            words = (wchar_t*) realloc(words, size * sizeof(wchar_t));
        }
        words[*lengthCount]=buffer;
        (*lengthCount)++;
    }
    fclose(input);
    return words;
}

