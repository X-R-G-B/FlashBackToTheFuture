/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** init_xp_hud
*/

#include "my_bgs.h"
#include "my_rpg.h"
#include "macro.h"

static const char xp_hud_borders_sprite_path[] =
    "./assets/image/hud/xp_bar_border.png";
static const sfIntRect xp_hud_borders_rect = {-1, -1, -1, -1};
static const sfVector2f xp_hud_borders_pos = {960.0, 960.0};
static const char xp_hud_bar_sprite_path[] =
    "./assets/image/hud/xp_bar.png";
static const sfIntRect xp_hud_bar_rect = {-1, -1, -1, -1};
static const sfVector2f xp_hud_bar_pos = {976.6, 958.5};

static int init_xp_borders_hud(window_t *win, scene_t *scene, player_t *player)
{
    object_t *xp_hud_borders = NULL;

    xp_hud_borders = create_object(NULL, NULL, scene, LAYER_HUD);
    if (xp_hud_borders == NULL) {
        return RET_ERR_INPUT;
    }
    if (object_set_sprite(xp_hud_borders, xp_hud_borders_sprite_path,
            xp_hud_borders_rect ,xp_hud_borders_pos) != BGS_OK) {
        return RET_ERR_INPUT;
    }
    if (add_hud_to_hud_element(win, xp_hud_borders, player) != RET_OK) {
        return RET_ERR_INPUT;
    }
    return RET_OK;
}

static int init_xp_bar_hud(window_t *win, scene_t *scene, player_t *player)
{
    object_t *xp_hud_bar = NULL;

    xp_hud_bar = create_object(update_xp_bar, NULL, scene, LAYER_HUD);
    if (xp_hud_bar == NULL) {
        return RET_ERR_INPUT;
    }
    if (object_set_sprite(xp_hud_bar, xp_hud_bar_sprite_path,
            xp_hud_bar_rect ,xp_hud_bar_pos) != BGS_OK) {
        return RET_ERR_INPUT;
    }
    if (add_hud_to_hud_element(win, xp_hud_bar, player) != RET_OK) {
        return RET_ERR_INPUT;
    }
    return RET_OK;
}

int init_xp_hud(window_t *win, scene_t *scene)
{
    player_t *player = NULL;

    if (win == NULL || win->components == NULL || scene == NULL) {
        return RET_ERR_INPUT;
    }
    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL) {
        return RET_ERR_INPUT;
    }
    if (init_xp_borders_hud(win, scene, player) != RET_OK) {
        return RET_ERR_INPUT;
    }
    if (init_xp_bar_hud(win, scene, player) != RET_OK) {
        return RET_ERR_INPUT;
    }
    return RET_OK;
}