#include "shell.h"

/**
  * concat_path - Concatenate a path name and a program name
  * @pathname: The path name to concatenate with the program name
  * @progname: The program name to place in the path name
  *
  * Return: The path name concatenated with the program name
  */
char *concat_path(char *pathname, char *progname)
{
	int prog_len = 0, path_len = 0;

	prog_len = _strlen(progname);
	path_len = _strlen(pathname);
	pathname = realloc(pathname, sizeof(char) * (path_len + prog_len + 2));
	if (!pathname)
		return (NULL);

	_strcat(pathname, "/");
	_strcat(pathname, progname);

	return (pathname);
}

/**
  * find - Verify if a command is found in the system
  * @cname: The command name to find in the system
  *
  * Return: The path name of the command found or NULL if failed
  */
char *find(char *cname)
{
	char *env_path = NULL, **p_tokns = NULL;
	int i = 0, path_len = 0, num_del = 0;
	struct stat sb;

	if (cname)
	{
		if (stat(cname, &sb) == 0)
		{
			return (cname);
		}
		else
		{
			env_path = _getenv("PATH");
			num_del = count_delims(env_path, ":") + 1;
			p_tokns = tokenize(env_path, ":", num_del);

			while (p_tokns[i])
			{
				p_tokns[i] = concat_path(p_tokns[i], cname);
				path_len = _strlen(p_tokns[i]);

				if (stat(p_tokns[i], &sb) == 0)
				{
					cname = realloc(cname, sizeof(char) * (path_len + 2));
					if (!cname)
						return (NULL);
					cname = strdup(p_tokns[i]);
					return (cname);
				}

				i++;
			}
		}
	}

	return (NULL);
}

/**
  * exec - Executes a command
  * @cname: The command to execute
  * @opts: The options or flags to the command
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
