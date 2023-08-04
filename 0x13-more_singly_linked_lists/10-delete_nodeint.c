#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node
 * @head: Pointer to the head of the list
 * @index: The index of the node to be deleted
 *
 * Return: 1 if it succeeded
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *this, *freed;
	unsigned int count = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		freed = *head;
		*head = (*head)->next;
		free(freed);
		return (1);
	}

	this = *head;
	while (this != NULL && count < index - 1)
	{
		this = this->next;
		count++;
	}

	if (this == NULL || this->next == NULL)
		return (-1);

	freed = this->next;
	this->next = freed->next;
	free(freed);

	return (1);
}

