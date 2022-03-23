/*
** EPITECH PROJECT, 2022
** LIBCONVERSION
** File description:
** get nbr from str
*/

#include "my_conversions.h"

/**
** @brief get the number in str
** @param str
** @return the number (0 if it not a number (my_atoi_err))
**/
int my_atoi(char const *str)
{
    int is_error = 0;

    return (my_atoi_err(str, &is_error));
}
