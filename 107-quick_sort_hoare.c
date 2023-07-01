#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * partition - finds the partition for the quicksort using the Hoare scheme
 * @array: pointer to array to sort
 * @low: lowest index of the partition to sort
 * @high: highest index of the partition to sort
 * @size: size of the array
 * Return: index of the partition
 */
size_t partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot, temp;

	pivot = array[high];
	while (low <= high)
	{
		while (array[low] < pivot)
			low++;
		while (array[high] > pivot)
			high--;
		if (low <= high)
		{
			if (low != high)
			{
				temp = array[low];
				array[low] = array[high];
				array[high] = temp;
				print_array(array, size);
			}
			low++;
			high--;
		}
	}
	return (high);
}

/**
 * quickSort - recursively sorts a partition of an array of integers
 * @array: pointer to array to be sorted
 * @low: lowest index of the partition to sort
 * @high: highest index of the partition to sort
 * @size: size of the array
 * Return: nothing
 */
void quickSort(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quickSort(array, low, pivot, size);
		quickSort(array, pivot + 1, high, size);

	}
}

/**
 * quick_sort_hoare - sorts an array of integers in ascending order,
 * using the Quick sort algorithm
 * @array: pointer to the array to be sorted
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quickSort(array, 0, size - 1, size);
}
