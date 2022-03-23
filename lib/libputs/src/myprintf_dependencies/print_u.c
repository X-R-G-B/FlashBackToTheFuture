/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** take valist and put unsigned int
*/

#include <stdarg.h>
#include "my_puts.h"

int print_u(int fd, va_list ap)
{
    return (my_putunbr_base(fd, va_arg(ap, unsigned int), "0123456789"));
}
