/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** life_hud
*/

#include "my_bgs.h"
#include "my_json.h"
#include "my_rpg.h"

int update_life_stats(object_t *obj, player_t *player, any_t *stats)
{
    any_t *max_life_data = NULL;
    int max_life = 0;

    if (player == NULL) {
        return RET_ERR_INPUT;
    }
    max_life_data = dico_t_get_value(stats->value.dict, "max_life");
    if (max_life_data != NULL || max_life_data->type != INT) {
        return RET_ERR_INPUT;
    }
    max_life = max_life_data->value.i;
    obj->bigdata.sprite_bigdata.rect.top =
        obj->bigdata.sprite_bigdata.rect.top - player.
}

void update_life_hud(object_t *object, window_t *win,
    scene_t *scene, float time)
{
    player_t *player = NULL;
    any_t *stats = NULL;

    if (object == NULL || win == NULL || scene == NULL) {
        return RET_ERR_INPUT;
    }
    player = dico_t_get_value(win->components, "player");
    if (player == NULL) {
        return RET_ERR_INPUT;
    }
    stats = dico_t_get_value(player->obj->components, "stats");
    if (stats == NULL || stats->type != DICT) {
        return RET_ERR_INPUT;
    }
}

int init_life_hud(window_t *win, scene_t *scene)
{
    object_t *life_hud = NULL;

    if (win == NULL || scene == NULL) {
        return RET_ERR_INPUT;
    }
    life_hud = create_object(NULL, NULL, scene, -2);
}