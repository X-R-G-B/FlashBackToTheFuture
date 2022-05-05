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
const char can_play_dead_screen[] = "can_play";

const char can_play_dead_screen[] = "can play";

static void set_opacity(object_t *dead_message, object_t *dead_screen)
{
    if (dead_message == NULL || dead_screen == NULL) {
        return;
    }
    sfSprite_setColor(dead_message->drawable.sprite,
        (sfColor) {255, 255, 255, 0});
    sfSprite_setColor(dead_screen->drawable.sprite,
        (sfColor) {255, 255, 255, 0});
    return;
}

static void init_dead_screen_pos(window_t *win)
{
    player_t *player = dico_t_get_value(win->components, PLAYER);
    list_ptr_t *hud_elements = dico_t_get_value(win->components, HUD_ELEMENTS);

    if (player == NULL || hud_elements == NULL) {
        return;
    }
    list_add_to_end(hud_elements,
        dico_t_get_value(win->components, DEAD_MESSAGE));
    list_add_to_end(hud_elements,
        dico_t_get_value(win->components, DEAD_SCREEN));
    hud_apply_right_pos(dico_t_get_value(win->components,
        DEAD_MESSAGE), player->obj);
    hud_apply_right_pos(dico_t_get_value(win->components,
        DEAD_SCREEN), player->obj);
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
<<<<<<< HEAD
    if (scene_add_components(scene, can_play, can_play_dead_screen,
            free) != BGS_OK || window_add_component(win, dead_message,
=======
    if (scene_add_components(scene, can_play,
        can_play_dead_screen, free) != BGS_OK ||
        window_add_component(win, dead_message,
>>>>>>> dev
            DEAD_MESSAGE, NULL) != BGS_OK ||
            window_add_component(win, dead_screen,
            DEAD_SCREEN, NULL) != BGS_OK) {
        return;
    }
    set_opacity(dead_message, dead_screen);
}

static int add_object_to_update_list(scene_t *scene, object_t *dead_screens)
{
    layer_t *tmp_layer = NULL;

    if (scene == NULL || dead_screens == NULL) {
        return RET_ERR_INPUT;
    }
    tmp_layer = get_layer(scene, dead_screens->layer);
    if (tmp_layer == NULL || tmp_layer->updates == NULL) {
        return BGS_ERR_INPUT;
    }
    list_add_to_end(tmp_layer->updates, dead_screens);
    return BGS_OK;
}

int init_dead_menu(window_t *win, scene_t *scene)
{
    object_t *dead_screens[2] = {NULL, NULL};
    list_ptr_t *dead_objects = create_button(scene, dead_screen_path);

    if (win == NULL || dead_objects == NULL) {
        return BGS_ERR_MALLOC;
    }
    for (int i = 0; i < 2; i++) {
        dead_screens[i] = get_element_i_var(dead_objects, i);
        if (dead_screens[i] == NULL) {
            return BGS_ERR_MALLOC;
        }
        dead_screens[i]->update = dead_screen_update[i];
        if (add_object_to_update_list(scene, dead_screens[i]) != BGS_OK) {
            return RET_ERR_INPUT;
        }
    }
    config_input_and_components(win, dead_screens[0], dead_screens[1], scene);
    free_list(dead_objects);
    init_dead_screen_pos(win);
    return RET_OK;
}
