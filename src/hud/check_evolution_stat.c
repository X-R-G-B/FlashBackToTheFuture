/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** check_evolution_stat
*/

#include "my_json.h"
#include "my_rpg.h"

static any_t *get_stats_of_player(player_t *player, float *prev_max_stat)
{
    any_t *stats = NULL;

    if (player == NULL || prev_max_stat == NULL) {
        return NULL;
    }
    stats = dico_t_get_value(player->obj->components, PLAYER_STATS);
    if (stats == NULL || stats->type != DICT) {
        return NULL;
    }
    return stats;
}

bool check_evolution_stat(player_t *player, float *prev_max_stat,
    const char stat_name[])
{
    any_t *max_stat_data = NULL;
    any_t *stats = NULL;
    float actual_max_stat = -1;

    stats = get_stats_of_player(player, prev_max_stat);
    if (stats == NULL) {
        return false;
    }
    max_stat_data = dico_t_get_value(stats->value.dict, stat_name);
    if (max_stat_data == NULL || max_stat_data->type != FLOAT) {
        return false;
    }
    actual_max_stat = max_stat_data->value.f;
    if (*prev_max_stat != actual_max_stat) {
        *prev_max_stat = actual_max_stat;
        return true;
    }
    return false;
}
