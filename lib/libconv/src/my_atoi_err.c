/*
** EPITECH PROJECT, 2021
** LIBCONVERSION
** File description:
** str to int with error status
*/

#include <stddef.h>
#include "my_strings.h"

static int get_out_of_noise(char const *str, int *is_error)
{
    int i = 0;

    if (str == NULL) {
        *is_error = 1;
        return (84);
    }
    while (str[i] != '\0' && my_strcontainc("\b\t\n\v\f\r ", str[i])) {
        i++;
    }
    return (i);
}

static int check_if_negativ_number(char const *str, int i)
{
    int nb_minus = 0;

    while (str[i] != '\0' && my_strcontainc("+-", str[i])) {
        if (str[i] == '-') {
            nb_minus += 1;
        }
        i++;
    }
    return (nb_minus % 2 != 0);
}

static int get_out_of_sign(char const *str, int i, int *is_error)
{
    while (str[i] != '\0' && my_strcontainc("+-", str[i])) {
        i++;
    }
    if (my_strcontainc("123456789", str[i]) == 0) {
        if (str[i] == '0' && my_strcontainc("123456789", str[i]) == 0) {
            return (i);
        }
        *is_error = 1;
        return (84);
    }
    return (i);
}

static int get_absol_neg_result(char const *str, int i)
{
    int result = 0;

    while (str[i] != '\0' && my_strcontainc("0123456789", str[i])) {
        result *= 10;
        result -= str[i] - '0';
        i++;
    }
    return (result);
}

/**
** @brief get the number in str
** @param str
** @param is_error
** @return 0 if there is an error and *is_error set to 1; the number else
**/
int my_atoi_err(char const *str, int *is_error)
{
    int i = 0;
    int nb_minus = 0;
    int result = 0;

    i = get_out_of_noise(str, is_error);
    if (*is_error) {
        return (0);
    }
    nb_minus = check_if_negativ_number(str, i);
    i = get_out_of_sign(str, i, is_error);
    if (*is_error) {
        return (0);
    }
    result = get_absol_neg_result(str, i);
    if (nb_minus == 0) {
        result *= -1;
    }
    return (result);
}
