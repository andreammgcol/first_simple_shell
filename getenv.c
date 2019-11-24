#include "shell.h"

/**
  * _getenv - Gets an environment variable
  * @name: Environment variable name
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
