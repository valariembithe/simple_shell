#include "main.h"

/**
 * get_len - length of an integer
 * @n: type int integer
 * Return: length of integer
 */
int get_len(int n)
{
	unsigned int i;
	int length = 1;

	if (n < 0)
	{
		length++;
		i = n * -1;
	}
	else
	{
		i = n;
	}
	while (i > 9)
	{
		length++;
		i = i / 10;
	}
	return (length);
}

/**
 * _itoa - converts int to string
 * @n: type int number
 * Return: string
 */
char *_itoa(int n)
{
	unsigned int n1;
	int length = get_len(n);
	char *buffer;

	buffer = malloc(sizeof(char) * (length + 1));

	if (buffer == 0)
		return (NULL);
	*(buffer + length) = '\0';
	if (n < 0)
	{
		n1 = n * -1;
		buffer[0] = '-';
	}
	else
	{
		n1 = n;
	}
	length--;
	do
	{
		*(buffer + length) = (n1 % 10) +  '0';
		n1 = n1 / 10;
		length--;
	}
	while (n1 > 0)
		;
	return (buffer);
}

/**
 * _atoi - converts string to int
 * @s: string
 * Return: integer
 */
int _atoi(char *s)
{
	unsigned int count = 0, size = 0, io = 0, pn = 1, m = 1, i;

	while (*(s + count) != '\0')
	{
		if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
			break;
		if (*(s + count) == '-')
			pn *= -1;
		if ((*(s + count) >= '0') && (*(s + count) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		count++;
	}
	for (i = count - size; i < count; i++)
	{
		io = io + ((*(s + i) - 48) * m);
		m /= 10;
	}
	return (io * pn);
}
