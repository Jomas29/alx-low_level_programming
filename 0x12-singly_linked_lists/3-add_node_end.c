#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node_end - Adds a new node at the end of a list
 * @head: Double pointer to the head of the list
 * @str: String to be duplicated
 *
 * Return: The address of the new element
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new, *freed;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}

	new->len = strlen(str);
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
	}
	else
	{
		freed = *head;
		while (freed->next != NULL)
			freed = freed->next;

		freed->next = new;
	}

	return (new);
}

