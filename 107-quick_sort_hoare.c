#include "sort.h"

/**
 * swap_elems - function helps swaping two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_elems(int *a, int *b)
{
	int bedel;

	bedel = *a;
	*a = *b;
	*b = bedel;
}

/**
 * hoare_div - Order a subset according to the hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @l: The starting left index
 * @r: the ending right index
 * Return: The final index.
 */
int hoare_div(int *array, size_t size, int l, int r)
{
	int pivot, fo9, taht;

	pivot = array[r];
	for (fo9 = l - 1, taht = r + 1; fo9 < taht;)
	{
		do {
			fo9++;
		} while (array[fo9] < pivot);
		do {
			taht--;
		} while (array[taht] > pivot);

		if (fo9 < taht)
		{
			swap_elems(array + fo9, array + taht);
			print_array(array, size);
		}
	}

	return (fo9);
}

/**
 * hoare_sort - the quicksort algorithm through recursion.
 * @array: An array of integers.
 * @size: The size of the array.
 * @l: The starting index of the array
 * @r: The ending index of the array
 */
void hoare_sort(int *array, size_t size, int l, int r)
{
	int div;

	if (r - l > 0)
	{
		div = hoare_div(array, size, l, r);
		hoare_sort(array, size, l, div - 1);
		hoare_sort(array, size, div, r);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || !size)
		return;

	hoare_sort(array, size, 0, size - 1);
}
