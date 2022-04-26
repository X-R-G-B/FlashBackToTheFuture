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
    *player_stats = dico_t_get_any(player->obj->components, "stats");
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

static int level_up(any_t *player_stats, any_t *ennemy_stats, any_t *xp)
{
    any_t *xp_max = NULL;
    any_t *lvl = NULL;

    if (player_stats == NULL || ennemy_stats == NULL) {
        return RET_ERR_INPUT;
    }
    xp_max = dico_t_get_any(player_stats->value.dict, MAX_XP);
    lvl = dico_t_get_any(player_stats->value.dict, ACTUAL_LVL);
    if (xp_max == NULL || lvl == NULL) {
        return RET_ERR_MALLOC;
    }
    for (; xp_max->value.f <= xp->value.f;) {
        xp->value.f -= xp_max->value.f;
        lvl->value.f += 1.0;
    }
    if (write_json(player_stats, PLAYER_STATS) != JS_OK) {
        return JS_ERR_INPUT;
    }
    return RET_OK;
}

void update_xp(ennemy_t *ennemy, window_t *win)
{
    player_t *player = NULL;
    any_t *player_stats = NULL;
    any_t *ennemy_stats = NULL;
    any_t *xp = NULL;
    any_t *loot_xp = NULL;

    if (init_any_stats(&player_stats, &ennemy_stats, ennemy, win) != RET_OK ||
        init_any_xp(&xp, &loot_xp, ennemy_stats, player_stats) != RET_OK) {
        return;
    }
    xp->value.f += loot_xp->value.f;
    level_up(player_stats, ennemy_stats, xp);
    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL) {
        return;
    }
    player->xp = xp->value.f;
}
