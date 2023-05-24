#include "main.h"

/**
 * get_error - error as from builtin
 * @datashell: data that contains arguments
 * @eval: error value
 * Return: 0 on success
 */
int get_error(datash *datashell, int eval)
{
	char *error;

	switch (eval)
	{
		case -1:
			error = error_env(datashell);
			break;
		case 126:
			error = error_path_126(datashell);
			break;
		case 127:
			error = error_not_found(datashell);
			break;
		case 2:
			if (_strcmp("exit", datashell->args[0]) == 0)
				error = error_exit_shell(datashell);
			else if (_strcmp("cd", datashell->args[0]) == 0)
				error = error_get_cd(datashell);
			break;
	}
	if (error)
	{
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
	}
	datashell->status = eval;
	return (eval);
}
