#include <stdlib.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position
 * @head: Pointer to the head of the list
 * @idx: The index where the new node should be added
 * @n: The value to store in the new node
 *
 * Return: The address of the new node
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new, *this = *head;
	unsigned int count = 0;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	while (this != NULL)
	{
		if (count == idx - 1)
		{
			new->next = this->next;
			this->next = new;
			return (new);
		}

		this = this->next;
		count++;
	}

	free(new);
	return (NULL);
}

