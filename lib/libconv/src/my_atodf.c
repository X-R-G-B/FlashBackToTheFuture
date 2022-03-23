/*
** EPITECH PROJECT, 2022
** libconv
** File description:
** get float from str
*/

#include "my_conversions.h"

double my_atodf(char const *str)
{
    int is_error = 0;

    return (my_atodf_err(str, &is_error));
}
