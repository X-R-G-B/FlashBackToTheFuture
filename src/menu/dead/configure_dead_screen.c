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

static const char dead_screen_path[] = "./assets/data/menu/dead_screen.json";
static void (*dead_screen_update[2])(object_t *, scene_t *,
    window_t *, float) = {update_dead_message, update_dead_screen};

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

static void config_input_and_components(window_t *win,
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
    dead_message->is_visible = false;
    dead_screen->is_visible = false;
    if (scene_add_components(scene, can_play, "can_play", free) != BGS_OK ||
        window_add_component(win, dead_message,
            "dead_message", NULL) != BGS_OK ||
        window_add_component(win, dead_screen,
            "dead_screen", NULL) != BGS_OK) {
        return;
    }
}

int init_dead_menu(window_t *win, scene_t *scene)
{
    object_t *dead_screens[2] = {NULL, NULL};
    list_ptr_t *dead_objects = create_button(scene, dead_screen_path);
    layer_t *tmp_layer = NULL;

    if (dead_objects == NULL) {
        return BGS_ERR_MALLOC;
    }
    for (int i = 0; i < 2; i++) {
        dead_screens[i] = get_element_i_var(dead_objects, i);
        if (dead_screens[i] == NULL) {
            return BGS_ERR_MALLOC;
        }
        dead_screens[i]->update = dead_screen_update[i];
        tmp_layer = get_layer(scene, dead_screens[i]->layer);
        list_add_to_end(tmp_layer->updates, dead_screens[i]);
    }
    config_input_and_components(win, dead_screens[0], dead_screens[1], scene);
    return RET_OK;
}
