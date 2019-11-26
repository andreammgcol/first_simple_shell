#include "shell.h"

/**
  * _print_env - Prints the environment built-in
  *
  * Return: Nothing to returns
  */
void _print_env(void)
{
	int i = 0;

	while (environ[i])
	{
		puts(environ[i]);
		i++;
	}
}
