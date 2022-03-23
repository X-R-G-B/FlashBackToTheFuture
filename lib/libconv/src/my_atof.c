/*
** EPITECH PROJECT, 2022
** libconv
** File description:
** get float from str
*/

#include "my_conversions.h"

float my_atof(char const *str)
{
    int is_error = 0;

    return (my_atof_err(str, &is_error));
}
