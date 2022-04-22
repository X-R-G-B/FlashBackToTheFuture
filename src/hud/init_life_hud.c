/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** life_hud
*/

#include "my_bgs.h"
#include "my_json.h"
#include "my_rpg.h"
#include "my_macro.h"

static const char life_hud_path[] = "./assets/image/hud/life_bar.png";
static const sfIntRect life_hud_rec = {0, 0, 60, 188};
static const sfVector2f life_hud_pos = {285, 50};

void update_life_hud(object_t *object, scene_t *scene,
    window_t *win, __attribute__((unused)) float time)
{
    player_t *player = NULL;
    static float prev_stat_value = -1;

    if (object == NULL || win == NULL || scene == NULL) {
        return;
    }
    player = dico_t_get_value(win->components, "player");
    if (player == NULL) {
        return;
    }
    if (player->life == prev_stat_value || player->life < 0) {
        return;
    }
    prev_stat_value = player->life;
    update_hud_stats(object, player, "max_life", player->life);
}

static int set_default_life(player_t *player)
{
    any_t *stats = NULL;
    any_t *life = NULL;

    stats = dico_t_get_value(player->obj->components, "stats");
    if (stats == NULL || stats->type != DICT) {
        return RET_ERR_INPUT;
    }
    life = dico_t_get_value(stats->value.dict, "max_life");
    if (life == NULL || life->type != FLOAT) {
        return RET_ERR_INPUT;
    }
    player->life = life->value.f;
    return RET_OK;
}

static int create_life_hud(object_t **life_hud, player_t **player,
    scene_t *scene, window_t *win)
{
    *life_hud = create_object(update_life_hud, NULL, scene, -2);
    *player = dico_t_get_value(win->components, "player");
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
    if (set_default_life(player) != RET_OK) {
        return RET_ERR_INPUT;
    }
    if (add_hud_to_uid_element(scene, life_hud, player) != RET_OK) {
        return RET_ERR_INPUT;
    }
    return RET_OK;
}
