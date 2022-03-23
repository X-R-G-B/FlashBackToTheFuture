/*
** EPITECH PROJECT, 2022
** LIBCONVERSION
** File description:
** int to str in base b with a status error
*/

#include <stdlib.h>
#include "my_macro.h"
#include "my_strings.h"

static char *dup_and_cat(char *dest, char c, int *cap)
{
    int len = my_strlen(dest);
    char *new = NULL;

    if (len + 2 >= *cap) {
        *cap = *cap + 12;
        new = my_calloc(*cap);
        if (!new)
            return (NULL);
        for (int i = 0; i < len; i++)
            new[i] = dest[i];
        free(dest);
        dest = new;
    }
    dest[len] = c;
    return (dest);
}

static void do_zero_special_case(int nb, char *result)
{
    if (nb == 0 && result != NULL) {
        result[0] = '0';
    }
}

/**
** @brief int to str in base base if base is not null
** @param nb
** @param base
** @param is_error
** @return *is_error set to 1 if error; otherwise the str
**/
char *my_itoa_base_err(int nb, char const *base, int *is_error)
{
    int i = 0;
    int max_cap = 12;
    int is_neg = nb < 0;
    char *result = my_calloc(max_cap);

    nb = ABSOL(nb);
    do_zero_special_case(nb, result);
    for (; nb != 0 && base != NULL && result != NULL; i++) {
        result = dup_and_cat(result, base[nb % my_strlen(base)], &max_cap);
        nb /= my_strlen(base);
    }
    if (is_neg && result != NULL && base != NULL) {
        result[i] = '-';
    }
    if (result == NULL || base == NULL) {
        *is_error = 1;
    }
    return (my_revstr(result));
}
