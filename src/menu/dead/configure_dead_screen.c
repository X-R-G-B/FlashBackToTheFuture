/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** configure_dead_screen
*/

#include <stdlib.h>
#include "my_bgs.h"
#include "my_bgs_components.h"
#include "my_rpg.h"

static void configure_color_for_dead_screen(object_t *dead_message,
    object_t *dead_screen)
{
    sfColor color[] = {{0, 0, 0, 0}, {0, 0, 0, 0}};

    dead_message->is_visible = false;
    dead_screen->is_visible = false;
    color[0] = sfSprite_getColor(dead_message->drawable.sprite);
    color[1] = sfSprite_getColor(dead_screen->drawable.sprite);
    color[0].a = 0;
    color[1].a = 0;
    sfSprite_setColor(dead_message->drawable.sprite, color[0]);
    sfSprite_setColor(dead_screen->drawable.sprite, color[1]);
}

//variables' values aren't checked because they have been already checked
void init_dead_screen_pos(list_ptr_t *uid_elements, window_t *win)
{
    player_t *player = NULL;
    sfVector2f screen_pos = {0};

    player = dico_t_get_value(win->components, "player");
    if (player == NULL) {
        return;
    }
    screen_pos = (sfVector2f) {
        player->obj->bigdata.sprite_bigdata.pos.x - WIN_SIZE_X / 2,
        player->obj->bigdata.sprite_bigdata.pos.y - WIN_SIZE_Y / 2
    };
    list_add_to_end(uid_elements,
        dico_t_get_value(win->components, "dead_message"));
    list_add_to_end(uid_elements,
        dico_t_get_value(win->components, "dead_screen"));
    uid_apply_right_pos(dico_t_get_value(win->components,
        "dead_message"), screen_pos);
    uid_apply_right_pos(dico_t_get_value(win->components,
        "dead_screen"), screen_pos);
}

static void config_input_and_componets(window_t *win,
    object_t *dead_message, object_t *dead_screen, scene_t *scene)
{
    bool *can_play = malloc(sizeof(bool));

    *can_play = false;
    if (event_add_node(create_event(dead_event_input, false, dead_message,
            NULL), (node_params_t) {sfMouseLeft, sfKeyQ, KEY}) != BGS_OK ||
        event_add_node(create_event(dead_event_input, false, dead_message,
            NULL), (node_params_t) {sfMouseLeft, sfKeyH, KEY}) != BGS_OK) {
        return;
    }
    configure_color_for_dead_screen(dead_message, dead_screen);
    if (scene_add_components(scene, can_play, "can_play", free) ||
        window_add_component(win, dead_message,
            "dead_message", NULL) != BGS_OK ||
        window_add_component(win, dead_screen,
            "dead_screen", NULL) != BGS_OK) {
        return;
    }
}

int init_dead_menu(window_t *win, scene_t *scene)
{
    object_t *dead_message =
        create_object(update_dead_message, NULL, scene, -3);
    object_t *dead_screen = create_object(update_dead_screen, NULL, scene, - 3);

    if (dead_message == NULL || dead_screen == NULL ||
        object_set_sprite(dead_message,
        "./assets/image/menu/dead/dead_message.png",
        (sfIntRect) {0, 0, 1920, 261}, (sfVector2f) {960, 410}) != BGS_OK ||
        object_set_sprite(dead_screen,
        "./assets/image/menu/dead/dead_screen.png",
        (sfIntRect) {0, 0, 1920, 1080}, (sfVector2f) {960, 540}) != BGS_OK) {
        return RET_ERR_INPUT;
    }
    config_input_and_componets(win, dead_message, dead_screen, scene);
    return RET_OK;
}
