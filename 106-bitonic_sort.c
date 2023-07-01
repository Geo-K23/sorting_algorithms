#include <stdio.h>
#include "sort.h"

/**
 * compareAndSwap - compare and swap elements based on the sorting direction
 * @up: direction of sorting
 * @array: pointer to sub-array to sort
 * @size: size of the sub-array
 */
void compareAndSwap(char up, int *array, size_t size)
{
	int temp;
	size_t k, dist;

	dist = size / 2;
	for (k = 0; k < dist; k++)
	{
		if ((array[k] > array[k + dist]) == up)
		{
			temp = array[k];
			array[k] = array[k + dist];
			array[k + dist] = temp;
		}
	}
}

/**
 * bitonicMerge - recursive function that merges two sub-arrays
 * @up: direction of sorting
 * @array: pointer to sub-array to sort
 * @size: size of the sub-array
 *
 * Return: nothing
 */
void bitonicMerge(char up, int *array, size_t size)
{
	if (size < 2)
		return;
	compareAndSwap(up, array, size);
	bitonicMerge(up, array, size / 2);
	bitonicMerge(up, array + (size / 2), size / 2);
}

/**
 * bitonicSort - recursive function using the Bitonic sort algorithm
 * @up: direction of sorting
 * @array: pointer to sub-array to sort
 * @size: size of the sub-array
 * @t: total size of the original array
 * Return: void
 */
void bitonicSort(char up, int *array, size_t size, size_t t)
{
	if (size < 2)
		return;
	printf("Merging [%lu/%lu] (%s):\n", size, t, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);
	bitonicSort(1, array, size / 2, t);
	bitonicSort(0, array + (size / 2), size / 2, t);
	bitonicMerge(up, array, size);
	printf("Result [%lu/%lu] (%s):\n", size, t, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);

}

/**
 * bitonic_sort - sorts an array of integers in ascending,
 * order using the Bitonic sort algorithm
 * @array: pointer to array to sort
 * @size: size of the array
 *
 * Return: void
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bitonicSort(1, array, size, size);
}
