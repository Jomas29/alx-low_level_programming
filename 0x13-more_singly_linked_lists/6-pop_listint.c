#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - Deletes the head node
 * @head: Pointer to the head of the list
 *
 * Return: The head node's data
 */
int pop_listint(listint_t **head)

	listint_t *freed = *head;
	int header = freed->n;
{
	if (head == NULL || *head == NULL)
		return (0);

	*head = (*head)->next;
	free(freed);

	return (header);
}

