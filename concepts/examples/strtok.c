#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
  * main - Extract tokens from strings
  *
  * Return: Always zero
  */
int main(void)
{
	char str[] = "One love, one heart, one destiny Bob Marley";
	char *token;

	token = strtok(str, " ");

	while (token)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}

	return (0);
}
