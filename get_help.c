#include "shell.h"

/**
 * get_help - retrieves help messages based on the builtin command
 * @datash: data structure containing arguments and input
 * Return: Returns 0
 */
int get_help(data_shell *datash)
{
	if (datash->args[1] == 0)
		aux_help_general();
	else if (strcmp(datash->args[1], "setenv") == 0)
		aux_help_setenv();
	else if (strcmp(datash->args[1], "env") == 0)
		aux_help_env();
	else if (strcmp(datash->args[1], "unsetenv") == 0)
		aux_help_unsetenv();
	else if (strcmp(datash->args[1], "help") == 0)
		aux_help();
	else if (strcmp(datash->args[1], "exit") == 0)
		aux_help_exit();
	else if (strcmp(datash->args[1], "cd") == 0)
		aux_help_cd();
	else if (strcmp(datash->args[1], "alias") == 0)
		aux_help_alias();
	else
		write(STDERR_FILENO, datash->args[0],
		strlen(datash->args[0]));

	datash->status = 0;
	return (1);
}
