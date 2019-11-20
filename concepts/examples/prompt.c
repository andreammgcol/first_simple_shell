#include "shell.h"

/**
  * main - Entry point to shell
  *
  * Return: Always zero
  */
int main(void)
{
	char *line = NULL, **a_words;
	int c_words = 0, k = 0;
	size_t size = 0;
	ssize_t len_line = 0;
	pid_t child;

	while (len_line >= 0)
	{
		write(STDOUT_FILENO, "$ ", 2);
		len_line = getline(&line, &size, stdin);
		if (len_line == -1)
			break;
		c_words = count_words(line, " ");
		a_words = splits_string(line, " ", c_words);

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

		write(STDOUT_FILENO, line, len_line);
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
	printf("PAPA (%lu) - Mi hijo es (%lu)\n", (long) getpid(), (long) child);

	wait(NULL);

	printf("PAPA (%lu) - Mi hijo (%lu) ya termino\n", (long) getpid(), (long) child);
	printf("PAPA (%lu) - Ya me voy a salir\n", (long) getpid());
}

/**
  * child - ...
  * @command: The command to performs
  * @options: The options to the command
  *
  * Return: ...
  */
void perform_task(char *command, char **options)
{
	printf("HIJO (%lu) - Mi papa es (%lu)\n", (long) getpid(), (long) getppid());
	printf("HIJO (%lu) - Ya me voy a salir\n", (long) getpid());
	
	execve(command, options, NULL);
	perror("Error:");
}
