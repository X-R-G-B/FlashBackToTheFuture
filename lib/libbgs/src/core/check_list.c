/*
** EPITECH PROJECT, 2022
** bgs
** File description:
** check list
*/

#include <stdbool.h>
#include <stddef.h>
#include "list.h"

bool check_list(list_ptr_t *list, void *data)
{
    list_t *elem = NULL;

    if (list == NULL) {
        return (false);
    }
    elem = list->start;
    for (int i = 0; i < list->len; i++, elem = elem->next) {
        if (elem->var == data) {
            rm_elem_i(list, i);
            return true;
        }
    }
    return false;
}
