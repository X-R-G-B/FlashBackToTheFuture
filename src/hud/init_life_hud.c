/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** life_hud
*/

#include "my_bgs.h"
#include "my_json.h"
#include "my_rpg.h"
#include "macro.h"

static const char life_hud_path[] = "./assets/image/hud/life_bar.png";
static const sfIntRect life_hud_rec = {0, 0, 60, 188};
const sfVector2f life_hud_pos = {285, 50};
extern const char life_max_name[];

void update_life_hud(object_t *object, scene_t *scene,
    window_t *win, __attribute__((unused)) float time)
{
    player_t *player = NULL;
    static float prev_stat_value = -1;
    static float prev_max_stat_value = -1;

    if (object == NULL || win == NULL || scene == NULL) {
        return;
    }
    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL || (player->life == prev_stat_value &&
            check_evolution_stat(player, &prev_max_stat_value,
            life_max_name) == false) ||
            (player->life <= 0 && prev_stat_value <= 0)) {
        return;
    }
    if (player->life <= 0) {
        player->life = 0;
    }
    prev_stat_value = player->life;
    update_hud_stats(object, player, life_max_name, player->life);
}

static int create_life_hud(object_t **life_hud, player_t **player,
    scene_t *scene, window_t *win)
{
    *life_hud = create_object(update_life_hud, NULL, scene, LAYER_HUD);
    *player = dico_t_get_value(win->components, PLAYER);
    if (*life_hud == NULL || *player == NULL) {
        return RET_ERR_MALLOC;
    }
    if (object_set_sprite(*life_hud, life_hud_path,
            life_hud_rec, life_hud_pos) != BGS_OK) {
        return RET_ERR_INPUT;
    }
    return RET_OK;
}

int init_life_hud(window_t *win, scene_t *scene)
{
    object_t *life_hud = NULL;
    player_t *player = NULL;

    if (win == NULL || scene == NULL) {
        return RET_ERR_INPUT;
    }
    if (create_life_hud(&life_hud, &player, scene, win) != RET_OK) {
        return RET_ERR_INPUT;
    }
    if (add_hud_to_hud_element(win, life_hud, player) != RET_OK) {
        return RET_ERR_INPUT;
    }
    if (update_hud_stats(life_hud, player, life_max_name,
            player->life) != RET_OK) {
        return RET_ERR_INPUT;
    }
    return RET_OK;
}
