#include <stdlib.h>
#include <stdio.h>

/**
 * main - Prints all the args without using ac
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	(void) ac;
	while (*av)
	{
		printf("%s\n", *av);
		av++;
	}
	
	return (0);
}
