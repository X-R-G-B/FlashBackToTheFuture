/*
** EPITECH PROJECT, 2022
** LIBCONVERSION
** File description:
** int to str with base b
*/

#include <stddef.h>
#include "my_conversions.h"

/**
** @brief int to str base base if base not null
** @param nb
** @param base
** @return null if error; else the str
**/
char *my_itoa_base(int nb, char const *base)
{
    int is_error = 0;

    if (base == NULL) {
        return (NULL);
    }
    return (my_itoa_base_err(nb, base, &is_error));
}
