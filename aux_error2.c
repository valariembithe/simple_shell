#include "shell.h"

/**
 * error_env - generates an error message for env related issues in get_env.
 * @datash: relevant data (counter, arguments)
 * Return: error message
 */
char *error_env(data_shell *datash)
{
	int length;
	char *error;
	char *ver_str;
	char *msg;

	ver_str = aux_itoa(datash->counter);
	msg = ": Unable to add/remove from environment\n";
	length = strlen(datash->av[0]) + strlen(ver_str);
	length += strlen(datash->args[0]) + strlen(msg) + 4;
	error = malloc(sizeof(char) * (length + 1));
	if (error == NULL)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}

	strcpy(error, datash->av[0]);
	strcat(error, ": ");
	strcat(error, ver_str);
	strcat(error, ": ");
	strcat(error, datash->args[0]);
	strcat(error, msg);
	strcat(error, "\0");
	free(ver_str);

	return (error);
}

/**
 * error_path_126 - generate error message for path & permission denied issues.
 * @datash: relevant data (counter, arguments)
 * Return: error message
 */
char *error_path_126(data_shell *datash)
{
	int length;
	char *ver_str;
	char *error;

	ver_str = aux_itoa(datash->counter);
	length = strlen(datash->av[0]) + strlen(ver_str);
	length += strlen(datash->args[0]) + 24;
	error = malloc(sizeof(char) * (length + 1));
	if (error == NULL)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}
	strcpy(error, datash->av[0]);
	strcat(error, ": ");
	strcat(error, ver_str);
	strcat(error, ": ");
	strcat(error, datash->args[0]);
	strcat(error, ": Permission denied\n");
	strcat(error, "\0");
	free(ver_str);
	return (error);
}
