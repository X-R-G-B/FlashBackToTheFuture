/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** take valist and put int to binary
*/

#include <stdarg.h>
#include "my_puts.h"

int print_b(int fd, va_list ap)
{
    return (my_putunbr_base(fd, va_arg(ap, unsigned int), "01"));
}
