/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** put a decimal nbr in stdout
*/

#include "my_puts.h"

/**
** @brief write nb on stdout
** @param nb
** @return number of char wrote
**/
int my_putnbr(int fd, int nb)
{
    char const base[] = "0123456789";

    return (my_putnbr_base(fd, nb, base));
}
