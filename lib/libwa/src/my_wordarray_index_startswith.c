/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** get index from a str startswith
*/

#include <stddef.h>
#include "my_strings.h"

/**
** @brief search the first occurence of str in the 2d array and get its index
** @param arr
** @param str
** @return -1 if arr is null or there is no occurence; otherwise the index
**/
int my_wordarray_get_index_startswith(char *const *arr, char const *str)
{
    int i = 0;
    int find = 0;

    if (arr == NULL) {
        return (-1);
    }
    for (; arr[i] != NULL && find == 0; i++) {
        if (my_strstartswith(arr[i], str)) {
            find = 1;
        }
    }
    if (find == 0) {
        return (-1);
    } else {
        return (i - 1);
    }
}
