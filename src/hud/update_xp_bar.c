/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** update_xp_bar
*/

#include "my_bgs.h"
#include "my_rpg.h"
#include "my_macro.h"

const char xp_level_name[] = "actual xp";
const char xp_max_name[] = "xp max";
extern const char xp_max_width_key[];

any_t *get_xp_data(player_t *player, const char data_name[])
{
    any_t *stats = NULL;
    any_t *max_xp_data = NULL;

    if (player == NULL || player->obj == NULL) {
        return NULL;
    }
    stats = dico_t_get_value(player->obj->components, PLAYER_STATS);
    if (stats == NULL || stats->type != DICT) {
        return NULL;
    }
    max_xp_data = dico_t_get_value(stats->value.dict, data_name);
    if (max_xp_data == NULL || max_xp_data->type != FLOAT) {
        return NULL;
    }
    return max_xp_data;
}

static bool is_xp_changed(any_t *actual_xp_data)
{
    static float prev_xp = -1;
    float actual_xp = -1;

    actual_xp = actual_xp_data->value.f;
    if (actual_xp != prev_xp) {
        prev_xp = actual_xp;
        return true;
    }
    return false;
}

static bool is_xp_max_upgraded(any_t *xp_max_data)
{
    static float prev_xp_max = -1;
    float xp_max = -1;

    xp_max = xp_max_data->value.f;
    if (xp_max != prev_xp_max) {
        prev_xp_max = xp_max;
        return true;
    }
    return false;
}

int change_xp_bar_stats(any_t *max_xp_data, any_t *actual_xp_data,
    object_t *object, scene_t *scene)
{
    float actual_xp = 0;
    float max_xp = 0;
    int *max_width = NULL;

    actual_xp = actual_xp_data->value.f;
    max_xp = max_xp_data->value.f;
    max_width = dico_t_get_value(scene->components, xp_max_width_key);
    if (max_width == NULL || actual_xp > max_xp) {
        return RET_ERR_INPUT;
    }
    object->bigdata.sprite_bigdata.rect.width =
        (*max_width / max_xp) * actual_xp;
    return RET_OK;
}

void update_xp_bar(object_t *object, scene_t *scene,
    window_t *window, __attribute__((unused)) float time)
{
    player_t *player = NULL;
    any_t *max_xp = NULL;
    any_t *actual_xp = NULL;

    if (object == NULL || scene == NULL || window == NULL ||
            window->components == NULL) {
        return;
    }
    player = dico_t_get_value(window->components, PLAYER);
    if (player == NULL) {
        return;
    }
    max_xp = get_xp_data(player, xp_max_name);
    actual_xp = get_xp_data(player, xp_level_name);
    if (max_xp == NULL || actual_xp == NULL) {
        return;
    }
    if (is_xp_changed(actual_xp) || is_xp_max_upgraded(max_xp)) {
        change_xp_bar_stats(max_xp, actual_xp, object, scene);
    }
}
