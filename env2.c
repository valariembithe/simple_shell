#include "shell.h"

/**
 * copy_info - copies info to
 * a new env or alias
 * @name: name (env or alias)
 * @value: value (env or alias).
 *
 * Return: new env or alias.
 */
char *copy_info(char *name, char *value)
{
	char *dup;
	int len_name, len_val, length;

	len_name = _strlen(name);
	len_val = _strlen(value);
	length = len_name + len_value + 2;
	dup = malloc(sizeof(char) * (length));
	_strcpy(new, name);
	_strcat(new, "=");
	_strcat(new, value);
	_strcat(new, "\0");

	return (dup);
}

/**
 * set_env - sets an environment variable
 * @name: name of environment variable
 * @value: value of environment variable
 * @datash: data structure (environ)
 * Return: no return
 */
void set_env(char *name, char *value, data_shell *datash)
{
	int j;
	char *variable_env, *name_env;

	for (j = 0; datash->_environ[j]; j++)
	{
		variable_env = _strdup(datash->_environ[j]);
		name_env = _strtok(variable_env, "=");
		if (_strcmp(name_env, name) == 0)
		{
			free(datash->_environ[j]);
			datash->_environ[j] = copy_info(name_env, value);
			free(variable_env);
			return;
		}
		free(variable_env);
	}

	datash->_environ = _reallocdp(datash->_environ, i, sizeof(char *) * (j + 2));
	datash->_environ[j] = copy_info(name, value);
	datash->_environ[j + 1] = NULL;
}

/**
 * _setenv - compares env variables
 * with the name passed
 * @datash: data relevant (env value and env name)
 *
 * Return: 1 on success.
 */
int _setenv(data_shell *datash)
{

	if (datash->args[1] == NULL || datash->args[2] == NULL)
	{
		get_error(datash, -1);
		return (1);
	}

	set_env(datash->args[1], datash->args[2], datash);

	return (1);
}

/**
 * _unsetenv - deletes a environment variable
 *
 * @datash: data relevant (env name)
 *
 * Return: 1 on success.
 */
int _unsetenv(data_shell *datash)
{
	char **realloc_environ;
	char *variable_env, *name_env;
	int i, j, k;

	if (datash->args[1] == NULL)
	{
		get_error(datash, -1);
		return (1);
	}
	k = -1;
	for (i = 0; datash->_environ[i]; i++)
	{
		variable_env = _strdup(datash->_environ[i]);
		name_env = _strtok(variable_env, "=");
		if (_strcmp(name_env, datash->args[1]) == 0)
		{
			k = i;
		}
		free(variable_env);
	}
	if (k == -1)
	{
		get_error(datash, -1);
		return (1);
	}
	realloc_environ = malloc(sizeof(char *) * (i));
	for (i = j = 0; datash->_environ[i]; i++)
	{
		if (i != k)
		{
			realloc_environ[j] = datash->_environ[i];
			j++;
		}
	}
	realloc_environ[j] = NULL;
	free(datash->_environ[k]);
	free(datash->_environ);
	datash->_environ = realloc_environ;
	return (1);
}
