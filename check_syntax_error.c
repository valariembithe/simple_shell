#include "shell.h"

/**
 * repeated_char - counts the repetitions.
 *
 * @input: string
 * @i: index loop
 * Return: repetitions
 */
int repeated_char(char *input, int i)
{
	if (*(input - 1) == *input)
		return (repeated_char(input - 1, i + 1));

	return (i);
}

/**
 * error_sep_op - finds syntax errors
 *
 * @input: string input
 * @i: index loop
 * @last: last char
 *
 * Return: index of error else 0 when there are no
 */
int error_sep_op(char *input, int i, char last)
{
	int k;

	k = 0;
	if (*input == '\0')
		return (0);

	if (*input == ' ' || *input == '\t')
		return (error_sep_op(input + 1, k + 1, last));

	if (*input == ';')
		if (last == '|' || last == '&' || last == ';')
			return (k);

	if (*input == '|')
	{
		if (last == ';' || last == '&')
			return (k);

		if (last == '|')
		{
			count = repeated_char(input, 0);
			if (count == 0 || count > 1)
				return (k);
		}
	}

	if (*input == '&')
	{
		if (last == ';' || last == '|')
			return (k);

		if (last == '&')
		{
			count = repeated_char(input, 0);
			if (count == 0 || count > 1)
				return (k);
		}
	}

	return (error_sep_op(input + 1, k + 1, *input));
}

/**
 * first_char - finds index
 * @input: string input
 * @i: index loop
 *
 * Return: 1 if there is an error else 0 in other case.
 */
int first_char(char *input, int *i)
{

	for (*i = 0; input[*i]; *i += 1)
	{
		if (input[*i] == ' ' || input[*i] == '\t')
			continue;

		if (input[*i] == ';' || input[*i] == '|' || input[*i] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * print_syntax_error - prints when a syntax error
 * @datash: data structure
 * @input: string input
 * @i: index of error
 * @bool: control msg error
 *
 * Return: no return
 */
void print_syntax_error(data_shell *datash, char *input, int i, int bool)
{
	char *msg, *msg2, *msg3, *error, *counter;
	int len;

	if (input[i] == ';')
	{
		if (bool == 0)
			msg = (input[i + 1] == ';' ? ";;" : ";");
		else
			msg = (input[i - 1] == ';' ? ";;" : ";");
	}

	if (input[i] == '|')
		msg = (input[i + 1] == '|' ? "||" : "|");

	if (input[i] == '&')
		msg = (input[i + 1] == '&' ? "&&" : "&");

	msg2 = ": Syntax error: \"";
	msg3 = "\" unexpected\n";
	counter = aux_itoa(datash->counter);
	len = _strlen(datash->av[0]) + _strlen(counter);
	len += _strlen(msg) + _strlen(msg2) + _strlen(msg3) + 2;

	error = malloc(sizeof(char) * (len + 1));
	if (error == 0)
	{
		free(counter);
		return;
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, counter);
	_strcat(error, msg2);
	_strcat(error, msg);
	_strcat(error, msg3);
	_strcat(error, "\0");

	write(STDERR_FILENO, error, length);
	free(error);
	free(counter);
}

/**
 * check_syntax_error - find and print a syntax error
 *
 * @datash: data structure
 * @input: string input
 * Return: 1 if there is an error else 0 in other case
 */
int check_syntax_error(data_shell *datash, char *input)
{
	int start = 0;
	int f_char = 0;
	int i = 0;

	f_char = first_char(input, &start);
	if (f_char == -1)
	{
		print_syntax_error(datash, input, start, 0);
		return (1);
	}

	i = error_sep_op(input + start, 0, *(input + start));
	if (i != 0)
	{
		print_syntax_error(datash, input, start + i, 1);
		return (1);
	}

	return (0);
}
