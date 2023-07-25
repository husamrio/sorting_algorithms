#include "sort.h"

/**
* swap_nodeshaw - Swap two nodes in a listint_t doubly-linked list.
* @h:Pointer to the head of the list.
* @n2: The second node to swap.
* @n1: A pointer to the first node to swap.
*/
void swap_nodeshaw(listint_t **h, listint_t **n1, listint_t *n2)

{
(*n1)->next = n2->next;
if (n2->next != NULL)
n2->next->prev = *n1;
n2->prev = (*n1)->prev;
n2->next = *n1;

if ((*n1)->prev != NULL)
(*n1)->prev->next = n2;

else
*h = n2;

(*n1)->prev = n2;
*n1 = n2->prev;
}


/**
* insertion_sort_listhaw - This function sorts a doubly-linked list
* of integers.
* using the insertion sort algorithm.
* @list: Pointer to the head of the list..
*
* Description: Prints the list after each swap.
*/
void insertion_sort_listhaw(listint_t **list)

{
listint_t *iter, *insert, *tmp;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

for (iter = (*list)->next; iter != NULL; iter = tmp)
{
tmp = iter->next;
insert = iter->prev;

while (insert != NULL && iter->n < insert->n)
{
swap_nodeshaw(list, &insert, iter);
print_list((const listint_t *)*list);
}
}
}
