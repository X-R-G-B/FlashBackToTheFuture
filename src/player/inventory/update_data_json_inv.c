/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** update_data_json_inv
*/

#include "my_json.h"
#include "my_rpg.h"
#include "audio.h"
#include "player.h"

extern const char stats_path_key[];

any_t *get_player_stats(window_t *win)
{
    player_t *player = NULL;

    if (win == NULL) {
        return NULL;
    }
    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL) {
        return NULL;
    }
    return dico_t_get_any(player->obj->components, PLAYER_STATS);
}

void get_potions(window_t *win)
{
    any_t *json = NULL;
    any_t *potions = NULL;
    player_t *player = NULL;

    if (win == NULL) {
        return;
    }
    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL) {
        return;
    }
    json = dico_t_get_value(player->obj->components, PLAYER_STATS);
    potions = get_from_any(json, "d", POTIONS);
    if (potions == NULL || potions->type != INT) {
        return;
    }
    potions->value.i += 1;
    write_json(json, dico_t_get_value(player->obj->components, stats_path_key));
}

void get_infinity_86(window_t *win)
{
    any_t *json = NULL;
    any_t *key_obj = NULL;
    player_t *player = (win != NULL) ?
        dico_t_get_value(win->components, PLAYER) : NULL;

    if (player == NULL || player->obj == NULL) {
        return;
    }
    json = dico_t_get_value(player->obj->components, PLAYER_STATS);
    key_obj = get_from_any(json, "d", INFINITY_86);
    if (key_obj == NULL || key_obj->type != INT) {
        return;
    }
    level_up(dico_t_get_value(win->scenes, win->current_scene), win);
    key_obj->value.i += 1;
    write_json(json, dico_t_get_value(player->obj->components,
        stats_path_key));
    play_sound(win, INFINITY_86_SOUND);
}
