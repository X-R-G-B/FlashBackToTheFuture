/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** play_menu
*/

#include "my_bgs_button_generator.h"

void load_save_scene(object_t *obj, scene_t *scene,
    window_t *win, set_event_t *event)
{
    list_t *elem = NULL;
    list_ptr_t *load_game = dico_t_get_value(scene->components,
                            "POP_UP_PLAY");

    if (!load_game) {
        return;
    }
    elem = load_game->start;
    for (int i = 0; i != load_game->len; i++) {
        ((object_t *) elem->var)->is_visible = true;
        elem = elem->next;
    }
}
