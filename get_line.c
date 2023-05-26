#include "shell.h"

/**
 * input_buf - buffers commands
 * @info: struct containing args
 * @buf: buffer
 * @len: address of len var
 *
 * Return: bytes available
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t b = 0;
	size_t len_p = 0;

	if (!*len) /* if null in the buffer, fill buffer */
	{
		/*bfree((void **)info->cmd_buf);*/
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		b = getline(buf, &len_p, stdin);
#else
		b = _getline(info, buf, &len_p);
#endif
		if (b > 0)
		{
			if ((*buf)[b - 1] == '\n')
			{
				(*buf)[b - 1] = '\0'; /* remove trailing space */
				b--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			/* if (_strchr(*buf, ';')) is this a command */
			{
				*len = b;
				info->cmd_buf = buf;
			}
		}
	}
	return (b);
}

/**
 * get_input - gets a line
 * @info: struct of args
 *
 * Return: bytes
 */
ssize_t get_input(info_t *info)
{
	static char *buf; /* the ';' command chain */
	static size_t i, j, len;
	ssize_t b = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	b = input_buf(info, &buf, &len);
	if (b == -1) /* EOF */
		return (-1);
	if (len) /* we have commands left in the chain */
	{
		j = i; /* init new loop to current buf position */
		p = buf + i; /* get pointer */

		check_chain(info, buf, &j, i, len);
		while (j < len) /* loop to semicolon or end */
		{
			if (is_chain(info, buf, &j))
				break;
			j++;
		}

		i = j + 1;
		if (i >= len) /* has it reached end of buffer */
		{
			i = len = 0;
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p;
		return (_strlen(p)); /* return length of command */
	}

	*buf_p = buf; /* else, pass buffer from _getline() */
	return (b); /* length of buffer */
}

/**
 * read_buf - reads a buffer
 * @info: struct of args
 * @buf: buffer
 * @i: size
 *
 * Return: b
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t b = 0;

	if (*i)
		return (0);
	b = read(info->readfd, buf, READ_BUF_SIZE);
	if (b >= 0)
		*i = b;
	return (b);
}

/**
 * _getline - gets the next line of input
 * @info: struct of args
 * @ptr: address of pointer to buffer
 * @length: size of preallocated ptr buffer else, NULL
 *
 * Return: s
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	size_t j;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (i == len)
		i = len = 0;

	r = read_buf(info, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buf + i, '\n');
	j = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, s, s ? s + j : j + 1);
	if (!new_p) /* Malloc error */
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buf + i, j - i);
	else
		_strncpy(new_p, buf + i, j - i + 1);

	s += j - i;
	i = j;
	p = new_p;

	if (length)
		*length = s;
	*ptr = p;
	return (s);
}

/**
 * sigintHandler - blocks CTRL - C
 * @sig_num: signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
