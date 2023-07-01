#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order,
 * using the Counting sort algorithm
 * @array: pointer to array to be sorted
 * @size: size of the array to sort
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	size_t b, tmp, total = 0;
	int k, max;
	int *count = NULL, *new = NULL;

	if (array == NULL || size < 2)
		return;
	new = malloc(sizeof(int) * size);
	if (new == NULL)
		return;
	for (b = 0, max = 0; b < size; b++)
	{
		new[b] = array[b];
		if (array[b] > max)
			max = array[b];
	}
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(new);
		return;
	}
	for (k = 0; k <= max; k++)
		count[k] = 0;
	for (b = 0; b < size; b++)
		count[array[b]] += 1;
	for (k = 0; k <= max; k++)
	{
		tmp = count[k];
		count[k] = total;
		total += tmp;
	}
	for (b = 0; b < size; b++)
	{
		array[count[new[b]]] = new[b];
		count[new[b]] += 1;
	}
	print_array(count, max + 1);
	free(count);
	free(new);
}
