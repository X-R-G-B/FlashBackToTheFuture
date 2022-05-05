/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** dead_screen_input
*/

#include "my_bgs_components.h"
#include "my_rpg.h"

static void handle_dead_key_input(int key, window_t *window, scene_t *scene)
{
    switch (key) {
        case sfKeyQ:
            sfRenderWindow_close(window->win);
            return;
        case sfKeyH:
            go_to_home(scene, window);
            return;
        case sfKeySpace:
            restart_game(scene, window);
    }
}

void dead_event_input(object_t *object, scene_t *scene,
    window_t *window, set_event_t *event)
{
    player_t *player = NULL;

    if (object == NULL || object->components == NULL ||
            scene == NULL || window == NULL || event == NULL ||
            event->input_key.event_type != KEY) {
        return;
    }
    player = dico_t_get_value(window->components, PLAYER);
    if (player == NULL || player->state != DIE) {
        return;
    }
    handle_dead_key_input(event->input_key.event_code.key, window, scene);
}
