/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** create_inventory
*/

#include "my_rpg.h"
#include "my_bgs_components.h"

static const char INV_BUTTONS[] =
    "./assets/data/player/inventory.json";
static const char THE_86[] =
    "assets/data/player/key_obj.json";
static const int OBJ_LAYER = 0;

static int create_open_inv_event(player_t *player)
{
    set_event_t *invopen = NULL;
    object_t *obj = NULL;

    obj = player->obj;
    if (obj == NULL) {
        return RET_ERR_INPUT;
    }
    invopen = create_event(NULL, NULL, obj, open_inventory);
    if (invopen == NULL || event_add_node(invopen,
    (node_params_t) {sfMouseLeft, sfKeyI, KEY}) != BGS_OK) {
        return RET_ERR_MALLOC;
    }
    return RET_OK;
}

static int create_close_inv_event(scene_t *scene)
{
    object_t *obj = NULL;

    obj = create_object(NULL, NULL, scene, OBJ_LAYER);
    if (object_set_custom(obj) != BGS_OK) {
        return RET_ERR_MALLOC;
    }
    if (event_add_node(create_event(NULL, false, obj,
        close_inventory), (node_params_t) {sfMouseLeft, sfKeyEscape, KEY})
        != BGS_OK) {
        return RET_ERR_MALLOC;
    }
    return RET_OK;
}

static int create_buttons(scene_t *scene)
{
    list_ptr_t *buttons = NULL;
    list_ptr_t *key_obj = NULL;

    if (scene == NULL) {
        return RET_ERR_INPUT;
    }
    buttons = create_button(scene, INV_BUTTONS);
    key_obj = create_button(scene, THE_86);
    if (buttons == NULL || key_obj == NULL) {
        return RET_ERR_MALLOC;
    }
    if (scene_add_components(scene, buttons, INV_BUTTONS_COMP, free_pop_up)
        != BGS_OK || scene_add_components(scene, key_obj, KEY_OBJ, free_pop_up)
        != BGS_OK) {
        return RET_ERR_MALLOC;
    }
    toggle_pop_up(scene->components, KEY_OBJ);
    return RET_OK;
}

static int create_inventory_key(player_t *player, scene_t *scene)
{
    if (player == NULL) {
        return RET_ERR_INPUT;
    }
    if (create_close_inv_event(scene) != RET_OK ||
        create_open_inv_event(player) != RET_OK) {
        return RET_ERR_MALLOC;
    }
    return RET_OK;
}

int create_inventory(window_t *win)
{
    scene_t *scene = NULL;
    player_t *player = NULL;

    if (win == NULL) {
        return RET_ERR_INPUT;
    }
    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL) {
        return RET_ERR_MALLOC;
    }
    scene = create_scene(win, sfWhite, INV_SCENE);
    if (scene == NULL || create_inventory_key(player, scene) != RET_OK ||
        create_buttons(scene) != RET_OK) {
        return RET_ERR_INPUT;
    }
    return RET_OK;
}
