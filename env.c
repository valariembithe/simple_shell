#include "shell.h"

/**
 * compare_env_name - compares env names
 * @nenv: name of the environment variable
 * @name: the name.
 * Return: 0 if are not equal. otherwise another value
 */
int compare_env_name(const char *nenv, const char *name)
{
	int j;

	for (j = 0; nenv[j] != '='; j++)
	{
		if (nenv[j] != name[j])
		{
			return (0);
		}
	}

	return (j + 1);
}

/**
 * _getenv - get an environment variable.
 * @name: name of  environment variable.
 * @_environ: env variable.
 *
 * Return: value of environment variable if found.
 * otherwise return NULL.
 */
char *_getenv(const char *name, char **_environ)
{
	char *ptr;
	int i, j;

	/* Initialize ptr value */
	ptr = NULL;
	j = 0;
	/* Compare all env variables */
	/* environ is declared in header file */
	for (i = 0; _environ[i]; i++)
	{
		/* If name and env are equal */
		j = compare_env_name(_environ[i], name);
		if (j)
		{
			ptr = _environ[i];
			break;
		}
	}

	return (ptr + j);
}

/**
 * _env - prints the evironment variables
 *
 * @datash: data relevant.
 * Return: 1 on success.
 */
int _env(data_shell *datash)
{
	int i, j;

	for (j = 0; datash->_environ[j]; j++)
	{

		for (i = 0; datash->_environ[j][i]; i++)
			break;

		write(STDOUT_FILENO, datash->_environ[j], i);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;

	return (1);
}
