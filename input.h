#pragma once
#include <wchar.h>

void formatString(wchar_t *p);
void printHelp();
int checkArgs(int argc, char **argv);
wchar_t *getInput(char *filename, int *wordCount);
int isSuffix(char *substring, char *string);
