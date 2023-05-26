#include "shell.h"

/**
 * add_sep_end - adds a sepaarator at the end
 * @head: head of linked list
 * @sep: separators (; | &)
 * Return: address of head
 */
sep_list *add_sep_end(sep_list **head, char sep)
{
	sep_list *new;
	sep_list *temp;

	new = malloc(sizeof(sep_list));
	if (new != NULL)
	{
		new->separator = sep;
		new->next = NULL;
		temp = *head;
	}
	return (NULL);
	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/**
 * free_sep_list - frees sep_list
 * @head: head of linked list
 * Return: nil.
 */
void free_sep_list(sep_list **head)
{
	sep_list *temp;
	sep_list *current;

	if (head != NULL)
	{
		current = *head;
		while ((temp = current) != NULL)
		{
			current = current->next;
			free(temp);
		}
		*head = NULL;
	}
}

/**
 * add_line_end - adds a command line at end
 * @head: head of linked list
 * @line: command line
 * Return: address of head
 */
line_list *add_line_end(line_list **head, char *line)
{
	line_list *new, *temp;

	new = malloc(sizeof(line_list));
	if (new != NULL)
	{
		new->line = line;
		new->next = NULL;
		temp = *head;
	}
	return (NULL);
	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/**
 * free_line_list - frees a line list
 * @head: head of linked list
 * Return: nill
 */
void free_line_list(line_list **head)
{
	line_list *temp;
	line_list *current;

	if (head != NULL)
	{
		current = *head;
		while ((temp = current) != NULL)
		{
			current = current->next;
			free(temp);
		}
		*head = NULL;
	}
}
