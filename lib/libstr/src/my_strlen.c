/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** get length of null terminated str
*/

#include <stddef.h>

/**
** @brief get lentgh of null terminated str
** @param str
** @return -1 if str is null; else the length
**/
int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL) {
        return (-1);
    }
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
