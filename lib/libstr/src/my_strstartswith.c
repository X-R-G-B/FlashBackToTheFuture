/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** check is str starts with str
*/

#include "my_strings.h"

/**
** @brief check if str start with substr
** @param str
** @param substr
** @return 1 if str start with substr; 0 otherwise
**/
int my_strstartswith(char const *str, char const *substr)
{
    int i = 0;
    int size = my_strlen(substr);

    while (str[i] != '\0' && substr[i] != '\0' && str[i] == substr[i]) {
        i++;
    }
    if (i == size) {
        return (1);
    } else {
        return (0);
    }
}
