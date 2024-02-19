#include "sort.h"

/**
 * swap_elems - fuunction helps to Swap two integers.
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
 * merging_elems - Sort a bitonic sequence inside an array.
 * @array: An array of integers.
 * @size: The size of the array.
 * @begin: The begining index of the sequence in array to sort.
 * @seq: The size to be sort.
 * @here: The direction to sort in.
 */
void merging_elems(int *array, size_t size, size_t begin, size_t seq,
		char here)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = begin; i < begin + jump; i++)
		{
			if ((here == UP && array[i] > array[i + jump]) ||
			    (here == DOWN && array[i] < array[i + jump]))
				swap_elems(array + i, array + i + jump);
		}
		merging_elems(array, size, begin, jump, here);
		merging_elems(array, size, begin + jump, jump, here);
	}
}

/**
 * ints_into_seq - Convert an array of integers into a bitonic sequence.
 * @array: An array.
 * @size: The size of the array.
 * @begin: The index of a block of the building bitonic sequence.
 * @seq: The size of a block created
 * @here: The direction to sort.
 */
void ints_into_seq(int *array, size_t size, size_t begin, size_t seq,
		char here)
{
	size_t cut;
	char *str = (here == UP) ? "UP" : "DOWN";

	cut = seq / 2;
	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + begin, seq);

		ints_into_seq(array, size, begin, cut, UP);
		ints_into_seq(array, size, begin + cut, cut, DOWN);
		merging_elems(array, size, begin, seq, here);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + begin, seq);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || !size)
		return;

	ints_into_seq(array, size, 0, size, UP);
}
