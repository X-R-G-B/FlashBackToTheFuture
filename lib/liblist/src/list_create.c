/*
** EPITECH PROJECT, 2021
** list_create.c
** File description:
** create a list
*/

#include <stdlib.h>
#include "list.h"

list_ptr_t *list_create(void)
{
    list_ptr_t *list_ptr = malloc(sizeof(list_ptr_t));

    if (!list_ptr)
        return NULL;
    list_ptr->len = 0;
    list_ptr->start = NULL;
    list_ptr->end = NULL;
    return list_ptr;
}
