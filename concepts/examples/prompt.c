#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int count_delimiters(char *str, char *delim);
char **splits_string(char *str, char *delim, int c_words);

/**
  * main - Entry point to shell
  *
  * Return: Always zero
  */
int main(void)
{
	char *line = NULL, **prints;
	size_t sz = 0;
	ssize_t len = 0;
	int c_words = 0, i = 0;

	while (len >= 0)
	{
		write(STDOUT_FILENO, "$ ", 2);
		len = getline(&line, &sz, stdin);
		c_words = count_delimiters(line, " ") + 1;
		prints = splits_string(line, " ", c_words);

		while (i < c_words)
		{
			printf("Value of prints: %s\n", prints[i]);
			i++;
		}

		write(STDOUT_FILENO, line, len);
	}

	free(prints);
	free(line);
	return (0);
}

int count_delimiters(char *str, char *delim)
{
	int i = 0, cd = 0;

	while (str[i])
	{
		if (str[i] == delim[0])
			cd++;
		i++;
	}

	return (cd);
}

/**
  * splits_string - Extract tokens from strings
  *
  * Return: Always zero
  */
char **splits_string(char *str, char *delim, int c_words)
{
	char **words, *token, *buffer;
	int i = 0, aux = 0;

	buffer = malloc(sizeof(str));
	if (!buffer)
		return (NULL);

	words = malloc(sizeof(char *) * c_words);
	if (!words)
		return (NULL);

	strcpy(buffer, str);
	token = strtok(buffer, delim);

	while (token)
	{
		words[i] = malloc(sizeof(char) * (strlen(token) + 1));
		if (!words[i])
		{
			for (aux = i; aux >= 0; aux--)
				free(words[aux]);

			free(words);
			return (NULL);
		}

		strcpy(words[i], token);
		token = strtok(NULL, delim);
		i++;
	}

	free(buffer);
	return (words);
}

