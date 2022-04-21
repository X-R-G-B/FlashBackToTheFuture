/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** life_hud
*/

#include "my_bgs.h"
#include "my_json.h"
#include "my_rpg.h"

static int update_life_stats(object_t *obj, player_t *player, any_t *stats)
{
    any_t *max_life_data = NULL;
    static float prev_life = -1;
    float max_life = 0;
    float coef = 0;

    if (player == NULL) {
        return RET_ERR_INPUT;
    }
    if (player->life == prev_life) {
        return RET_OK;
    }
    max_life_data = dico_t_get_value(stats->value.dict, "max_life");
    if (max_life_data != NULL || max_life_data->type != FLOAT) {
        return RET_ERR_INPUT;
    }
    coef = obj->bigdata.sprite_bigdata.rect.height / max_life;
    max_life = max_life_data->value.i;
    obj->bigdata.sprite_bigdata.rect.top =
        obj->bigdata.sprite_bigdata.rect.top - (max_life - player->life) * coef;
    prev_life = player->life;
    return RET_OK;
}

void update_life_hud(object_t *object, scene_t *scene,
    window_t *win, float time)
{
    player_t *player = NULL;
    any_t *stats = NULL;

    if (object == NULL || win == NULL || scene == NULL) {
        return;
    }
    player = dico_t_get_value(win->components, "player");
    if (player == NULL) {
        return;
    }
    stats = dico_t_get_value(player->obj->components, "stats");
    if (stats == NULL || stats->type != DICT) {
        return;
    }
    update_life_stats(object, player, stats);
}

int init_life_hud(window_t *win, scene_t *scene)
{
    object_t *life_hud = NULL;
    any_t *life = NULL;
    player_t *player = NULL;
    any_t *stats = NULL;

    if (win == NULL || scene == NULL) {
        return RET_ERR_INPUT;
    }
    life_hud = create_object(NULL, NULL, scene, -3);
    player = dico_t_get_value(win->components, "player");
    if (life_hud == NULL || player == NULL) {
        return RET_ERR_MALLOC;
    }
    if (object_set_sprite(life_hud, "./assets/image/hud/life_bar.png",
            (sfIntRect) {-1, -1, -1, -1}, (sfVector2f) {100, 100}) != BGS_OK) {
        return RET_ERR_INPUT;
    }
    stats = dico_t_get_value(player->obj->components, "stats");
    if (stats == NULL || stats->type != DICT) {
        return RET_ERR_INPUT;
    }
    life = dico_t_get_value(stats->value.dict, "max_life");
    if (life == NULL || life->type != FLOAT) {
        return RET_ERR_INPUT;
    }
    player->life = life->value.f;
    printf("ca a init le life hud\n");
    return RET_OK;
}