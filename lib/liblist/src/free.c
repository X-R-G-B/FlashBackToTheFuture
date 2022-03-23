/*
** EPITECH PROJECT, 2021
** free.c
** File description:
** free
*/

#include <stdlib.h>
#include "list.h"

void free_list(list_ptr_t *list_ptr)
{
    list_t *cpy;

    for (int i = 0; i < list_ptr->len; i++) {
        cpy = list_ptr->start;
        list_ptr->start = cpy->next;
        free(cpy);
    }
    free(list_ptr);
}
