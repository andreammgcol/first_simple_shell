#include "shell.h"

/**
 * execBuiltInCommands - Executes a built-in command
 * @u_tokns: ...
 *
 * Return: 1 if is a built-in command or 0 if not
 */
int execBuiltInCommands(char **u_tokns)
{
	int i = 0;
	char *ListBuiltinCmds[] = { "exit", "cd", "help", NULL };

	while (ListBuiltinCmds[i])
	{
		if (!strcmp(u_tokns[0], ListBuiltinCmds[i]))
		{
			switch (i)
			{
				case 0:
					exit(EXIT_SUCCESS);
				case 1:
					chdir(u_tokns[1]);
					return (1);
				case 2:
					openHelp();
					return (1);
				default:
					break;
			}
		}
		i++;
	}

	return (0);
}

/**
 * openHelp - Opens the Holberton Shell help
 *
 * Return: Nothing to returns
 */
void openHelp(void)
{
	puts("\n***WELCOME TO THE SHELL HELP***"
		"\nList of Commands supported:"
		"\n>cd"
		"\n>ls"
		"\n>pwd"
		"\n>cat"
		"\n>exit");
}
