/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** energy_hud
*/

#include "my_bgs.h"
#include "my_json.h"
#include "my_rpg.h"
#include "macro.h"

static const char energy_hud_path[] = "./assets/image/hud/energy_bar.png";
static const sfIntRect energy_hud_rect = {0, 0, 60, 188};
const sfVector2f energy_hud_pos = {113, 50};
extern const char energy_max_name[];

static void retake_energy(float time_elapsed, player_t *player)
{
    any_t *max_stat_data = NULL;
    any_t *stats = NULL;
    static float time = 0;

    stats = dico_t_get_value(player->obj->components, PLAYER_STATS);
    if (stats == NULL || stats->type != DICT) {
        return;
    }
    max_stat_data = dico_t_get_value(stats->value.dict, energy_max_name);
    if (max_stat_data == NULL || max_stat_data->type != FLOAT ||
            player->energy + 5 > max_stat_data->value.f) {
        return;
    }
    time += time_elapsed;
    for (; time > 0.03; time -= 0.03) {
        player->energy += 5;
    }
    if (player->energy > max_stat_data->value.f) {
        player->energy = max_stat_data->value.f;
    }
}

void update_energy_hud(object_t *object, scene_t *scene,
    window_t *win, float time)
{
    player_t *player = NULL;
    static float prev_stat_value = -1;
    static float prev_max_stat_value = -1;

    if (object == NULL || win == NULL || scene == NULL) {
        return;
    }
    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL) {
        return;
    }
    retake_energy(time, player);
    if ((player->energy == prev_stat_value && check_evolution_stat(player,
            &prev_max_stat_value, energy_max_name) == false) ||
            player->energy < 0) {
        return;
    }
    prev_stat_value = player->energy;
    update_hud_stats(object, player, energy_max_name, player->energy);
}

static int create_energy_hud(object_t **energy_hud, player_t **player,
    scene_t *scene, window_t *win)
{
    *energy_hud = create_object(update_energy_hud, NULL, scene, LAYER_HUD);
    *player = dico_t_get_value(win->components, PLAYER);
    if (*energy_hud == NULL || *player == NULL) {
        return RET_ERR_MALLOC;
    }
    if (object_set_sprite(*energy_hud, energy_hud_path,
            energy_hud_rect, energy_hud_pos) != BGS_OK) {
        return RET_ERR_INPUT;
    }
    return RET_OK;
}

int init_energy_hud(window_t *win, scene_t *scene)
{
    object_t *energy_hud = NULL;
    player_t *player = NULL;

    if (win == NULL || scene == NULL) {
        return RET_ERR_INPUT;
    }
    if (create_energy_hud(&energy_hud, &player, scene, win) != RET_OK) {
        return RET_ERR_INPUT;
    }
    if (add_hud_to_hud_element(win, energy_hud, player) != RET_OK) {
        return RET_ERR_INPUT;
    }
    if (update_hud_stats(energy_hud, player, energy_max_name,
            player->energy) != RET_OK) {
        return RET_ERR_INPUT;
    }
    return RET_OK;
}
