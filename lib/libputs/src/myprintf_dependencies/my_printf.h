/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** the internal function and structure for _printf
*/

#ifndef MY_PRINTF_H_
    #define MY_PRINTF_H_

    #include <stdarg.h>

struct specifier_struct {
    char prefix;
    int (*fptr)(int fd, va_list);
};
typedef struct specifier_struct specifier_t;

// print char
int print_c(int fd, va_list);

// print int
int print_d(int fd, va_list);

// print uint
int print_u(int fd, va_list);

// print uint in octal
int print_o(int fd, va_list);

// print uint in binary
int print_b(int fd, va_list);

// print uint in hexa low
int print_x_low(int fd, va_list);

// print uint in hexa up
int print_x_up(int fd, va_list);

// print str
int print_s(int fd, va_list);

// print %
int print_mod(int fd, va_list);

#endif
