#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

/**
  * main - Entry point to the Shell
  *
  * Return: Always zero.
  */
int main(void)
{
	char *line = NULL, **u_tokns = NULL;
	int i = 0;
	size_t line_size = 0;
	ssize_t line_len = 0;
	pid_t child;

	while (line_len >= 0)
	{
		write(STDOUT_FILENO, "$ ", 2);
		line_len = getline(&line, &line_size, stdin);
		if (line_len == -1)
			break;

		u_tokns = tokenize(line, " ", count_input(line, ' '));

		if ((u_tokns[0] = find_command(u_tokns[0])))
		{
			switch (child = fork())
			{
				case -1:
					perror("fork failed");
					exit(-1);
				case 0:
					perform_task(u_tokns[0], u_tokns);
				default:
					parent(child);
			}
		}

		write(STDOUT_FILENO, "\n", 1);

		for (i = count_input(line, ' '); i >= 0; i--)
			free(u_tokns[i]);

		free(u_tokns);
	}

	free(line);
	return (0);
}

/**
  * verify_command - ...
  * @pathname: ...
  *
  * Return: integer
  */
char *find_command(char *pathname)
{
	char *env_path = NULL, **p_tokns = NULL;
	int i = 0, path_len = 0, num_del = 0;
	struct stat sb;

	if (stat(pathname, &sb) == 0)
	{
		return (pathname);
	}
	else
	{
		env_path = _getenv("PATH");
		num_del = count_delims(env_path, ":") + 1;
		p_tokns = tokenize(env_path, ":", num_del);

		while (p_tokns[i])
		{
			p_tokns[i] = concat_path(p_tokns[i], pathname);
			path_len = _strlen(p_tokns[i]);

			if (stat(p_tokns[i], &sb) == 0)
			{
				pathname = realloc(pathname, sizeof(char) * (path_len + 2));
				if (!pathname)
					return (NULL);
				pathname = strdup(p_tokns[i]);
				return (pathname);
			}

			i++;
		}
	}

	return (NULL);
}

/**
  * parent - ...
  * @child: ...
  *
  * Return: ...
  */
void parent(pid_t child)
{
	int status;

	do {
		waitpid(child, &status, WUNTRACED);
	} while (WIFEXITED(status) == 0 && WIFSIGNALED(status) == 0);
}

/**
  * perform_task - ...
  * @command: The command to performs
  * @options: The options to the command
  *
  * Return: ...
  */
void perform_task(char *command, char **options)
{
	execve(command, options, NULL);
	perror("Error:");
}
