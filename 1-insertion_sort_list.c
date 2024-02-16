#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: Pointer points to the head.
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *count = (*list)->next;
	listint_t *ptr, *next;

	while (count)
	{
		ptr = count->prev;
		next = count->next;

		while (ptr && ptr->n > count->n)
		{
			ptr->next = count->next;
			if (count->next != NULL)
				count->next->prev = ptr;

			count->next = ptr;
			count->prev = ptr->prev;

			if (ptr->prev != NULL)
				ptr->prev->next = count;
			ptr->prev = count;

			if (count->prev == NULL)
				*list = count;

			print_list(*list);

			ptr = count->prev;
		}
		count = next;
	}
}
