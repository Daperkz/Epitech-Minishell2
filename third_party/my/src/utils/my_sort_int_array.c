/*
** EPITECH PROJECT, 2025
** my_sort_int_array
** File description:
** sorts an integer array in ascending order
*/

#include "my/utils.h"

int min_in_array(int *arr, int size, int i)
{
    int min = i;

    for (int j = i + 1; j < size; j++) {
        if (arr[min] > arr[j])
            min = j;
    }
    return min;
}

void my_sort_int_array(int *tab, int size)
{
    int min;

    for (int i = 0; i < size; i++) {
        min = min_in_array(tab, size, i);
        my_swap(&tab[i], &tab[min]);
    }
}
