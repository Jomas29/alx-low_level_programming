#include "lists.h"
#include <stdlib.h>

/**
 * free_list - Frees a list_t list
 * @head: Pointer to the head of the list
 */
void free_list(list_t *head)
{
	list_t *this, *next;

	this = head;
	while (this != NULL)
	{
		next = this->next;
		free(this->str);
		free(this);
		this = next;
	}
}

