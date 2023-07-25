#include "sort.h"

/**
* swap_intshaw - exchange 2 int in an array.
* @b: 2nd integer to exchange.
* @a: 1st integer to exchange.
*/
void swap_intshaw(int *a, int *b)
{
int tmp;

tmp = *a;
*a = *b;
*b = tmp;
}

/**
* max_heapify - Binary tree to complete binary heap.
* @root: Root node of binary tree.
* @array: Binary tree represented as integer array.
* @base: Index of base row in tree.
* @size: Array/Tree size.
*/
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
size_t left, right, large;

left = 2 * root + 1;
right = 2 * root + 2;
large = root;

if (left < base && array[left] > array[large])
large = left;
if (right < base && array[right] > array[large])
large = right;

if (large != root)
{
swap_intshaw(array + root, array + large);
print_array(array, size);
max_heapify(array, size, base, large);
}
}

/**
* heap_sort - Sort integer array in ascending order
*             Using heap sort algorithm.
* @array: Integer array.
* @size: Array size.
*
* Description: Sift-down heap sort implementation
* algorithm. Print array after swaps.
*/
void heap_sort(int *array, size_t size)
{
int i;

if (array == NULL || size < 2)
return;

for (i = (size / 2) - 1; i >= 0; i--)
max_heapify(array, size, size, i);

for (i = size - 1; i > 0; i--)
{
swap_intshaw(array, array + i);
print_array(array, size);
max_heapify(array, size, i, 0);
}
}
