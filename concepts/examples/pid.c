#include <stdio.h>
#include <unistd.h>

/**
 * main - Gets the current process id and the parent process id
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t my_pid;
	pid_t my_ppid;

    my_pid = getpid();
	my_ppid = getppid();
    printf("Process ID: %u and their Parent Process ID: %u\n", my_pid, my_ppid);

    return (0);
}
