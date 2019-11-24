#include "shell.h"

/**
  * execBuiltInCommands - ...
  *
  * Return: integer
  */

int execBuiltInCommands(char **u_tokns)
{
        int NoBuiltinCmds = 2, i; 
	char *ListBuiltinCmds[] = {"exit", "cd", "help"};
	for (i = 0; i <= NoBuiltinCmds; i++) { 
		if (strcmp(u_tokns[0], ListBuiltinCmds[i]) == 0)
                {
			break; 
		} 
	} 

	switch (i)
        { 
                case 0:
                        exit(0); 
                case 1: 
                        chdir(u_tokns[1]); 
                        return 1; 
                case 2: 
                        openHelp(); 
                        return 1; 
                default: 
                        break; 
	} 

	return 0; 
}

/**
  * openHelp - ...
  *
  * Return:
  */
void openHelp()
{ 
	puts("\n***WELCOME TO THE SHELL HELP***"
		"\nList of Commands supported:"
		"\n>cd"
		"\n>ls"
		"\n>pwd"
                "\n>cat"
		"\n>exit");

	return; 
} 

