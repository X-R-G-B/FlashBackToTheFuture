/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** gain_xp
*/

#include "my_rpg.h"
#include "ennemies.h"

const char XP[] = "actual xp";
const char LOOT_XP[] = "xp loot";
const char MAX_XP[] = "xp max";
const char ACTUAL_LVL[] = "actual lvl";
extern const char stats_path_key[];

static int init_any_stats(any_t **player_stats, any_t **ennemy_stats,
    ennemy_t *ennemy, window_t *win)
{
    player_t *player = NULL;

    if (ennemy == NULL || win == NULL) {
        return RET_ERR_INPUT;
    }
    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL) {
        return RET_ERR_MALLOC;
    }
    *player_stats = dico_t_get_any(player->obj->components, PLAYER_STATS);
    *ennemy_stats = dico_t_get_any(ennemy->obj->components, ENNEMY_DATA);
    if (*player_stats == NULL || *ennemy_stats == NULL) {
        return RET_ERR_INPUT;
    }
    return RET_OK;
}

static int init_any_xp(any_t **xp, any_t **loot_xp,
    any_t *ennemy_stats, any_t *player_stats)
{
    if (player_stats == NULL || ennemy_stats == NULL) {
        return RET_ERR_INPUT;
    }
    *xp = dico_t_get_any(player_stats->value.dict, XP);
    *loot_xp = dico_t_get_any(ennemy_stats->value.dict, LOOT_XP);
    if (*xp == NULL || *loot_xp == NULL) {
        return RET_ERR_MALLOC;
    }
    return RET_OK;
}

static int update_stats(any_t *player_stats, any_t *xp, any_t *xp_max,
    int *lvl_gained)
{
    any_t *lvl = NULL;

    if (player_stats == NULL || xp == NULL || xp_max == NULL) {
        return RET_ERR_INPUT;
    }
    lvl = dico_t_get_any(player_stats->value.dict, ACTUAL_LVL);
    if (lvl == NULL) {
        return RET_ERR_MALLOC;
    }
    for (; xp_max->value.f <= xp->value.f; (*lvl_gained)++) {
        xp->value.f -= xp_max->value.f;
        lvl->value.f += 1.0;
        xp_max->value.f *= 1.2;
    }
    return RET_OK;
}

static int gain_xp(any_t *player_stats, any_t *ennemy_stats, any_t *xp,
    player_t *player)
{
    any_t *xp_max = NULL;
    int lvl_gained = 0;

    if (player_stats == NULL || ennemy_stats == NULL || player == NULL ||
            player->obj == NULL) {
        return RET_ERR_INPUT;
    }
    xp_max = dico_t_get_any(player_stats->value.dict, MAX_XP);
    if (xp_max == NULL) {
        return RET_ERR_MALLOC;
    }
    if (update_stats(player_stats, xp, xp_max, &lvl_gained) != RET_OK ||
            write_json(player_stats, dico_t_get_value(player->obj->components,
            stats_path_key)) != JS_OK) {
        return RET_ERR_MALLOC;
    }
    if (lvl_gained != 0) {
        return LVL_UP;
    }
    return RET_OK;
}

void update_xp(ennemy_t *ennemy, window_t *win, scene_t *scene)
{
    any_t *player_stats = NULL;
    any_t *ennemy_stats = NULL;
    any_t *xp = NULL;
    any_t *loot_xp = NULL;

    if (win == NULL || ennemy == NULL || scene == NULL ||
        init_any_stats(&player_stats, &ennemy_stats, ennemy, win) != RET_OK ||
        init_any_xp(&xp, &loot_xp, ennemy_stats, player_stats) != RET_OK) {
        return;
    }
    xp->value.f += loot_xp->value.f;
    if (gain_xp(player_stats, ennemy_stats, xp,
            dico_t_get_value(win->components, PLAYER)) == LVL_UP) {
        level_up(scene, win);
        play_sound(win, LEVEL_UP_SOUND);
    }
}
