#include <unistd.h>
#include <string.h>

int main(void)
{
	char *argv[] = { "/usr/bin/env", NULL };

	exec(argv[0], argv, NULL);

	return (0);
}
