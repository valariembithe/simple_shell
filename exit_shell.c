#include "main.h"

/**
 * _exit - exits shell
 * @datash: data relevant (args and status)
 * Return: 0 on success
 */
int exit_shell(datash *datashell)
{
	int str_len;
	int is_digit;
	int big_no;
	unsigned int cstatus;

	if (datashell->args[1] != NULL)
	{
		cstatus = _atoi(datashell->args[1]);
		is_digit = _isdigit(datashell->args[1]);
		str_len = _strlen(datashell->args[1]);
		big_no = cstatus > (unsigned int)INT_MAX;
		if (!is_digit || str_len > 10 || big_no)
		{
			get_error(datashell, 2);
			datashell->status = 2;
			return (1);
		}
		datashell->status = (cstatus % 256);
	}
	return (0);
}
