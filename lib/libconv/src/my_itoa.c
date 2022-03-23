/*
** EPITECH PROJECT, 2022
** LIBCONVERSION
** File description:
** int to str in base 10
*/

#include "my_conversions.h"

/**
** @brief int to str in base 10
** @param nb
** @return null if there is error; the str else
**/
char *my_itoa(int nb)
{
    int is_error = 0;

    return (my_itoa_err(nb, &is_error));
}
