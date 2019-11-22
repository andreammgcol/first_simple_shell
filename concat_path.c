#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "shell.h"

/**
  * concat_path - Select the correct path to a executable
  * @u_tkns: ...
  * @str: The program
  *
  * Return: ...
  */
char *concat_path(char *pathname, char *prog_name)
{
	int prog_len = 0, path_len = 0; 

	prog_len = _strlen(prog_name);
	path_len = _strlen(pathname);
	pathname = realloc(pathname, sizeof(char) * (path_len + prog_len + 2));
	if (!pathname)
		return (NULL);

	strcat(pathname, "/");
	strcat(pathname, prog_name);

	return (pathname);
}
