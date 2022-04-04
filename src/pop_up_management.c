/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** pop_up_management
*/

#include "my_bgs_button_generator.h"

void free_pop_up(void *list)
{
    free_list(list);
}

void set_is_visible_false(list_ptr_t *list)
{
    list_t *elem = NULL;

    if (!list) {
        return;
    }
    elem = list->start;
    for (int i = 0; i != list->len; i++) {
        ((object_t *) elem->var)->is_visible = false;
        elem = elem->next;
    }
}

int check_if_pop_up_true(scene_t *scene, char *key)
{
    list_t *elem = NULL;
    list_ptr_t *list = dico_t_get_value(scene->components, key);

    if (!list)
        return (1);
    elem = list->start;
    if (((object_t *) elem->var)->is_visible == true) {
        set_is_visible_false(list);
        return (1);
    }
    return (0);
}
