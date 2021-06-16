#include "sort.h"

/**
 * cocktail_sort_list - cocktail sorting method
 * @list: head of linked list
 *
 * Return: void function
 */


void cocktail_sort_list(listint_t **list)
{
	listint_t *temp;
	int swapped = 0;

	if (!list || !*list || !(*list)->next)
		return;


	do {
		swapped = 0;
		for (temp = *list; temp->next != NULL; temp = temp->next)
		{
			if (temp->n > temp->next->n)
			{
				swap_link(list, temp, temp->next);
				print_list(*list);
				swapped = 1;
				temp = temp->prev;
			}
		}
		if (swapped == 0)
			break;
		swapped = 0;
		for (; temp->prev != NULL; temp = temp->prev)
		{
			if (temp->n < temp->prev->n)
			{
				swap_link(list, temp->prev, temp);
				swapped = 1;
				print_list(*list);
				temp = temp->next;
			}
		}
	} while (swapped);
}

/**
 * swap_link - swap adjacent nodes of a doubly linked list
 * @first: first node
 * @second: second node
 * @head: head of list
 *
 * Return: void
 */
void swap_link(listint_t **head, listint_t *node1, listint_t *node2)
{
	listint_t *prev, *next;

	prev = node1->prev;
	next = node2->next;

	if (prev != NULL)
		prev->next = node2;
	else
		*head = node2;
	node1->prev = node2;
	node1->next = next;
	node2->prev = prev;
	node2->next = node1;
	if (next)
		next->prev = node1;
}
