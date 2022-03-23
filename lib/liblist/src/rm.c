/*
** EPITECH PROJECT, 2021
** rm.c
** File description:
** rm
*/

#include <stdlib.h>
#include "list.h"

void rm_fst_elem(list_ptr_t *list_ptr)
{
    list_t *cpy;

    if (list_ptr->len == 1) {
        free(list_ptr->start);
        list_ptr->start = NULL;
        list_ptr->len -= 1;
        list_ptr->end = NULL;
        return;
    }
    cpy = list_ptr->start;
    list_ptr->start = list_ptr->start->next;
    list_ptr->start->back = list_ptr->end;
    list_ptr->end->next = list_ptr->start;
    free(cpy);
    list_ptr->len -= 1;
}

void rm_last_elem(list_ptr_t *list_ptr)
{
    list_t *cpy;

    if (list_ptr->len == 1) {
        free(list_ptr->start);
        list_ptr->start = NULL;
        list_ptr->end = NULL;
        list_ptr->len -= 1;
        return;
    }
    cpy = list_ptr->end;
    list_ptr->end = list_ptr->end->back;
    list_ptr->end->next = list_ptr->start;
    list_ptr->start->back = list_ptr->end;
    free(cpy);
    list_ptr->len -= 1;
}

void rm_elem_i(list_ptr_t *list_ptr, int x)
{
    list_t *cpy;

    if (x == 0) {
        rm_fst_elem(list_ptr);
        return;
    } else if (x == list_ptr->len - 1) {
        rm_last_elem(list_ptr);
        return;
    }
    cpy = list_ptr->start;
    for (int i = 0; i < x && cpy != list_ptr->end; i++)
        cpy = cpy->next;
    cpy->back->next = cpy->next;
    cpy->next->back = cpy->back;
    free(cpy);
    list_ptr->len -= 1;
}
