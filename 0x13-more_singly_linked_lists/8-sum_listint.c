#include "lists.h"

/**
 * sum_listint - Returns the sum of all the data
 * @head: Pointer to the head of the list
 *
 * Return: The sum of all the data (n)
 */
int sum_listint(listint_t *head)
{
	int add = 0;
	listint_t *this = head;

	while (this != NULL)
	{
		add += this->n;
		this = this->next;
	}

	return (add);
}

