/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** the put part of libmy
*/

#ifndef MY_PUTS_H_
    #define MY_PUTS_H_

    #include <stdarg.h>

/**
** @brief reproduce the _printf
** @param format
** @param ...
** @return number of char wrote
**/
int my_printf(int fd, char const *format, ...);

/**
** @brief write c on stdout
** @param c
** @return number of char wrote
**/
int my_putchar(int fd, char c);

/**
** @brief write nb on stdout
** @param nb
** @return number of char wrote
**/
int my_putnbr(int fd, int nb);

/**
** @brief write nb on base base in stdout if base is not null
** @param nb
** @param base
** @return number of char wrote
**/
int my_putnbr_base(int fd, int nb, char const *base);

/**
** @brief write the \0 terminated str if str is not null
** @param str
** @return the number of char wrote
**/
int my_putstr(int fd, char const *str);

/**
** @brief write the unsigned nb on stdout if base is not null
** @param nb
** @param base
** @return the number of char wrote
**/
int my_putunbr_base(int fd, unsigned int nb, char const *base);

#endif
