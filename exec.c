#include "shell.h"

/**
  * exec - Executes a command
  * @cname: The command to execute
  * @options: The options or flags to the command
  *
  * Return: A integer status value
  */
int exec(char *cname, char **opts)
{
	pid_t child;
	int status;

	switch (child = fork())
	{
		case -1:
			perror("fork failed");
			return (-1);
		case 0:
			execve(cname, opts, NULL);
		default:
			do {
				waitpid(child, &status, WUNTRACED);
			} while (WIFEXITED(status) == 0 && WIFSIGNALED(status) == 0);
	}

	return (0);
}
