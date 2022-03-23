/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** take valist and put %
*/

#include <stdarg.h>
#include "my_puts.h"

int print_mod(int fd, __attribute__((unused)) va_list ap)
{
    return (my_putchar(fd, '%'));
}
