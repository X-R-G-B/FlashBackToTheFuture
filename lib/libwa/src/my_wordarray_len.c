/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** get length of word array
*/

#include <stddef.h>

/**
** @brief get length of null terminated 2d array
** @param array
** @return 0 if array is null; else the length
**/
int my_wordarray_len(char *const *array)
{
    int i = 0;

    if (array == NULL) {
        return (0);
    }
    for (; array[i] != NULL; i++);
    return (i);
}
