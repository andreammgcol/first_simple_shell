#ifndef _SHELL_
#define _SHELL_

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

extern char **environ;

char **tokenize(char *str, char *del, int len);
char *find(char *pathname);
int exec(char *cname, char **opts);
char *concat_path(char *pathname, char *prog_name);
char *remove_new_line(char *str);
int count_input(char *str, char del);
int count_delims(char *str, char *del);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_getenv(const char *name);
void signal_handler(int signo);
int execBuiltInCommands(char **u_tokns);
void openHelp(void);

#endif
