/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** update ennemy move
*/

#include <stdlib.h>
#include "ennemies.h"
#include "ennemy_pathfind.h"

static const char rect_actualisation[] = "rect actualisation";
static const char speed[] = "speed";
static const char scale_data[] = "scale";
static const char move_dict[] = "move";

static int get_data(any_t **rect_speed, any_t **move_speed, any_t *data,
    any_t **rect_list)
{
    if (data == NULL) {
        return RET_ERR_INPUT;
    }
    *rect_speed = dico_t_get_any(data->value.dict, rect_actualisation);
    *move_speed = dico_t_get_any(data->value.dict, speed);
    *rect_list = get_from_any(data, "da", move_dict, 0);
    if (*rect_speed == NULL || (*rect_speed)->type != FLOAT ||
        *move_speed == NULL || (*move_speed)->type != FLOAT ||
        *rect_list == NULL || (*rect_list)->type != ARRAY) {
        return RET_ERR_INPUT;
    }
    return RET_OK;
}

static void set_new_data(ennemy_t *ennemy, float move, int *rect)
{
    sfVector2f news[4] = {{0, 0 - move}, {0 - move, 0}, {0, move}, {move, 0}};

    ennemy->obj->bigdata.sprite_bigdata.pos.x += news[ennemy->dir].x;
    ennemy->obj->bigdata.sprite_bigdata.pos.y += news[ennemy->dir].y;
    if (rect == NULL) {
        return;
    }
    ennemy->obj->bigdata.sprite_bigdata.rect = (sfIntRect) {rect[0], rect[1],
        rect[2], rect[3]};
    free(rect);
}

static void set_new_dir(ennemy_t *ennemy, any_t *ennemy_data, scene_t *scene)
{
    dir_t prev_dir = ennemy->dir;
    any_t *scale = dico_t_get_any(ennemy_data->value.dict, scale_data);
    float scale_value = 1;

    ennemy->dir = get_path_find_dir(ennemy->obj, scene);
    if (scale != NULL && scale->type == FLOAT) {
        scale_value = scale->value.f;
    }
    if (prev_dir != RIGHT && ennemy->dir == RIGHT) {
        sfSprite_setScale(ennemy->obj->drawable.sprite,
            (sfVector2f) {scale_value * -1, scale_value});
    } else if (prev_dir == RIGHT && ennemy->dir != RIGHT) {
        sfSprite_setScale(ennemy->obj->drawable.sprite,
            (sfVector2f) {scale_value, scale_value});
    }
}

static void cross_time(float *dtime, any_t *rect_speed, int *rect_id,
    any_t *rect_list)
{
    for (; *dtime >= rect_speed->value.f;
        *dtime -= rect_speed->value.f) {
        *rect_id += 1;
        if (*rect_id >= rect_list->value.array->len) {
            *rect_id = 0;
        }
    }
}

void update_ennemy_move(ennemy_t *ennemy, scene_t *scene, window_t *win,
    float time)
{
    static int rect_id = 0;
    static float dtime = 0;
    any_t *data = dico_t_get_any(ennemy->obj->components, ENNEMY_DATA);
    any_t *rect_speed = NULL;
    any_t *move_speed = NULL;
    any_t *rect_list = NULL;

    if (get_data(&rect_speed, &move_speed, data, &rect_list) != RET_OK ||
        ennemy == NULL || ennemy->obj == NULL || scene == NULL || win == NULL) {
        return;
    }
    set_new_dir(ennemy, data, scene);
    dtime += time;
    cross_time(&dtime, rect_speed, &rect_id, rect_list);
    set_new_data(ennemy, time * move_speed->value.f,
        get_rect(ennemy, win, data, rect_id));
    if (is_player_in_range(ennemy, win) == false) {
        rect_id = 0;
        ennemy_set_stop(ennemy);
    }
}
