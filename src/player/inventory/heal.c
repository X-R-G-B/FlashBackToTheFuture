/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** heal
*/

#include "my_rpg.h"

static void used_potion(window_t *win)
{
    any_t *inv_data = NULL;
    any_t *potions = NULL;

    if (win == NULL) {
        return;
    }
    inv_data = parse_json_file(DATA_INV);
    if (inv_data == NULL) {
        return;
    }
    potions = dico_t_get_any(inv_data->value.dict, "86 heal");
    if (potions == NULL) {
        return;
    }
    potions->value.i -= 1;
}

static float get_max_life(player_t *player)
{
    any_t *player_stats = NULL;
    any_t *max_life = NULL;

    if (player == NULL) {
        return RET_ERR_INPUT;
    }
    player_stats = dico_t_get_any(player->obj->components, PLAYER_STATS);
    if (player_stats == NULL) {
        return RET_ERR_MALLOC;
    }
    max_life = dico_t_get_any(player_stats->value.dict, "max_life");
    return max_life->value.f;
}

void heal(window_t *win)
{
    player_t *player = NULL;
    float max_life = 0;

    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL || player->obj->components == NULL) {
        return;
    }
    max_life = get_max_life(player);
    if (max_life == RET_ERR_INPUT || max_life == RET_ERR_MALLOC) {
        return;
    }
    if (player->life < max_life) {
        used_potion(win);
    }
    player->life += 100.0;
    if (player->life >= max_life) {
        player->life = max_life;
        return;
    }
}
