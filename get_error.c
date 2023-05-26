#include "shell.h"

/**
 * get_error - Calls the appropriate error function based on the error code.
 * @datash: Data structure that contains arguments.
 * @eval: Error value.
 * Return: The error value.
 */
int get_error(data_shell *datash, int eval)
{
	char *error = NULL;

	switch (eval)
	{
	case -1:
		error = error_env(datash);
		break;
	case 126:
		error = error_path_126(datash);
		break;
	case 127:
		error = error_not_found(datash);
		break;
	case 2:
		if (_strcmp("exit", datash->args[0]) == 0)
			error = error_exit_shell(datash);
		else if (_strcmp("cd", datash->args[0]) == 0)
			error = error_get_cd(datash);
		break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, strlen(error));
		free(error);
	}

	datash->status = eval;
	return (eval);
}
