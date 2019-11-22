#include <stdio.h>
#include "shell.h"

/**
  * count_delims - Counts the tokens from a string
  * @str: The string 
  * @del: The delimiter
  *
  * Return: The number of tokens in a string
  */
int count_delims(char *str, char *del)
{
	int i = 0, j = 0, cw = 0;

	while (del[i])
	{
		j = 0;
		while (str[j])
		{
			if (str[j] == del[i])
				cw++;
			j++;
		}
		i++;
	}

	return (cw);
}
