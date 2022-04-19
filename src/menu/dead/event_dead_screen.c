/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** dead_screen_input
*/

#include "my_bgs_components.h"
#include "my_rpg.h"

static void go_to_home_from_dead_screen(object_t *object, scene_t *scene,
    window_t *window, set_event_t *event)
{
    player_t *player = dico_t_get_value(window->components, "player");

    if (player == NULL) {
        return;
    }
    window_change_scene(window, "MAIN MENU");
    list_add_to_end(window->to_remove, scene);
    sfView_setCenter(player->view,
        (sfVector2f) {WIN_SIZE_X / 2, WIN_SIZE_Y / 2});
    sfRenderWindow_setView(window->win, player->view);
    window->components = dico_t_rem(window->components, "player");
    window->components = dico_t_rem(window->components, "pause");
    window->components = dico_t_rem(window->components, "dead_screen");
    window->components = dico_t_rem(window->components, "dead_message");
    window->components = dico_t_rem(window->components, SAVE);
    pressed_button_off(object, scene, window, event);
    list_add_to_end(window->to_remove, scene);
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
    player = dico_t_get_value(window->components, "player");
    if (player == NULL || player->state != DIE) {
        return;
    }
    if (event->input_key.event_code.key == sfKeyQ) {
        sfRenderWindow_close(window->win);
        return;
    }
    if (event->input_key.event_code.key == sfKeyH) {
        go_to_home_from_dead_screen(object, scene, window, event);
        return;
    }
}
