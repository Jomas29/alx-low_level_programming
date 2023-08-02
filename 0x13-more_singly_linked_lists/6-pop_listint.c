#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - Deletes the head node
 * @head: Pointer to the head of the list
 *
 * Return: The head node's data
 */
int pop_listint(listint_t **head)
{
	if (head == NULL || *head == NULL)
		return (0);

	int head_data;
	listint_t *temp;

	temp = *head;
	head_data = temp->n;
	*head = (*head)->next;
	free(temp);

	return (head_data);
}
