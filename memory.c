#include "main.h"

/**
 * *_realloc - reallocates a memory block
 * @ptr: pointer to memort
 * @old_size: old size
 * @new_size: new size
 * Return: pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *reallo, *clone;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (ptr != NULL)
		clone = ptr;
	else
	{
		return (malloc(new_size));
	}
	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	reallo = malloc(new_size);
	if (reallo == NULL)
		return (0);
	for (i = 0; i < old_size || i < new_size; i++)
	{
		*(reallo + i) = clone[i];
	}
	free(ptr);

	return (reallo);
}
/**
 * _memcpy - copies information between void pointers.
 * @newptr: destination pointer.
 * @ptr: source pointer.
 * @size: size of the new pointer.
 *
 * Return: no return.
 */
void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
	char *_ptr = (char *)ptr;
	char *_newptr = (char *)newptr;
	unsigned int i;

	for (i = 0; i < size; i++)
		_newptr[i] = _ptr[i];
}
