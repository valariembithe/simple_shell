#include "main.h"
/**
 * assign_line - assigns line variable to getline
 * @lineptr: buffer storing input string
 * @buffer: string called in line
 * @n: size of line
 * @j: size of buffer
 */
void assign_line(char **lineptr, size_t *n, char *buffer, size_t j)
{
	if (*lineptr == NULL)
	{
		if (j > BUFSIZE)
			*n = j;
		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else if (*n < j)
	{
		if (j > BUFSIZE)
			*n = j;
		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else
	{
		strcpy(*lineptr, buffer);
		free(buffer);
	}
}
/**
 * get_line - reads input from prompt
 * @lineptr: buffer that stores input
 * @n: size of lineptr
 * @stream: stream to read from
 * Return: number of bytes
 */
ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
	int i;
	char *buffer;
	char t = 'z';
	static ssize_t input;
	ssize_t retval;

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;
	/* allocate size to buffer */
	buffer = malloc(sizeof(char) * BUFSIZE);
	if(buffer == 0)
		return (-1);
	/* while token delim is not a new line character */
	while (t != '\n')
	{
		/* read from input of file */
		i = read(STDIN_FILENO, &t, 1);
		if (i == -1 || (i == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (i == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= BUFSIZE)
			buffer = _realloc(buffer, input, input + 1);
		buffer[input] = t;
		input++;
	}
	buffer[input] = '\0';
	assign_line(lineptr, n, buffer, input);
	retval = input;
	if (i != 0)
		input = 0;
	return (retval);
}

