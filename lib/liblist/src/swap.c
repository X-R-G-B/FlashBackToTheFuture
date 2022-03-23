/*
** EPITECH PROJECT, 2021
** swap
** File description:
** swap elements
*/

#include "list.h"

void swap_two_elem(list_ptr_t *list_ptr, int x, int y)
{
    list_t *fst_elem;
    list_t *scd_elem;
    void *cpy;

    fst_elem = list_ptr->start;
    scd_elem = list_ptr->start;
    for (int i = 0; i < x && fst_elem != list_ptr->end; i++)
        fst_elem = fst_elem->next;
    for (int i = 0; i < y && fst_elem != list_ptr->end; i++)
        scd_elem = scd_elem->next;
    cpy = fst_elem->var;
    fst_elem->var = scd_elem->var;
    scd_elem->var = cpy;
}

void move_last_elem_to_start(list_ptr_t *list_ptr)
{
    list_ptr->start = list_ptr->end;
    list_ptr->end = list_ptr->end->back;
}

void move_first_elem_to_end(list_ptr_t *list_ptr)
{
    list_ptr->end = list_ptr->start;
    list_ptr->start = list_ptr->start->next;
}

void rev_list(list_ptr_t *list_ptr)
{
    int max = list_ptr->len / 2;
    int count = list_ptr->len - 1;

    for (int i = 0; i < max; i++) {
        swap_two_elem(list_ptr, i, count);
        count -= 1;
    }
}
