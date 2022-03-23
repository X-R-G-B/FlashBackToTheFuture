/*
** EPITECH PROJECT, 2022
** cast a var
** File description:
** cast the void ptr
*/

#include "list.h"

char *str_from_list(list_t *elem)
{
    return ((char *) (elem->var));
}
