/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** set_player_default_stats
*/

#include "my_json.h"
#include "my_rpg.h"

static int set_default_life(player_t *player, any_t *stats)
{
    any_t *life = NULL;

    if (stats == NULL || stats->type != DICT) {
        return RET_ERR_INPUT;
    }
    life = dico_t_get_value(stats->value.dict, "max_life");
    if (life == NULL || life->type != FLOAT) {
        return RET_ERR_INPUT;
    }
    player->life = life->value.f;
    return RET_OK;
}

static int set_default_energy(player_t *player, any_t *stats)
{
    any_t *energy = NULL;

    if (stats == NULL || stats->type != DICT) {
        return RET_ERR_INPUT;
    }
    energy = dico_t_get_value(stats->value.dict, "max_energy");
    if (energy == NULL || energy->type != FLOAT) {
        return RET_ERR_INPUT;
    }
    player->energy = energy->value.f;
    return RET_OK;
}

int set_player_default_stats(player_t *player, any_t *stats)
{
    if (player == NULL || stats == NULL) {
        return RET_ERR_INPUT;
    }
    if (set_default_life(player, stats) != RET_OK ||
        set_default_energy(player, stats) != RET_OK) {
            return RET_ERR_INPUT;
    }
    return RET_OK;
}
