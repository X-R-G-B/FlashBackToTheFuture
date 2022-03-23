/*
** EPITECH PROJECT, 2022
** LIBSTR
** File description:
** check if str contains substr
*/

#include <stddef.h>
#include "my_strings.h"

/**
** @brief check if substr is in str
** @param str
** @param substr
** @return 1 if substr is in str; 0 otherwise
**/
int my_strcontains(char const *str, char const *substr)
{
    int j = 0;
    int len_sub = 0;
    int not_find = 1;

    len_sub = my_strlen(substr);
    if (len_sub == 0 || str == NULL) {
        return (0);
    }
    for (int i = 0; not_find == 1 && str[i] != '\0'; i++) {
        j = 0;
        while (j < len_sub && str[i + j] != '\0' && substr[j] == str[i + j]) {
            j++;
        }
        if (j == len_sub) {
            not_find = 0;
        }
    }
    return ((not_find) ? 0 : 1);
}
