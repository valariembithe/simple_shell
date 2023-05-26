#include "shell.h"

/**
 * get_environ - returns  string array copy
 * @info: containing potential arguments. To maintain
 *          constant function
 * Return: Always 0
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv - remove an env var
 * @info: containing potential arguments. To maintain
 *        constant function
 *  Return: 1 on failure, 0 success
 * @var: string enviroon var
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t j = 0;
	char *c;

	if (!node || !var)
		return (0);

	while (node)
	{
		c = starts_with(node->str, var);
		if (c && *c == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), j);
			j = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		j++;
	}
	return (info->env_changed);
}

/**
 * _setenv - Initialize a new env var
 * @info: containing potential arguments.To maintain
 *        constant function
 * @var: string env variable
 * @value: string env variable value
 *  Return: Always 0
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *c;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		c = starts_with(node->str, var);
		if (c && *c == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}

