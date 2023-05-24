#include "main.h"

/**
 * error_path_126 - error message for path and persmission denied
 * @datashell: data relavant i.e args, counter
 * Return: error string
 */
char *error_path_126(datash *datashell)
{
	int len;
	char *ver_string;
	char *error;

	ver_string = _itoa(datashell->counter);
	len = _strlen(datashell->av[0]) + _strlen(ver_string);
	len += _strlen(datashell->args[0]) + 24;
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
	_strcat(error, ": Permission denied\n");
	_strcat(error, "\0");
	free(ver_string);
	return (error);
}
/**
 * error_env - error message in get_env
 * @datashell: data relevant
 * Return: error message
 */
char *error_env(datash *datashell)
{
	int len;
	char *ver_string;
	char *error;
	char *msg;

	ver_string = _itoa(datashell->counter);
	msg = ": Unable to add/remove from environment\n";
	len = _strlen(datashell->av[0]) + _strlen(ver_string);
	len += _strlen(datashell->args[0]) + _strlen(msg) + 4;
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
	_strcat(error, msg);
	_strcat(error, "\0");
	free(ver_string);
	return (error);
}
