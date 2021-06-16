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
	int swapped;

	do
	{
		swapped = 0;
		while (temp->next != NULL)
		{
			if ((temp->n) > ((temp->next)->n))
			{
				swap_link(temp, temp->next);
				print_list(*list);
				swapped = 1;
				continue;
			}
			temp = temp->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (temp->prev != NULL)
		{
			if ((temp->n) < ((temp->prev)->n))
			{
				swap_link(temp->prev, temp);
				swapped = 1;
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
 * swap_link - swap adjacent nodes of a doubly linked list
 * @first: first node
 * @second: second node
 *
 * Return: void
 */
void swap_link(listint_t *first, listint_t *second)
{
	listint_t *a = first->prev;
	listint_t *b = second->next;

	if (a != NULL)
		(a)->next = second;
	first->prev = second;
	first->next = b;
	second->prev = a;
	second->next = first;
	if (second->next != NULL)
		b->prev = first;
}
