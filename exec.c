#include "main.h"
/**
 * @argv: argument vector with list of commands
 */
void execommand(char **argv)
{
	char *command = NULL;
	char *real_command = NULL;
	char *buffer;

	if (argv)
	{
		command = argv[0];
		/* generate path of command */
		real_command = get_location(command);
		buffer = malloc(sizeof(char) * BUFSIZE);
		/* execute command */
		if (execve(real_command, argv, NULL) == -1)
		{
			perror("Error:");
			free(buffer);
		}
	}
}
