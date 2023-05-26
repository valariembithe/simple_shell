#include "shell.h"

/**
 * _strdup - duplicates string s
 * @s: string
 * Return: duplicated string
 */
char *_strdup(const char *s)
{
	char *dup;
	size_t length;

	length = _strlen(s);
	dup = malloc(sizeof(char) * (length + 1));
	if (dup == NULL)
		return (NULL);
	_memcpy(dup, s, length + 1);
	return (dup);
}

/**
 * _strlen - Returns lenght of string.
 * @s: string
 * Return: Always 0.
 */
int _strlen(const char *s)
{
	int length = 0;

	while (s[length] != 0)
	{
		length++;
	}
	return (length);
}

/**
 * cmp_chars - compare chars in strings
 * @str: string.
 * @delim: delimiter.
 *
 * Return: 1 if are equals, else 0
 */
int cmp_chars(char str[], const char *delim)
{
	unsigned int i, j, k;

	for (i = 0, k = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);
	return (0);
}

/**
 * _strtok - splits a string
 * @str: string.
 * @delim: delimiter
 *
 * Return: string splited.
 */
char *_strtok(char str[], const char *delim)
{
	static char *token, *str_end;
	char *str_start;
	unsigned int i, bool;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		token = str; /*Stores first address*/
		i = _strlen(str);
		str_end = &str[i]; /*Stores last address*/
	}
	str_start = token;
	if (str_start == str_end) /*Reaches the end*/
		return (NULL);

	for (bool = 0; *token; token++)
	{
		/*Breaking loop after finding the next token*/
		if (token != str_start)
			if (*token && *(token - 1) == '\0')
				break;
		/*Replacing delimiter for null terminator*/
		for (i = 0; delim[i]; i++)
		{
			if (*token == delim[i])
			{
				*token = '\0';
				if (token == str_start)
					str_start++;
				break;
			}
		}
		if (bool == 0 && *token) /*string != Delimiter*/
			bool = 1;
	}
	if (bool == 0) /*string == delimiter*/
		return (NULL);
	return (str_start);
}

/**
 * _isdigit - if string passed is a number
 *
 * @s: string input
 * Return: 1 if string is a number, otherwise 0
 */
int _isdigit(const char *s)
{
	unsigned int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
	}
	return (1);
}
