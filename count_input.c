#include "shell.h"

/**
  * count_words - Counts the words from the user input in prompt
  * @str: The string
  * @del: The delim to find
  *
  * Return: ...
  */
int count_input(char *str, char del)
{
	int i = 0, cw = 0;

	while (str[i])
	{
		if (str[i] == '\n')
			break;

		if (str[i] != del)
		{
			cw++;
			while (str[i] != del)
			{
				if (!str[i])
					break;
				i++;
			}
		}
		i++;
	}

	return (cw);
}