#include <stdio.h>
#include "sort.h"

/**
 * swap_nodes - swaps a node with the next node in the list
 * @list: double pointer to the beginning of the list
 * @node: node to swap
 *
 * Return: nothing
 */
void swap_nodes(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in,
 * ascending order using the Cocktail shaker sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	char sorted = 1;

	if (list == NULL || *list == NULL)
		return;
	current = *list;
	while (sorted != 0)
	{
		sorted = 0;
		while (current->next != NULL)
		{
			if (current->next->n < current->n)
			{
				swap_nodes(list, current);
				sorted = 1;
				print_list(*list);
			}
			else
				current = current->next;
		}
		if (sorted == 0)
			break;
		sorted = 0;
		while (current->prev != NULL)
		{
			if (current->prev->n > current->n)
			{
				swap_nodes(list, current->prev);
				sorted = 1;
				print_list(*list);
			}
			else
				current = current->prev;
		}
	}
}
