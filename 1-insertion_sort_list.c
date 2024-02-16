#include "sort.h"

/**
 * swap_elems - function helps to swap between elements
 * @h: A pointer to the head of the doubly-linked list.
 * @elem1: A pointer to the first element.
 * @elem2: ptr The second element to swap.
 */
void swap_elems(listint_t **h, listint_t **elem1, listint_t *elem2)
{
	(*elem1)->next = elem2->next;
	if (elem2->next != NULL)
		elem2->next->prev = *elem1;
	elem2->prev = (*elem1)->prev;
	elem2->next = *elem1;
	if ((*elem1)->prev != NULL)
		(*elem1)->prev->next = elem2;
	else
		*h = elem2;
	(*elem1)->prev = elem2;
	*elem1 = elem2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: Pointer points to the head.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *hseb, *bedel, *cpt;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (hseb = (*list)->next; hseb != NULL; hseb = cpt)
	{
		cpt = hseb->next;
		bedel = hseb->prev;
		while (bedel != NULL && hseb->n < bedel->n)
		{
			swap_elems(list, &bedel, hseb);
			print_list((const listint_t *)*list);
		}
	}
}
