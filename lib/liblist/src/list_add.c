/*
** EPITECH PROJECT, 2021
** list_add.c
** File description:
** add a list to the chained list
*/

#include <stdlib.h>
#include "list.h"

list_t *list_add_to_end(list_ptr_t *list_ptr, void *content)
{
    list_t *newelem = malloc(sizeof(list_t));

    if (newelem == NULL || content == NULL || list_ptr == NULL) {
        return NULL;
    }
    newelem->var = content;
    newelem->back = list_ptr->end;
    newelem->next = list_ptr->start;
    if (list_ptr->len == 0) {
        list_ptr->start = newelem;
        list_ptr->end = newelem;
    }
    list_ptr->start->back = newelem;
    list_ptr->end->next = newelem;
    list_ptr->end = newelem;
    list_ptr->len += 1;
    return (newelem);
}

list_t *list_add_to_start(list_ptr_t *list_ptr, void *content)
{
    list_t *newelem = malloc(sizeof(list_t));

    if (newelem == NULL || list_ptr == NULL || content == NULL) {
        return NULL;
    }
    newelem->var = content;
    newelem->back = list_ptr->end;
    newelem->next = list_ptr->start;
    if (list_ptr->len == 0) {
        list_ptr->start = newelem;
        list_ptr->end = newelem;
    }
    list_ptr->end->next = newelem;
    list_ptr->start->back = newelem;
    list_ptr->start = newelem;
    list_ptr->len += 1;
    return (newelem);
}

list_t *list_add_to_i(list_ptr_t *list_ptr, void *content, int i)
{
    list_t *newelem = malloc(sizeof(list_t));
    list_t *id = NULL;

    if (newelem == NULL || list_ptr == NULL || content == NULL) {
        return NULL;
    } else if (i == 0) {
        return list_add_to_start(list_ptr, content);
    }
    newelem->var = content;
    id = list_ptr->start;
    for (int x = 0; x < i && id != list_ptr->end; x++)
        id = id->next;
    newelem->back = id;
    newelem->next = id->next;
    id->next->back = newelem;
    id->next = newelem;
    list_ptr->len += 1;
    return (newelem);
}
