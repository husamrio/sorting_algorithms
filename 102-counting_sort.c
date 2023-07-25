#include "sort.h"

/**
* get_maxhaw - Find max in integer array..
* @size: Array size.
* @array: Array of integers.
* Return: Max integer in array..
*/
int get_maxhaw(int *array, int size)
{
int max, i;


for (max = array[0], i = 1; i < size; i++)
{
if (array[i] > max)
max = array[i];
}

return (max);
}

/**
* counting_sort - Counting sort for integer array (ascending).
* @array: Integer array.
* @size: Array size.
*
* Description: Print counting array.
*/
void counting_sort(int *array, size_t size)
{
int *count, *sorted, max, i;


if (array == NULL || size < 2)
return;


sorted = malloc(sizeof(int) * size);
if (sorted == NULL)
return;
max = get_maxhaw(array, size);
count = malloc(sizeof(int) * (max + 1));
if (count == NULL)
{
free(sorted);
return;
}

for (i = 0; i < (max + 1); i++)
count[i] = 0;
for (i = 0; i < (int)size; i++)
count[array[i]] += 1;
for (i = 0; i < (max + 1); i++)
count[i] += count[i - 1];
print_array(count, max + 1);


for (i = 0; i < (int)size; i++)
{
sorted[count[array[i]] - 1] = array[i];
count[array[i]] -= 1;
}

for (i = 0; i < (int)size; i++)
array[i] = sorted[i];

free(sorted);
free(count);
}
