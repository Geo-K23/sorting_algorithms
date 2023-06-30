#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order,
 * using the Bubble sort algorithm
 * @array: pointer to the array to be sorted
 * @size: The size of the array
 *
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, k;
	int temp;

	if (array == NULL || size < 2)
		return;

	i = size;
	while (i > 0)
	{
		k = 0;
		for (j = 0; j < i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				k = j + 1;
				print_array(array, size);
			}
		}
		i = k;
	}
}
