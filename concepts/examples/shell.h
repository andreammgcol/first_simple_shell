#ifndef _SHELL_
#define _SHELL_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int count_words(char *str, char *delim);
char **splits_string(char *str, char *delim, int c_words);
char *remove_new_line(char *str);

#endif