#include "main.h"
/**
 * @argv: argument vector with list of commands
 */
void execommand(char **argv)
{
	char *cmd = NULL;

	if (argv)
	{
		cmd = argv[0];
		/* execute command */
		if (execve(cmd, argv, NULL) == -1)
		{
			perror("Error");
		}
	}
}
