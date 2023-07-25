#include "sort.h"

/**
* swap_node_behind - Swap nodes in a doubly-linked listint_t
* list with the one behind.
* @shaker: Pointer to current swapping node in cocktail shaker algo.
* @tail: Pointer to the tail of the DLL.
* @list: Pointer to DLL head of integers.
*/
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
listint_t *tmp = (*shaker)->prev;


if ((*shaker)->next != NULL)
(*shaker)->next->prev = tmp;
else
*tail = tmp;
tmp->next = (*shaker)->next;
(*shaker)->prev = tmp->prev;
if (tmp->prev != NULL)
tmp->prev->next = *shaker;
else
*list = *shaker;
(*shaker)->next = tmp;
tmp->prev = *shaker;
*shaker = tmp;
}

/**
* swap_node_ahead - Swap node in listint_t DLL with node ahead.
* @tail: Pointer to DLL tail.
* @shaker: Current node for swapping in cocktail shaker.
* @list: Pointer to DLL head of integers.
*
*/
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
listint_t *tmp = (*shaker)->next;


if ((*shaker)->prev != NULL)
(*shaker)->prev->next = tmp;
else
*list = tmp;
tmp->prev = (*shaker)->prev;
(*shaker)->next = tmp->next;
if (tmp->next != NULL)
tmp->next->prev = *shaker;
else
*tail = *shaker;
(*shaker)->prev = tmp;
tmp->next = *shaker;
*shaker = tmp;
}

/**
* cocktail_sort_list - Cocktail shaker sort for listint_t
* DLL in ascending order.
* @list: Pointer to DLL head..
*/
void cocktail_sort_list(listint_t **list)
{
listint_t *tail, *shaker;
bool shaken_not_stirred = false;


if (list == NULL || *list == NULL || (*list)->next == NULL)
return;


for (tail = *list; tail->next != NULL;)
tail = tail->next;


while (shaken_not_stirred == false)
{
shaken_not_stirred = true;
for (shaker = *list; shaker != tail; shaker = shaker->next)
{
if (shaker->n > shaker->next->n)
{
swap_node_ahead(list, &tail, &shaker);
print_list((const listint_t *)*list);
shaken_not_stirred = false;
}
}
for (shaker = shaker->prev; shaker != *list;
shaker = shaker->prev)
{
if (shaker->n < shaker->prev->n)
{
swap_node_behind(list, &tail, &shaker);
print_list((const listint_t *)*list);
shaken_not_stirred = false;
}
}
}
}
