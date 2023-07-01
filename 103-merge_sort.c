#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * Merge - sorts and merges the sub arrays in source
 * @start: starting index (inclusive) for the left sub array
 * @middle: end index (exclusive) for the left sub array and
 * starting index (inclusive) for the right sub array
 * @end: end index (exclusive) for the right sub array
 * @dest: pointer to destination for data
 * @source: pointer to source of data
 *
 * Return: nothing
 */
void Merge(size_t start, size_t middle, size_t end, int *dest, int *source)
{
	size_t k, i, j;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(source + start, middle - start);
	printf("[right]: ");
	print_array(source + middle, end - middle);
	i = start;
	j = middle;
	for (k = start; k < end; k++)
	{
		if (i < middle && (j >= end || source[i] <= source[j]))
		{
			dest[k] = source[i];
			i++;
		}
		else
		{
			dest[k] = source[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(dest + start, end - start);
}

/**
 * Merge_sort_recursive - recursively splits the array and merges,
 * the sorted arrays
 * @start: starting index (inclusive)
 * @end: end index (exclusive)
 * @array: pointer to the array to sort
 * @copy: pointer to a copy of the array
 */
void Merge_sort_recursive(size_t start, size_t end, int *array, int *copy)
{
	size_t middle;

	if (end - start < 2)
		return;
	middle = (start + end) / 2;
	Merge_sort_recursive(start, middle, array, copy);
	Merge_sort_recursive(middle, end, array, copy);
	Merge(start, middle, end, array, copy);
	for (middle = start; middle < end; middle++)
		copy[middle] = array[middle];
}

/**
 * merge_sort - sorts an array of integers in ascending order,
 * using the Merge sort algorithm
 * @array: pointer to array to sort
 * @size: size of the array
 *
 * Return: nothing
 */
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *tmp;

	if (array == NULL || size < 2)
		return;
	tmp = malloc(sizeof(int) * size);
	if (tmp == NULL)
		return;
	for (i = 0; i < size; i++)
		tmp[i] = array[i];
	Merge_sort_recursive(0, size, array, tmp);
	free(tmp);
}
