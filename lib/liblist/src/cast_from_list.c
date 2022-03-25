/*
** EPITECH PROJECT, 2022
** cast a var
** File description:
** cast the void ptr
*/

#include <stddef.h>
#include "list.h"

char *str_from_list(list_t *elem)
{
    if (elem == NULL) {
        return (NULL);
    }
    return ((char *) (elem->var));
}
