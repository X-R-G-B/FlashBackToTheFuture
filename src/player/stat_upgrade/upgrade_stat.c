/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** upgrade_stat
*/

#include "my_rpg.h"
#include "my_json.h"
#include "my_strings.h"

extern const char life_max_name[];
extern const char energy_max_name[];

static void set_stat_max(player_t *player, const char *stat_max_key)
{
    any_t *stat = NULL;

    if (player->obj == NULL) {
        return;
    }
    stat = dico_t_get_any(player->obj->components, PLAYER_STATS);
    stat = get_from_any(stat, "d", stat_max_key);
    if (stat == NULL) {
        return;
    }
    if (!my_strcmp(stat_max_key, life_max_name)) {
        player->life = stat->value.f;
    }
    if (!my_strcmp(stat_max_key, energy_max_name)) {
        player->energy = stat->value.f;
    }
}

static void upgrade(window_t *win, const char *stat_max_key)
{
    player_t *player = dico_t_get_value(win->components, PLAYER);
    any_t *stat = NULL;
    any_t *elem = NULL;

    if (player == NULL) {
        return;
    }
    stat = dico_t_get_any(player->obj->components, PLAYER_STATS);
    if (stat == NULL) {
        return;
    }
    elem = dico_t_get_any(stat->value.dict, stat_max_key);
    if (elem == NULL || elem->type != FLOAT) {
        return;
    }
    elem->value.f *= 1.10;
    upgrade_dammage(stat);
    if (write_json(stat, PLAYER_STATS_PATH) != JS_OK) {
        return;
    }
}

void level_up(scene_t *scene, window_t *win)
{
    player_t *player = NULL;

    if (win == NULL || scene == NULL) {
        return;
    }
    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL) {
        return;
    }
    player->state = IN_POP_UP;
    scene->pause = true;
    toggle_pop_up(scene->components, STATS_UPGRADE_KEY);
}

void upgrade_energy(__attribute__((unused)) object_t *obj,
    scene_t *scene,
    window_t *win, __attribute__((unused)) set_event_t *event)
{
    player_t *player = NULL;

    if (win == NULL || scene == NULL) {
        return;
    }
    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL) {
        return;
    }
    player->state = STOP;
    scene->pause = false;
    if (check_if_pop_up_true(scene->components, STATS_UPGRADE_KEY) == 1) {
        upgrade(win, energy_max_name);
        set_stat_max(player, energy_max_name);
    }
}

void upgrade_health(__attribute__((unused)) object_t *obj,
    __attribute__((unused)) scene_t *scene,
    window_t *win, __attribute__((unused)) set_event_t *event)
{
    player_t *player = NULL;

    if (win == NULL || scene == NULL) {
        return;
    }
    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL) {
        return;
    }
    player->state = STOP;
    scene->pause = false;
    if (check_if_pop_up_true(scene->components, STATS_UPGRADE_KEY) == 1) {
        upgrade(win, life_max_name);
        set_stat_max(player, life_max_name);
    }
}
