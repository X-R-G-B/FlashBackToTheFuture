/*
** EPITECH PROJECT, 2022
** bgs
** File description:
** cast
*/

#include "my_bgs.h"

scene_t *get_scene_i(list_ptr_t *list, int i)
{
    list_t *elem = NULL;

    if (i >= list->len) {
        return NULL;
    }
    elem = get_element_i(list, i);
    return elem->var;
}
