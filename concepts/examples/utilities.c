#include "shell.h"

/**
  * count_words - Counts the words of a string
  * @str: ...
  * @delim: ...
  *
  * Return: ...
  */
int count_words(char *str, char *delim)
{
	int cw = 0, k = 0;

	while (str[k])
	{
		if (str[k] == '\n')
			break;

		if (str[k] == delim[0])
			k++;
		else
		{
			cw++;
			while (str[k] != delim[0])
			{
				if (!str[k])
					break;
				k++;
			}
		}
	}

	return (cw);
}

/**
  * remove_new_line - Removes a new line from string
  * @str: The string
  *
  * Return: ...
  */
char *remove_new_line(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}

	return (str);
}
