#include "sort.h"

/**
 * cocktail_sort_list - cocktail sorting method
 * @list: head of linked list
 *
 * Return: void function
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *temp = *list;
	int swapped = 0;

	while (!swapped)
	{
		swapped = 1;
		while (temp->next != NULL)
		{
			if ((temp->n) > ((temp->next)->n))
			{
				swap_nodes(temp, temp->next);
				print_list(*list);
				swapped = 0;
				continue;
			}
			temp = temp->next;
		}
		if (swapped == 1)
			break;
		swapped = 1;
		while (temp->prev != NULL)
		{
			if ((temp->n) < ((temp->prev)->n))
			{
				swap_nodes(temp->prev, temp);
				swapped = 0;
				if (temp->prev == NULL)
					*list = temp;
				print_list(*list);
				continue;
			}
			temp = temp->prev;
		}
	} while (swapped);
}

/**
 * swap_nodes - swap adjacent nodes of a doubly linked list
 * @first: first node
 * @second: second node
 *
 * Return: void
 */
void swap_nodes(listint_t *first, listint_t *second)
{
	if (first->prev != NULL)
		(first->prev)->next = second;
	if (second->next != NULL)
		(second->next)->prev = first;
	second->prev = first->prev;
	first->prev = second;
	first->next = second->next;
	second->next = first;
}
