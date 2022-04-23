/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** play_menu
*/

#include "my_bgs_button_generator.h"

void toggle_pop_up(dico_t *dico, const char *key)
{
    list_t *elem = NULL;
    list_ptr_t *list = dico_t_get_value(dico, key);
    object_t *obj = NULL;

    if (list == NULL) {
        return;
    }
    elem = list->start;
    for (int i = 0; i != list->len; i++) {
        obj = elem->var;
        obj->is_visible = (obj->is_visible == false) ? true : false;
        elem = elem->next;
    }
}
