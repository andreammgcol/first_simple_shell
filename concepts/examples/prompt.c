#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
  * main - Entry point to shell
  *
  * Return: Always zero
  */
int main(void)
{
	char *line = NULL;
	size_t sz = 0;
	ssize_t len = 0;

	while (len >= 0)
	{
		write(STDOUT_FILENO, "$ ", 2);
		len = getline(&line, &sz, stdin);
		write(STDOUT_FILENO, line, len);
	}

	free(line);
	return (0);
}
