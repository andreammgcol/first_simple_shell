#include "shell.h"

/**
  * _strcat - Concatenates two strings
  * @dest: The destination string
  * @src: The source string
  *
  * Return: A pointer to the resulting string dest
  */
char *_strcat(char *dest, char *src)
{
	int dlen = 0, i = 0;

	while (dest[dlen])
		dlen++;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[dlen] = src[i];
		dlen++;
	}

	dest[dlen] = '\0';
	return (dest);
}

/**
  * _strlen - Counts the length of a string
  * @s: The string to counts
  *
  * Return: The length of a string
  */
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;

	return (i);
}

/**
  * _getenv - Gets an environment variable
  * @name: The variable to find in the system environment
  *
  * Return: The content of the environment variable
  */
char *_getenv(const char *name)
{
	int i = 0;
	char *env_var = NULL;

	while (environ[i])
	{
		if (!strncmp(name, environ[i], strlen(name)))
		{
			env_var = strdup(environ[i]);
			while (*env_var != '=')
				env_var++;

			++env_var;
			return (env_var);
		}
		i++;
	}

	return (NULL);
}
