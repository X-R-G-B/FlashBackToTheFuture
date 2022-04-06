/*
** EPITECH PROJECT, 2022
** button generator
** File description:
** fill object list
*/

#include "my_bgs_button_generator.h"

list_ptr_t *fill_obj_list(list_t *elem, scene_t *scene)
{
    list_ptr_t *list = list_create();

    if (scene == NULL || list == NULL || scene->objects == NULL ||
        scene->objects->len == 0) {
        return NULL;
    } else if (elem == NULL) {
        elem = scene->objects->end;
    }
    do {
        elem = elem->next;
        list_add_to_end(list, elem->var);
    } while (elem != scene->objects->end);
    return list;
}
