#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * power_of_10 - calculates a positive power of 10
 * @power: power of 10 to be calculated
 *
 * Return: the corresponding power of 10
 */
unsigned int power_of_10(unsigned int power)
{
	unsigned int i, result;

	result = 1;
	for (i = 0; i < power; i++)
		result *= 10;
	return (result);
}

/**
 * countingSort - sorts an array of integers in ascending order at,
 * a specific digit location using the Counting sort algorithm
 * @array: pointer to array to sort
 * @size: size of the array to sort
 * @digit: digit to sort by
 *
 * Return: 1 if there is need to keep sorting, 0 otherwise
 */
unsigned int countingSort(int *array, size_t size, unsigned int digit)
{
	int i, count[10] = {0};
	int *new = NULL;
	size_t j, temp, total = 0;
	unsigned int b1, b2, sort = 0;

	b2 = power_of_10(digit - 1);
	b1 = b2 * 10;
	new = malloc(sizeof(int) * size);
	if (new == NULL)
		exit(1);
	for (j = 0; j < size; j++)
	{
		new[j] = array[j];
		if (array[j] / b1 != 0)
			sort = 1;
	}
	for (i = 0; i < 10 ; i++)
		count[i] = 0;
	for (j = 0; j < size; j++)
		count[(array[j] % b1) / b2] += 1;
	for (i = 0; i < 10; i++)
	{
		temp = count[i];
		count[i] = total;
		total += temp;
	}
	for (j = 0; j < size; j++)
	{
		array[count[(new[j] % b1) / b2]] = new[j];
		count[(new[j] % b1) / b2] += 1;
	}
	free(new);
	return (sort);
}

/**
 * radix_sort - sorts an array of integers in ascending order,
 * using the Radix sort algorithm
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	unsigned int i, sort = 1;

	if (array == NULL || size < 2)
		return;
	for (i = 1; sort == 1; i++)
	{
		sort = countingSort(array, size, i);
		print_array(array, size);
	}
}
