#include "sort.h"

/**
 * insertion_sort_list - a function that sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm
 * @list: the list to be sorted
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t  *tmp, *last;
	listint_t  *current;

	if (*list == NULL || !(*list) || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		last = current->prev;
		tmp = current->next;
		while (last && current->n < last->n)
		{
			swap_nodes(list, current, last);
			print_list(*list);
			last = current->prev;
		}
		current = tmp;
	}
}

/**
 * swap_nodes - a function that swaps two nodes
 * @list: doubly linked list
 * @current: current node
 * @last: last node
 *
 */

void swap_nodes(listint_t **list, listint_t *current, listint_t *last)
{
	if (last->prev)
		last->prev->next = current;
	last->next = current->next;
	current->next = last;
	current->prev = last->prev;
	last->prev = current;
	if (last->next)
		last->next->prev = last;
	if (!current->prev)
		*list = current;
}

