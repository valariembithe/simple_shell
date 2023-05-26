#include "shell.h"

/**
 * _memcpy - copies data
 * @newptr: destination to be copied to
 * @ptr: source to be copied from
 * @size: size of the newptr
 *
 * Return: nil
 */
void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
	char *_ptr = (char *)ptr;
	char *new_ptr = (char *)newptr;
	unsigned int i;

	for (i = 0; i < size; i++)
		new_ptr[i] = _ptr[i];
}

/**
 * _realloc - reallocates a memory
 * @ptr: pointer to previously allocated memory
 * @old_size: size, in bytes of ptr
 * @new_size: new size, in bytes of the new memory
 *
 * Return: ptr
 * if new_size == old_size, returns ptr without changes.
 * if memory allocation fails, returns NULL.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *newptr;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(new_size);
	if (newptr == NULL)
		return (NULL);

	if (new_size < old_size)
		_memcpy(newptr, ptr, new_size);
	else
		_memcpy(newptr, ptr, old_size);

	free(ptr);
	return (newptr);
}

/**
 * _reallocdp - reallocates a memory of  double pointer ptr
 * @ptr: double pointer
 * @old_size: size, in bytes of the allocated memory of ptr.
 * @new_size: new size, in bytes of the new memory
 *
 * Return: ptr.
 */
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **newptr;
	unsigned int j;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(sizeof(char *) * new_size);
	if (newptr == NULL)
		return (NULL);

	for (j = 0; j < old_size; j++)
		newptr[j] = ptr[j];

	free(ptr);

	return (newptr);
}
