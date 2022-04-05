/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** play_menu
*/

#include "my_bgs_button_generator.h"

void toggle_pop_up(dico_t *dico, char *key)
{
    list_t *elem = NULL;
    list_ptr_t *load_game = dico_t_get_value(dico, key);
    object_t *obj = NULL;

    if (load_game == NULL) {
        return;
    }
    elem = load_game->start;
    for (int i = 0; i != load_game->len; i++) {
        obj = elem->var;
        obj->is_visible = (obj->is_visible == false) ? true : false;
        elem = elem->next;
    }
}
