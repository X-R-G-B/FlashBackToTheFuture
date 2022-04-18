/*
** EPITECH PROJECT, 2022
** LIBSTR
** File description:
** re alloc a ptr with a new str (free if *str != NULL)
*/

#include <stdlib.h>
#include "my_strings.h"

int my_strealloc(char **str, const char *dest)
{
    if (str == NULL) {
        return (0);
    }
    if (*str != NULL) {
        free(*str);
    }
    *str = my_strdup(dest);
    return (1);
}
