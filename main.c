#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "palindrome.h"
#include <wchar.h>
#include <locale.h>

int main(int argc, char **argv)
{
    if(checkArgs(argc, argv) == -1) {
        return -1;
    }
    int lengthCount = 0;
    setlocale(LC_ALL, "");
    wchar_t *words = getInput(argv[1], &lengthCount);
    if(words == NULL) {
        printf("Невозможно открыть файл %s\n", argv[1]);
        printHelp();
        return 0;
    }
    wchar_t *copywords = malloc(wcslen(words)*sizeof(wchar_t));
    wcscpy(copywords,words);
    remove_ch(words,' ');
    if(!*words){
        return -1;
    }
    printf("%ls\n", copywords);
    wchar_t *s;
    wchar_t *p=wcstok(copywords,L"!.?",&s);
    wchar_t *copy = malloc(wcslen(s)*sizeof(wchar_t));
    
    if (p!=NULL)
        {while(p){
        wcscpy(copy,p);
        remove_ch(p,' ');
        remove_prep(p);
        wtolower(p);
        if(isPalindrome(p))
        printf("%ls - это палиндром \n", copy);
        p=wcstok(NULL,L"!.?", &s);
    }
        }
    free(copy);
    return 0;
}

