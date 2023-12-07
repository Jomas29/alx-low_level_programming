#ifndef LISTS_H
#define LISTS_H

#include <stdlib.h>
#include <stdio.h>

/* Structure for a doubly linked list node */
typedef struct dlistint_s
{
	int n;
	struct dlistint_s *prev;
	struct dlistint_s *next;
} dlistint_t;

/* Function prototype for printing elements of a dlistint_t list */
size_t print_dlistint(const dlistint_t *h);

#endif /* LISTS_H */

