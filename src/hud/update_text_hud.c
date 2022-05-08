/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** update_text_hux
*/

#include <stdlib.h>
#include "my_conversions.h"
#include "my_bgs.h"
#include "my_rpg.h"

extern const char life_max_name[];
extern const char energy_max_name[];

static void change_text_hud(object_t *obj, any_t *max_stat_data)
{
    char *data_str = NULL;

    if (obj == NULL || obj->type != TEXT ||
            max_stat_data == NULL || max_stat_data->type != FLOAT) {
        return;
    }
    data_str = my_itoa((int) max_stat_data->value.f);
    sfText_setString(obj->drawable.text, data_str);
    free(data_str);
}

int update_text_hud(object_t *obj, player_t *player,
    const char stat_name[], float *stat_value)
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
    *stat_value = max_stat_data->value.f;
    change_text_hud(obj, max_stat_data);
    return RET_OK;
}

void update_energy_text_hud(object_t *object, scene_t *scene,
    window_t *win, __attribute__((unused)) float time)
{
    player_t *player = NULL;
    static float prev_max_stat_value = -1;

    if (object == NULL || win == NULL || scene == NULL) {
        return;
    }
    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL || check_evolution_stat(player,
            &prev_max_stat_value, energy_max_name) == false ||
            (player->life <= 0 && prev_max_stat_value <= 0)) {
        return;
    }
    if (player->energy <= 0) {
        player->energy = 0;
    }
    update_text_hud(object, player, energy_max_name, &prev_max_stat_value);
}

void update_life_text_hud(object_t *object, scene_t *scene,
    window_t *win, __attribute__((unused)) float time)
{
    player_t *player = NULL;
    static float prev_max_stat_value = -1;

    if (object == NULL || win == NULL || scene == NULL) {
        return;
    }
    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL || check_evolution_stat(player,
            &prev_max_stat_value, life_max_name) == false ||
            (player->life <= 0 && prev_max_stat_value <= 0)) {
        return;
    }
    if (player->life <= 0) {
        player->life = 0;
    }
    update_text_hud(object, player, life_max_name, &prev_max_stat_value);
}
