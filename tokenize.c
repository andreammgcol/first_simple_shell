#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
  * tokenize - Extract tokens from string
  * @str: The string to tokenize
  * @del: The delimiter of tokenization
  * @len: Tokens number
  *
  * Return: An array of tokens of the string
  */
char **tokenize(char *str, char *del, int len)
{
	char **tokens, *token, *temp;
	int i = 0;

	tokens = malloc(sizeof(char *) * (len + 1));
	if (!tokens)
		return (NULL);

	str = remove_new_line(str);
	temp = strdup(str);
	token = strtok(temp, del);

	while (token)
	{
		tokens[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (!tokens[i])
		{
			for (; i >= 0; i--)
				free(tokens[i]);

			free(tokens);
			return (NULL);
		}

		tokens[i] = strdup(token);
		token = strtok(NULL, del);
		i++;
	}

	tokens[i] = NULL;
	free(temp);
	return (tokens);
}
