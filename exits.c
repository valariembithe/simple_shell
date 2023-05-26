#include "shell.h"

/**
 * *_strncpy - copies a string
 * @dest: destination string to be copied
 * @src: source string being copied
 * @n: length
 * Return: the concatenated str
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *str = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (str);
}

/**
 * *_strncat - concatenates two strings
 * @dest: string one
 * @src: string two
 * @n: the number of bytes
 * Return: concatenated str
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *str = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (str);
}

/**
 * *_strchr - locates a character in a string
 * @s: string to be parsed
 * @c: character to look for
 * Return: a pointer to the memory s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
