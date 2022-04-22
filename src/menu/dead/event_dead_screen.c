/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** dead_screen_input
*/

#include "my_bgs_components.h"
#include "my_rpg.h"

void dead_event_input(object_t *object, scene_t *scene,
    window_t *window, set_event_t *event)
{
    player_t *player = NULL;

    if (object == NULL || object->components == NULL ||
            scene == NULL || window == NULL || event == NULL ||
            event->input_key.event_type != KEY) {
        return;
    }
    player = dico_t_get_value(window->components, "player");
    if (player == NULL || player->state != DIE) {
        return;
    }
    if (event->input_key.event_code.key == sfKeyQ) {
        sfRenderWindow_close(window->win);
        return;
    }
    if (event->input_key.event_code.key == sfKeyH) {
        go_to_home(scene, window);
        return;
    }
}
