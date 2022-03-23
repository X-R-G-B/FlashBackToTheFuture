/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** take valist and put decimal
*/

#include <stdarg.h>
#include "my_puts.h"

int print_d(int fd, va_list ap)
{
    return (my_putnbr(fd, va_arg(ap, int)));
}
