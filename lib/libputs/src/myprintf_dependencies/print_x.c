/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** put uint in hexa
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my_puts.h"

int print_x_low(int fd, va_list ap)
{
    return (my_putunbr_base(fd, va_arg(ap, unsigned int), "0123456789abcdef"));
}

int print_x_up(int fd, va_list ap)
{
    return (my_putunbr_base(fd, va_arg(ap, unsigned int), "0123456789ABCDEF"));
}
