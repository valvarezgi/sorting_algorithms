#include "sort.h"
/**
 * insertion_sort_list - Function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: Doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *to_insert;

	if (list == NULL)
		return;

	to_insert = (*list)->next;
	while (to_insert)
	{
		while (to_insert->prev && to_insert->n < to_insert->prev->n)
		{
			to_insert->prev->next = to_insert->next;
			if (to_insert->next)
				to_insert->next->prev = to_insert->prev;
			to_insert->next = to_insert->prev;
			to_insert->prev = to_insert->prev->prev;
			to_insert->next->prev = to_insert;
			if (!to_insert->prev)
				*list = to_insert;
			else
				to_insert->prev->next = to_insert;
			print_list(*list);
		}
		to_insert = to_insert->next;
	}
}
