#include "sort.h"

/**
 * merge_subarray - Merges two subarrays.
 * @subarray: A subarray of an array.
 * @ptr: A pointer to store the subarray.
 * @start: The start index.
 * @middle: The middle index.
 * @end: The end index.
 */
void merge_subarray(int *subarray, int *ptr, size_t start, size_t middle,
                    size_t end)
{
	size_t el1, el2, ptr_index = 0;
	size_t i, j;

	el1 = start;
	el2 = middle;

	printf("Merging...\n[left]: ");
	print_array(subarray + start, middle - start);

	printf("[right]: ");
	print_array(subarray + middle, end - middle);

	while (el1 < middle && el2 < end)
	{
		if (subarray[el1] < subarray[el2])
		{
			ptr[ptr_index++] = subarray[el1++];
		}
		 else 
		{
			ptr[ptr_index++] = subarray[el2++];
		}
	}

	while (el1 < middle)
	{
		ptr[ptr_index++] = subarray[el1++];
	}

	while (el2 < end)
	{
		ptr[ptr_index++] = subarray[el2++];
	}

	for (i = start, j = 0; i < end; i++, j++)
	{
		subarray[i] = ptr[j];
	}

	printf("[Done]: ");
	print_array(subarray + start, end - start);
}

/**
 * merge_recurs - recursion merge sort algorithm
 * @subarray: subarray of an array.
 * @ptr: A pointer to store the result.
 * @start: first index of the subarray.
 * @end: last index of the subarray.
 */
void merge_recurs(int *subarray, int *ptr, size_t start, size_t end)
{
	if (end - start > 1)
	{
		size_t middle = start + (end - start) / 2;
		merge_recurs(subarray, ptr, start, middle);
		merge_recurs(subarray, ptr, middle, end);
		merge_subarray(subarray, ptr, start, middle, end);
	}
}

/**
 * merge_sort - Sort an array of integers using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *ptr;

	if (array == NULL || !size)
		return;

	ptr = malloc(sizeof(int) * size);
	if (!ptr)
		return;

	merge_recurs(array, ptr, 0, size);

	free(ptr);
}
