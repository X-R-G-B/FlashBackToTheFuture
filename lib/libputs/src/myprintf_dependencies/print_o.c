/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** put uint in octal base
*/

#include <stdarg.h>
#include "my_puts.h"

int print_o(int fd, va_list ap)
{
    return (my_putunbr_base(fd, va_arg(ap, unsigned int), "01234567"));
}
