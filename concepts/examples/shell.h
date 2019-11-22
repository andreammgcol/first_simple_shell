#ifndef _SHELL_
#define _SHELL_

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int count_words(char *str, char *delim);
char **splits_string(char *str, char *delim, int c_words);
char *remove_new_line(char *str);
void parent(pid_t child);
void perform_task(char *command, char **options);
int count_delimiters(char *str, char *delim);

#endif