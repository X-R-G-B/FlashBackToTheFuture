/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** put decimal number in base b
*/

#include <stdlib.h>
#include "my_conversions.h"
#include "my_puts.h"

/**
** @brief write nb on base base in stdout if base is not null
** @param nb
** @param base
** @return number of char wrote
**/
int my_putnbr_base(int fd, int nb, char const *base)
{
    int i = 0;
    char *result = NULL;

    if (base == NULL) {
        return (0);
    }
    result = my_itoa_base(nb, base);
    i = my_putstr(fd, result);
    free(result);
    return (i);
}
