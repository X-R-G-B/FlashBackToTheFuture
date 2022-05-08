/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** hud_management
*/

#include "my_json.h"
#include "my_bgs.h"
#include "my_macro.h"
#include "my_rpg.h"
#include "macro.h"
#include "stage.h"

static const char head_with_borders_path[] =
    "./assets/image/hud/head_with_borders.png";
static const sfIntRect head_with_borders_rect = {-1, -1, -1, -1};
static const sfVector2f head_with_borders_pos = {200, 143};

static void change_stat_hud(object_t *obj, player_t *player,
    any_t *max_stat_data, float stat_value)
{
    sfVector2u size = {0};
    sfVector2f view = {0};
    float max_stat = 0;

    max_stat = max_stat_data->value.f;
    size = sfTexture_getSize(obj->bigdata.sprite_bigdata.texture);
    view = sfView_getCenter(player->view);
    obj->bigdata.sprite_bigdata.rect.top =
        size.y - stat_value * (float) size.y / max_stat;
    obj->bigdata.sprite_bigdata.rect.height =
        ABSOL(stat_value * (float) size.y / max_stat);
    obj->bigdata.sprite_bigdata.pos.y =
        (view.y - WIN_SIZE_Y / 2.0 + 50) +
        sfSprite_getOrigin(obj->drawable.sprite).y +
        (size.y - stat_value * (float) size.y / max_stat);
}

int update_hud_stats(object_t *obj, player_t *player, const char stat_name[],
    float stat_value)
{
    any_t *max_stat_data = NULL;
    any_t *stats = NULL;

    if (obj == NULL || player == NULL || player->obj == NULL) {
        return RET_ERR_INPUT;
    }
    stats = dico_t_get_value(player->obj->components, PLAYER_STATS);
    if (stats == NULL || stats->type != DICT) {
        return RET_ERR_INPUT;
    }
    max_stat_data = dico_t_get_value(stats->value.dict, stat_name);
    if (max_stat_data == NULL || max_stat_data->type != FLOAT) {
        return RET_ERR_INPUT;
    }
    change_stat_hud(obj, player, max_stat_data, stat_value);
    return RET_OK;
}

int add_hud_to_hud_element(window_t *win, object_t *hud_data, player_t *player)
{
    list_ptr_t *hud_elements = NULL;

    if (win == NULL || win->components == NULL ||
        hud_data == NULL || player == NULL) {
        return RET_ERR_INPUT;
    }
    hud_elements = dico_t_get_value(win->components, HUD_ELEMENTS);
    if (hud_elements == NULL) {
        return RET_ERR_INPUT;
    }
    hud_apply_right_pos(hud_data, player->obj);
    list_add_to_end(hud_elements, hud_data);
    return RET_OK;
}

static int init_head_with_border(window_t *win, scene_t *scene)
{
    object_t *head_with_borders = NULL;
    player_t *player = NULL;

    head_with_borders = create_object(NULL, NULL, scene, -2);
    if (head_with_borders == NULL) {
        return RET_ERR_MALLOC;
    }
    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL) {
        return RET_ERR_INPUT;
    }
    if (object_set_sprite(head_with_borders, head_with_borders_path,
        head_with_borders_rect, head_with_borders_pos) != BGS_OK) {
        return RET_ERR_INPUT;
    }
    if (add_hud_to_hud_element(win, head_with_borders, player) != RET_OK) {
        return RET_ERR_INPUT;
    }
    return RET_OK;
}

int init_hud(window_t *win, scene_t *scene)
{
    if (win == NULL || scene == NULL) {
        return RET_ERR_INPUT;
    }
    if (init_life_hud(win, scene) != RET_OK ||
            init_energy_hud(win, scene) != RET_OK ||
            init_head_with_border(win, scene) != RET_OK ||
            init_xp_hud(win, scene) != RET_OK) {
        return RET_ERR_INPUT;
    }
    return RET_OK;
}
