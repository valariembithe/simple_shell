#include "shell.h"

/**
 * is_cmd - checks if a file is an executable command
 * @info: struct info_t
 * @path: path tofile
 *
 * Return: 1 if true,else 0 on failure
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - duplicates characters
 * @pathstr: the PATH string
 * @start: starting i
 * @stop: stopping i
 *
 * Return: pointer new buffer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, n = 0;

	for (n = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[n++] = pathstr[i];
	buf[n] = 0;
	return (buf);
}

/**
 * find_path - find cmd in the PATH
 * @info: struct info_t
 * @pathstr: PATH string
 * @cmd: the cmd to locate
 *
 * Return: full path of cmd if found else NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int j = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[j] || pathstr[j] == ':')
		{
			path = dup_chars(pathstr, curr_pos, j);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[j])
				break;
			curr_pos = j;
		}
		j++;
	}
	return (NULL);
}
