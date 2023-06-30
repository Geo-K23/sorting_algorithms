#include <stdio.h>
#include "sort.h"

/**
 * partition - finds the partition for the quicksort using the Lomuto scheme
 * @array: pointer to array to sort
 * @low: lowest index of the partition to sort
 * @high: highest index of the partition to sort
 * @size: size of the array
 * Return: index of the partition
 */
size_t partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t k, j;
	int temp, pivot;

	pivot = array[high];
	k = low - 1;
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			k++;
			if (k != j)
			{
				temp = array[k];
				array[k] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[k + 1])
	{
		temp = array[k + 1];
		array[k + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (k + 1);
}

/**
 * quicksort - sorts a partition of an array of integers
 * @array: pointer to array to sort
 * @low: lowest index of the partition to sort
 * @high: highest index of the partition to sort
 * @size: size of the array
 */
void quicksort(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quicksort(array, low, pivot - 1, size);
		quicksort(array, pivot + 1, high, size);

	}
}

/**
 * quick_sort - sorts an array of integers in ascending order,
 * using the Quick sort algorithm
 * @array: pointer to the array to be sorted
 * @size: The size of the array
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
