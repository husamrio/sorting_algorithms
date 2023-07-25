#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Node of a doubly-linked list
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Bitonic sort comparison direction macros */
#define DOWN 1
#define UP 0

/**
 * enum bool - Boolean Enumeration values.
 * @true: Equals 1.
 * @false: Equals 0.
 
 */
typedef enum bool
{
	false = 0,
	true
} bool;



/* Helper printing functions */
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

/* Sort algorithms */
void quick_sort_hoare(int *array, size_t size);
void radix_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void merge_sort(int *array, size_t size);
void bubble_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void exchange_intshaw(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

#endif /* SORT_H */
