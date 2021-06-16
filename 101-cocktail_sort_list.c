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

	if (!list || !*list || !(*list)->next)
		return;


	do {
		swapped = 0;
		while (temp->next != NULL)
		{
			if ((temp->n) > ((temp->next)->n))
			{
				swap_link(temp, temp->next, list);
				print_list(*list);
				swapped = 1;
				temp = temp->prev;
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
				swap_link(temp->prev, temp, list);
				swapped = 1;
				print_list(*list);
				temp = temp->next;
			}
			temp = temp->prev;
		}
	}while (swapped);
}
/**
 * swap_link - swap adjacent nodes of a doubly linked list
 * @first: first node
 * @second: second node
 * @head: head of list
 *
 * Return: void
 */
void swap_link(listint_t *first, listint_t *second, listint_t **head)
{
	if (first->prev != NULL)
		(first->prev)->next = second;
	else
		*head = second;
	first->prev = second;
	first->next = second->next;
	second->prev = first->prev;
	second->next = first;
	if (second->next != NULL)
		(second->next)->prev = first;
}
