/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** upgrade_stat
*/

#include "my_rpg.h"
#include "my_json.h"

extern const char life_max_name[];
extern const char energy_max_name[];

static void upgrade(window_t *win, const char *stat_max_key)
{
    player_t *player = dico_t_get_value(win->components, "player");
    any_t *stat = NULL;
    any_t *health = NULL;

    if (player == NULL) {
        return;
    }
    stat = dico_t_get_any(player->obj->components, "stats");
    if (stat == NULL) {
        return;
    }
    health = dico_t_get_any(stat->value.dict, stat_max_key);
    if (health == NULL || health->type != FLOAT) {
        return;
    }
    health->value.f *= 1.10;
    if (write_json(stat, PLAYER_STATS) != JS_OK) {
        return;
    }
    printf("UPGRADE HEALTH OR ENERGY BRO\n");
    return;
}

void upgrade_energy(object_t *obj, scene_t *scene,
    window_t *win, set_event_t *event)
{
    if (win == NULL) {
        return;
    }
    upgrade(win, energy_max_name);
}

void upgrade_health(object_t *obj, scene_t *scene,
    window_t *win, set_event_t *event)
{
    if (win == NULL) {
        return;
    }
    upgrade(win, life_max_name);
}