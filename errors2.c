#include "main.h"

/**
 * strcat_cd - function that concatenates the message for cd error
 *
 * @datash: data relevant (directory)
 * @msg: message to print
 * @error: output message
 * @ver_string: counter lines
 * Return: error message
 */
char *strcat_cd(datash *datashell, char *msg, char *error, char *ver_string)
{
	char *illegal_flag;

	_strcpy(error, datashell->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_string);
	_strcat(error, ": ");
	_strcat(error, datashell->args[0]);
	_strcat(error, msg);
	if (datashell->args[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = datashell->args[1][1];
		illegal_flag[2] = '\0';
		_strcat(error, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		_strcat(error, datashell->args[1]);
	}
	_strcat(error, "\n");
	_strcat(error, "\0");
	return (error);
}

/**
 * error_get_cd - error message for cd command in get_cd
 * @datash: data relevant (directory)
 * Return: Error message
 */
char *error_get_cd(datash *datashell)
{
	char *error, *ver_string, *msg;
	int len, len_id;

	ver_string = _itoa(datashell->counter);
	if (datashell->args[1][0] == '-')
	{
		msg = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		msg = ": can't cd to ";
		len_id = _strlen(datashell->args[1]);
	}
	len = _strlen(datashell->av[0]) + _strlen(datashell->args[0]);
	len += _strlen(ver_string) + _strlen(msg) + len_id + 5;
	error = malloc(sizeof(char) * (len + 1));

	if (error == 0)
	{
		free(ver_string);
		return (NULL);
	}
	error = strcat_cd(datashell, msg, error, ver_string);
	free(ver_string);
	return (error);
}

/**
 * error_not_found - generic error message for command not found
 * @datash: data relevant (counter, arguments)
 * Return: Error message
 */
char *error_not_found(datash *datashell)
{
	int len;
	char *error;
	char *ver_string;

	ver_string = _itoa(datashell->counter);
	len = _strlen(datashell->av[0]) + _strlen(ver_string);
	len += _strlen(datashell->args[0]) + 16;
	error = malloc(sizeof(char) * (len + 1));
	if (error == 0)
	{
		free(error);
		free(ver_string);
		return (NULL);
	}
	_strcpy(error, datashell->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_string);
	_strcat(error, ": ");
	_strcat(error, datashell->args[0]);
	_strcat(error, ": not found\n");
	_strcat(error, "\0");
	free(ver_string);
	return (error);
}

/**
 * error_exit_shell - error message for exit in get_exit
 * @datash: data relevant
 *
 * Return: Error message
 */
char *error_exit_shell(datash *datashell)
{
	int len;
	char *error;
	char *ver_string;

	ver_string = _itoa(datashell->counter);
	len = _strlen(datashell->av[0]) + _strlen(ver_string);
	len += _strlen(datashell->args[0]) + _strlen(datashell->args[1]) + 23;
	error = malloc(sizeof(char) * (len + 1));
	if (error == 0)
	{
		free(ver_string);
		return (NULL);
	}
	_strcpy(error, datashell->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_string);
	_strcat(error, ": ");
	_strcat(error, datashell->args[0]);
	_strcat(error, ": Illegal number: ");
	_strcat(error, datashell->args[1]);
	_strcat(error, "\n\0");
	free(ver_string);

	return (error);
}
