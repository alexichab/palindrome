#include "palindrome.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>

wchar_t abc[]=
L"абвгдеёжзийклмнопрстуфхцчшщьыъэюя";
wchar_t ABC[]=
L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЬЫЪЭЮЯ";
wchar_t word[256]= { 0 } ;

int isPalindrome(wchar_t *str)
{
    int l = 0;
    int h = wcslen(str) - 1;
    while (h > l)
    {
        if (str[l++] != str[h--])
        {  
            return 0;
        }
    }
    return 1;
}

wchar_t *wtolower(wchar_t *str){
    for(int j = 0; j < wcslen(str);j++){
    if (wcschr(ABC,str[j])){
        wchar_t symbol=L'0';
        wcsncpy(&symbol,wcschr(ABC,str[j]),1);
        for(int i=0; i<wcslen(ABC);i++){
            if(ABC[i]==symbol)
            str[j] = abc[i];
        }
    }
    }
    return str;
}

wchar_t remove_ch(wchar_t *s, wchar_t ch){
    int i,j;
    j=0;
    for(i=0;s[i];i++){
        if(!iswspace(s[i]))
            s[j++] = s[i];
    }
    s[j] = '\0';
    return 0;
}

void remove_prep(wchar_t *s){
    wchar_t *last = s;
    while (*last){
        while(*last && !iswpunct(*last))
                *s++ = *last++;
        while (*last && iswpunct(*last))
        last++;
    }
    *s= '\0';
}