/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** upgrade_stat
*/

#include "my_rpg.h"
#include "my_json.h"
#include "my_strings.h"
#include "player.h"
#include "main_menu.h"

extern const char life_max_name[];
extern const char energy_max_name[];
extern const char stats_path_key[];

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

    if (player == NULL || player->obj == NULL) {
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
    elem->value.f = (int) (elem->value.f * 1.1);
    upgrade_dammage(stat);
    write_json(stat, dico_t_get_value(player->obj->components, stats_path_key));
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
    if (scene->pause == false) {
        toggle_pop_up(win->components, STATS_UPGRADE_KEY);
    }
    player->state = IN_POP_UP;
    scene->pause = true;
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
    if (check_if_pop_up_true(win->components, STATS_UPGRADE_KEY) == 1) {
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
    if (check_if_pop_up_true(win->components, STATS_UPGRADE_KEY) == 1) {
        upgrade(win, life_max_name);
        set_stat_max(player, life_max_name);
    }
}
