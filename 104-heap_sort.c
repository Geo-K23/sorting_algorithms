#include <stdio.h>
#include "sort.h"

/**
* heapify - creates a max heap and maintains its property during,
* the sorting process
* @array: pointer to array to sort
* @heap: size of heap data
* @i: index
* @size: size of array
*/

void heapify(int *array, int heap, int i, int size)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2, t;

	if (left < heap && array[left] > array[largest])
		largest = left;
	if (right < heap && array[right] > array[largest])
		largest = right;
	if (largest != i)
	{
		t = array[i], array[i] = array[largest], array[largest] = t;
		print_array(array, size);
		heapify(array, heap, largest, size);
	}
}

/**
* heap_sort - Sorts an array using the heap sort algorithm
* @array: pointer to array to sort
* @size: Size of array to sort
* Return: void
*/

void heap_sort(int *array, size_t size)
{
	int k = size / 2 - 1, tmp;

	if (array == NULL || size < 2)
		return;
	for (; k >= 0; k--)
		heapify(array, size, k, size);
	for (k = size - 1; k >= 0; k--)
	{
		tmp = array[0];
		array[0] = array[k];
		array[k] = tmp;
		if (k > 0)
			print_array(array, size);
		heapify(array, k, 0, size);
	}
}
