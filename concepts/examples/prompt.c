#include "shell.h"

/**
  * main - Entry point to shell
  *
  * Return: Always zero
  */
int main(int argc, char *argv[], char *envp[])
{
	char *line = NULL, **a_words, **p_words, *path_env;
	int c_words = 0, c_path = 0, k = 0, s = 0, prog_len = 0, path_len = 0, ex = 0;
	size_t size = 0;
	ssize_t len_line = 0;
	pid_t child;
	struct stat sb;

	(void) argc, (void) argv;

	while (envp[s])
	{
		if (!strncmp("PATH", envp[s], 4))
		{
			path_env = envp[s] + 5;
			break;
		}
		s++;
	}

	while (len_line >= 0)
	{
		write(STDOUT_FILENO, "$ ", 2);
		len_line = getline(&line, &size, stdin);
		if (len_line == -1)
			break;
		c_words = count_words(line, " ");
		a_words = splits_string(line, " ", c_words);

		if (stat(a_words[0], &sb) == 0)
		{
			ex = 1;
		}
		else
		{
			c_path = count_words(path_env, ":");
			p_words = splits_string(path_env, ":", c_path);
			prog_len = strlen(a_words[0]);
			s = 0;
			while (p_words[s])
			{
				path_len = strlen(p_words[s]) + 2;
				p_words[s] = realloc(p_words[s], sizeof(char) * (prog_len + path_len));
				if (!p_words[s])
					return (-1);
				strcat(p_words[s], "/");
				strcat(p_words[s], a_words[0]);

				if (stat(p_words[s], &sb) == 0)
				{
					ex = 1;
					a_words[0] = realloc(a_words[0], sizeof(char) * (prog_len + path_len));
					if (!a_words[0])
						return (-1);
					strcpy(a_words[0], p_words[s]);
					break;
				}

				s++;
			}
		}

		if (ex == 1)
		{
			switch (child = fork())
			{
				case -1:
					perror("fork failed");
					exit(-1);
				/* En caso de que el PID sea el hijo */
				case 0:
					perform_task(a_words[0], a_words);
				/* En caso de que el PID sea el padre */
				default:
					parent(child);
			}
		}

		write(STDOUT_FILENO, "\n", 1);

		for (k = c_words; k >= 0; k--)
			free(a_words[k]);

		free(a_words);
	}

	free(line);
	return (0);
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
