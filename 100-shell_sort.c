#include <stdio.h>
#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending,
 * order using the Shell sort algorithm
 * @array: pointer to array to be sorted
 * @size: size of the array to sort
 */
void shell_sort(int *array, size_t size)
{
	size_t k, j, interval = 1;
	int temp;

	if (array == NULL || size < 2)
		return;

	while (interval < size / 3)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		for (k = interval; k < size; k++)
		{
			temp = array[k];
			for (j = k; j >= interval && array[j - interval] > temp; j = j - interval)
				array[j] = array[j - interval];
			array[j] = temp;
		}
		interval = (interval - 1) / 3;
		print_array(array, size);
	}
}
