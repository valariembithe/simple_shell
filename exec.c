#include "shell.h"

/**
 * is_cdir - checks ":" is in current directory.
 * @path: type char pointer to path
 * @i: type int pointer to index
 * Return: 1 if the path is searchable in cd, 0 otherwise.
 */
int is_cdir(char *path, int *i)
{
	if (path[*i] == ':')
		return (1);

	while (path[*i] != ':' && path[*i])
	{
		*i += 1;
	}

	if (path[*i])
		*i += 1;

	return (0);
}

/**
 * _which - locates a command
 *
 * @cmd: command
 * @_environ: environment variable
 * Return: location of command.
 */
char *_which(char *cmd, char **_environ)
{
	char *path, *pointer_path, *token_path, *directory;
	int len_directory, len_cmd, i;
	struct stat st;

	path = _getenv("PATH", _environ);
	if (path)
	{
		pointer_path = _strdup(path);
		len_cmd = _strlen(cmd);
		token_path = _strtok(pointer_path, ":");
		i = 0;
		while (token_path != NULL)
		{
			if (is_cdir(path, &i))
				if (stat(cmd, &st) == 0)
					return (cmd);
			len_directory = _strlen(token_path);
			directory = malloc(len_directory + len_cmd + 2);
			_strcpy(directory, token_path);
			_strcat(directory, "/");
			_strcat(directory, cmd);
			_strcat(directory, "\0");
			if (stat(directory, &st) == 0)
			{
				free(pointer_path);
				return (directory);
			}
			free(directory);
			token_path = _strtok(NULL, ":");
		}
		free(pointer_path);
		if (stat(cmd, &st) == 0)
			return (cmd);
		return (NULL);
	}
	if (cmd[0] == '/')
		if (stat(cmd, &st) == 0)
			return (cmd);
	return (NULL);
}

/**
 * is_executable - determines if an executable
 *
 * @datash: data structure
 * Return: 0 if is not an executable, otherwise other number
 */
int is_executable(data_shell *datash)
{
	struct stat st;
	int j;
	char *input;

	input = datash->args[0];
	for (j = 0; input[j]; j++)
	{
		if (input[j] == '.')
		{
			if (input[j + 1] == '.')
				return (0);
			if (input[j + 1] == '/')
				continue;
			else
				break;
		}
		else if (input[j] == '/' && j != 0)
		{
			if (input[j + 1] == '.')
				continue;
			j++;
			break;
		}
		else
			break;
	}
	if (j == 0)
		return (0);

	if (stat(input + j, &st) == 0)
	{
		return (j);
	}
	get_error(datash, 127);
	return (-1);
}

/**
 * check_error_cmd - verifies if user has permission
 * @dir: destination directory
 * @datash: data structure
 *
 * Return: 1 if there is an error, 0 if not
 */
int check_error_cmd(char *directory, data_shell *datash)
{
	if (directory == NULL)
	{
		get_error(datash, 127);
		return (1);
	}

	if (_strcmp(datash->args[0], directory) != 0)
	{
		if (access(directory, X_OK) == -1)
		{
			get_error(datash, 126);
			free(directory);
			return (1);
		}
		free(directory);
	}
	else
	{
		if (access(datash->args[0], X_OK) == -1)
		{
			get_error(datash, 126);
			return (1);
		}
	}

	return (0);
}

/**
 * cmd_exec - executes command lines
 * @datash: data relevant (args and input)
 *
 * Return: 1 on success.
 */
int cmd_exec(data_shell *datash)
{
	pid_t pd;
	pid_t wpd;
	int state;
	int exec;
	char *directory;
	(void) wpd;

	exec = is_executable(datash);
	if (exec == -1)
		return (1);
	if (exec == 0)
	{
		directory = _which(datash->args[0], datash->_environ);
		if (check_error_cmd(directory, datash) == 1)
			return (1);
	}

	pd = fork();
	if (pd == 0)
	{
		if (exec == 0)
			directory = _which(datash->args[0], datash->_environ);
		else
			directory = datash->args[0];
		execve(directory + exec, datash->args, datash->_environ);
	}
	else if (pd < 0)
	{
		perror(datash->av[0]);
		return (1);
	}
	else
	{
		do {
			wpd = waitpid(pd, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}

	datash->status = state / 256;
	return (1);
}
