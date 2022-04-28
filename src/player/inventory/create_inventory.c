/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** create_inventory
*/

#include "my_rpg.h"
#include "my_bgs_components.h"

static int create_open_inv_event(player_t *player)
{
    set_event_t *invopen = NULL;
    object_t *obj = NULL;

    if (player == NULL) {
        return RET_ERR_INPUT;
    }
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
    set_event_t *invclose = NULL;
    object_t *obj = NULL;

    obj = create_object(NULL, NULL, scene, 0);
    if (obj == NULL) {
        return RET_ERR_INPUT;
    }
    if (object_set_custom(obj) != BGS_OK) {
        return RET_ERR_MALLOC;
    }
    invclose = create_event(NULL, NULL, obj,
        close_inventory);
    if (invclose == NULL || event_add_node(invclose,
        (node_params_t) {sfMouseLeft, sfKeyEscape, KEY}) != BGS_OK) {
        return RET_ERR_MALLOC;
    }
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
    scene = create_scene(win, sfBlue, INV_SCENE);
    player = dico_t_get_value(win->components, PLAYER);
    if (scene == NULL || player == NULL) {
        return RET_ERR_MALLOC;
    }
    if (create_inventory_key(player, scene) != RET_OK) {
        return RET_ERR_INPUT;
    }
    return RET_OK;
}
