#include "shell.h"

/**
 * _strcat - concatenate two strings
 * @dest: destination of the copied string
 * @src: source of string to be copied
 * Return: the destination
 */
char *_strcat(char *dest, const char *src)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)
		break;

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}
/**
 * *_strcpy - Copies the string
 * @dest: the destination of copied string
 * @src: the source of string to be copied
 * Return: the destination
 */
char *_strcpy(char *dest, char *src)
{

	size_t i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}
/**
 * _strcmp - compares two strings, s1 and s2
 * @s1: string one
 * @s2: string 2
 *
 * Return: Always 0.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		break;

	if (s1[i] < s2[i])
		return (-1);
	if (s1[i] > s2[i])
		return (1);
	return (0);
}
/**
 * _strchr - locates a character in a s
 * @s: string to iterate
 * @c: character located
 * Return: a pointer to first occurrence of  c in s
 */
char *_strchr(char *s, char c)
{
	unsigned int j;

	for (j = 0; *(s + j) != '\0'; j++)
		if (*(s + j) == c)
			return (s + j);
	if (*(s + j) == c)
		return (s + j);
	return ('\0');
}
/**
 * _strspn - length of prefix substring
 * @s: initial
 * @accept: accepted bytes in s
 * Return: the number of bytes.
 */
int _strspn(char *s, char *accept)
{
	int i, j, bool;

	for (j = 0; *(s + j) != '\0'; j++)
	{
		bool = 1;
		for (i = 0; *(accept + i) != '\0'; i++)
		{
			if (*(s + j) == *(accept + i))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (j);
}
