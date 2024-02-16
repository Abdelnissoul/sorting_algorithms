#include "sort.h"

/**
 * swap_elems - function helper to swap between elements
 * @list: Pointer to the head of the list
 * @elem1: Pointer to the first element
 * @elem2: Pointer to the second element
 */
void swap_elems(listint_t **list, listint_t *elem1, listint_t *elem2)
{
    if (elem1 == NULL || elem2 == NULL)
        return;

    if (elem1->prev != NULL)
        elem1->prev->next = elem2;
    else
        *list = elem2;

    if (elem2->next != NULL)
        elem2->next->prev = elem1;

    elem1->next = elem2->next;
    elem2->prev = elem1->prev;
    elem1->prev = elem2;
    elem2->next = elem1;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: Pointer points to the head.
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *count, *ptr, *next;

    count = (*list)->next;

    while (count)
    {
        ptr = count->prev;
        next = count->next;

        while (ptr && ptr->n > count->n)
        {
            swap_elems(list, ptr, count);
            print_list(*list);
            ptr = count->prev;
        }
        count = next;
    }
}
