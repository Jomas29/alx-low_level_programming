#include <stdlib.h>
#include "lists.h"

/**
 * get_nodeint_at_index - Returns the nth node
 * @head: Pointer to the head of the list
 * @index: The index of the node
 *
 * Return: The nth node
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int count = 0;
	listint_t *this = head;

	while (this != NULL)
	{
		if (count == index)
			return (this);

		this = this->next;
		count++;
	}

	return (NULL);
}

