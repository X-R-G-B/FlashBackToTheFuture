/*
** EPITECH PROJECT, 2021
** get
** File description:
** get a i
*/

#include <stddef.h>
#include "list.h"

void *get_element_i_var(list_ptr_t *list_ptr, int x)
{
    list_t *ptr;

    ptr = list_ptr->start;
    for (int i = 0; i < x && ptr != list_ptr->end; i++)
        ptr = ptr->next;
    return ptr->var;
}

list_t *get_element_i(list_ptr_t *list_ptr, int x)
{
    list_t *ptr = NULL;

    ptr = list_ptr->start;
    for (int i = 0; i < x; i++)
        ptr = ptr->next;
    return ptr;
}
