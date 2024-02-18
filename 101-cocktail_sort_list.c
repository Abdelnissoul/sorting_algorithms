#include "sort.h"

/**
 * swap_elems - Swap a node in a doubly-linked list
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_elems(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *cpt = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = cpt;
	else
		*list = cpt;
	cpt->prev = (*shaker)->prev;
	(*shaker)->next = cpt->next;
	if (cpt->next != NULL)
		cpt->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = cpt;
	cpt->next = *shaker;
	*shaker = cpt;
}

/**
 * swap_elems_rear - Swap a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_elems_rear(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *cpt = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = cpt;
	else
		*tail = cpt;
	cpt->next = (*shaker)->next;
	(*shaker)->prev = cpt->prev;
	if (cpt->prev != NULL)
		cpt->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = cpt;
	cpt->prev = *shaker;
	*shaker = cpt;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool shaken_not_stirred = false;

	if (!list || *list == NULL || (*list)->next == NULL)
		return;

	tail = *list;
	while (tail->next != NULL)
		tail = tail->next;

	while (!shaken_not_stirred)
	{
		shaken_not_stirred = true;
		shaker = *list;
		while (shaker != tail)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_elems(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
			else
				shaker = shaker->next;
		}
		shaker = tail;
		while (shaker != *list)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_elems_rear(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
			shaker = shaker->prev;
		}
	}
}
