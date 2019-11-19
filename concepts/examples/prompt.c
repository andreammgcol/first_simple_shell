#include "shell.h"

/**
  * main - Entry point to shell
  *
  * Return: Always zero
  */
int main(void)
{
	char *line = NULL, **a_words;
	size_t size = 0;
	ssize_t len_line = 0;
	int c_words = 0, k = 0;

	while (len_line >= 0)
	{
		write(STDOUT_FILENO, "$ ", 2);
		len_line = getline(&line, &size, stdin);
		if (len_line == -1)
			break;
		c_words = count_words(line, " ");
		a_words = splits_string(line, " ", c_words);

		if (execve(a_words[0], a_words, NULL) == -1)
			perror("Error:");

		write(STDOUT_FILENO, line, len_line);

		for (k = c_words; k >= 0; k--)
			free(a_words[k]);

		free(a_words);
	}

	free(line);
	return (0);
}
