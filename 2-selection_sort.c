#include <stdio.h>
#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending,
 * order using the Selection sort algorithm
 * @array: pointer to the array to sort
 * @size: The size of the array
 * Return: void
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t i, k, min_index;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		for (k = i + 1; k < size; k++)
		{
			if (array[k] < array[min_index])
				min_index = k;
		}
		if (i != min_index)
		{
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;
			print_array(array, size);
		}
	}
}
