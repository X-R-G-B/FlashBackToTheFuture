/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** reproduce the _printf
*/

#include <stddef.h>
#include <stdarg.h>
#include "my_printf.h"
#include "my_puts.h"

static const specifier_t SPECIFIERS[] = {
    {'c', &print_c},
    {'d', &print_d},
    {'i', &print_d},
    {'u', &print_u},
    {'o', &print_o},
    {'b', &print_b},
    {'x', &print_x_low},
    {'X', &print_x_up},
    {'s', &print_s},
    {'%', &print_mod},
    {'\0', NULL}
};

static int print_specifier(int fd, va_list ap, char const *c)
{
    int ret = 0;

    if (c[0] != '%') {
        return (0);
    }
    for (int i = 0; ret == 0 && SPECIFIERS[i].fptr != NULL; i++) {
        if (SPECIFIERS[i].prefix == c[1]) {
            ret += SPECIFIERS[i].fptr(fd, ap);
        }
    }
    return (ret);
}

/**
** @brief reproduce the _printf
** @param format
** @param ...
** @return number of char wrote
**/
int my_printf(int fd, char const *format, ...)
{
    va_list ap;
    int ret = 0;
    int tmp = 0;

    va_start(ap, format);
    for (int i = 0; format != NULL && format[i] != '\0'; i++) {
        tmp = print_specifier(fd, ap, format + i);
        if (tmp != 0) {
            ret += tmp;
            i++;
        } else {
            ret += my_putchar(fd, format[i]);
        }
    }
    va_end(ap);
    return (ret);
}
