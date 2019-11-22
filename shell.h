#ifndef _SHELL_
#define _SHELL_

#include <sys/types.h>

extern char **environ;

char **tokenize(char *str, char *del, int len);
char *find_command(char *pathname);
char *concat_path(char *pathname, char *prog_name);
char *remove_new_line(char *str);
int count_delims(char *str, char *del);
int count_input(char *str, char del);
char *_getenv(const char *name);
int _strlen(char *s);
void perform_task(char *command, char **options);
void parent(pid_t child);

#endif
