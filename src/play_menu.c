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

    if (!load_game) {
        return;
    }
    elem = load_game->start;
    for (int i = 0; i != load_game->len; i++) {
        ((object_t *) elem->var)->is_visible =
            (((object_t *) elem->var)->is_visible == false) ? true : false;
        elem = elem->next;
    }
}
