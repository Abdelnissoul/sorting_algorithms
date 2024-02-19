#include "sort.h"

/**
 * swap_elems - function Swaps two integers.
 * @a: The first integer.
 * @b: The second integer.
 */
void swap_elems(int *a, int *b)
{
	int bedel;

	bedel = *a;
	*a = *b;
	*b = bedel;
}

/**
 * heap_sift_sort - change the binary tree into heaps
 * @array: An array of integers.
 * @size: The size of the array
 * @base: the base row of the tree.
 * @root: the root node of tree.
 */
void heap_sift_sort(int *array, size_t size, size_t base, size_t root)
{
	size_t l, r, big;

	l = 2 * root + 1;
	r = 2 * root + 2;
	big = root;

	if (l < base && array[l] > array[big])
		big = l;
	if (r < base && array[r] > array[big])
		big = r;

	if (big != root)
	{
		swap_elems(array + root, array + big);
		print_array(array, size);
		heap_sift_sort(array, size, base, big);
	}
}

/**
 * heap_sort - Sort an array of integers using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * 
 * Description: Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int x;

	if (array == NULL || !size)
		return;

	for (x = (size / 2) - 1; x >= 0; x--)
		heap_sift_sort(array, size, size, x);

	for (x = size - 1; x > 0; x--)
	{
		swap_elems(array, array + x);
		print_array(array, size);
		heap_sift_sort(array, size, x, 0);
	}
}
