#include "shell.h"

/**
  * find_command - ...
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
