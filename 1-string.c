#include "main.h"
/**
 * _strcpy - copies string to dest in src
 * @dest: destination of string copied
 * @src: source of copied string
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';

	return (dest);
}

/**
 * _strcat - concatenates two strings
 * @dest: destination of copied string
 * @src: source of string
 * Return: dest
 */
char *_strcat(char *dest, const char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcmp - compares two strings
 * @s1: type string compared
 * @s2: type string compared
 * Return: Always 0
 *
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;
	if (s1[i] < s2[i])
		return (-1);
	if (s1[i] > s2[i])
		return (1);
	return (0);
}

/**
 * _strspn - length of a prefix substring
 * @s: inital segment
 * @accept: accepted bytes
 * Return: number of bytes
 *
 */
int _strspn(char *s, char *accept)
{
	int i, j, k;

	for (i = 0; *(s + i) != '\0'; i++)
	{
		k = 1;
		for (j = 0; *(accept + j) != '\0'; j++)
		{
			if (*(s + i) == *(accept + j))
			{
				k = 0;
				break;
			}
		}
		if (k == 1)
		{
			;
		}
	}
	return (i);
}
/**
 * _isdigit - defines if string passed is a number
 *
 * @s: input string
 * Return: 1 if string is a number. 0 in other case.
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
