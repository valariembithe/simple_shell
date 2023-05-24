#include "main.h"
/**
 * strlen - length of string
 * @s: string 
 * Return: length of string
 */
int _strlen(const char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * cmp_chars - compare two chars
 * @str: string 
 * @delim: delimiter
 *
 * Return: 1 if true else 0
 */
int cmp_chars(char str[], const char *delim)
{
	unsigned int i, j ,k;

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
 * _strtok - splits a string with delimiter
 * @str: string
 * @delim: delimiter
 * Return: string splitted
 */
char *_strtok(char str[], const char *delim)
{
	static char *token;
	static char *str_end;
	char *str_start;
	unsigned int i, j; /* is_token_found */

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);

		token = str; /* stores first address */
		i = _strlen(str);
		str_end = &str[i]; /* stores last address */
	}
	str_start = token;
	if (str_start == str_end)
		return (NULL);
	for (j = 0; *token; token++)
	{
		/* find the next token */
		if (token != str_start)
			if (*token && *(token - 1) == '\0')
			       break;
		/* Replace delim with a null terminator */
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
		if (j == 0 && *token) /* str != delim */
			j = 1;
	}
	if (j == 0) /* str == delim */
		return (NULL);
	return (str_start);
				   
}
