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
    inv_data = dico_t_get_value(win->components, SAVE);
    potions = get_from_any(inv_data, "d", POTIONS);
    if (potions == NULL) {
        return;
    }
    potions->value.i -= 1;
    write_json(inv_data, STORY_DATA_PATH);
}

static float get_max_life(player_t *player)
{
    any_t *player_stats = NULL;
    any_t *max_life = NULL;

    if (player == NULL || player->obj == NULL
        || player->obj->components == NULL) {
        return RET_ERR_INPUT;
    }
    player_stats = dico_t_get_any(player->obj->components, PLAYER_STATS);
    max_life = get_from_any(player_stats, "d", MAX_LIFE);
    if (max_life == NULL) {
        return RET_ERR_MALLOC;
    }
    return max_life->value.f;
}

static void is_above_max_health(player_t *player, float max_life)
{
    if (player->life >= max_life) {
        player->life = max_life;
    }
}

void heal(window_t *win)
{
    player_t *player = NULL;
    float max_life = 0;

    if (win == NULL) {
        return;
    }
    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL || player->obj == NULL) {
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
    is_above_max_health(player, max_life);
}
