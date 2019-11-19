#include "shell.h"

/**
  * splits_string - Extract tokens from strings
  * @str: ...
  * @delim: ...
  * @c_a_words: ...
  * 
  * Return: Always zero
  */
char **splits_string(char *str, char *delim, int c_a_words)
{
	char **a_words, *token, *buffer;
	int i = 0;

	str = remove_new_line(str);
	buffer = malloc(sizeof(char) * (strlen(str) + 1));
	if (!buffer)
		return (NULL);

	a_words = malloc(sizeof(char *) * (c_a_words + 1));
	if (!a_words)
		return (NULL);

	strcpy(buffer, str);
	token = strtok(buffer, delim);

	while (token)
	{
		a_words[i] = malloc(sizeof(char) * (strlen(token) + 1));
		if (!a_words[i])
		{
			for (; i >= 0; i--)
				free(a_words[i]);

			free(a_words);
			return (NULL);
		}

		strcpy(a_words[i], token);
		token = strtok(NULL, delim);
		i++;
	}

	a_words[i] = NULL;
	free(buffer);
	return (a_words);
}
