/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** update ennemy move
*/

#include <stdbool.h>
#include <stdlib.h>
#include "ennemies.h"
#include "ennemy_pathfind.h"
#include "my_rpg.h"

static const char rect_actualisation[] = "rect actualisation";
static const char speed[] = "speed";
static const char move_dict[] = "move";

int get_data(any_t **rect_speed, any_t **move_speed, any_t *data,
    any_t **rect_list)
{
    if (data == NULL) {
        return RET_ERR_INPUT;
    }
    *rect_speed = get_from_any(data, "d", rect_actualisation);
    *move_speed = get_from_any(data, "d", speed);
    *rect_list = get_from_any(data, "da", move_dict, 0);
    if (*rect_speed == NULL || (*rect_speed)->type != FLOAT ||
        *move_speed == NULL || (*move_speed)->type != FLOAT ||
        *rect_list == NULL || (*rect_list)->type != ARRAY) {
        return RET_ERR_INPUT;
    }
    return RET_OK;
}

void set_new_data(ennemy_t *ennemy, float move, int *rect)
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

static bool set_new_dir(ennemy_t *ennemy, scene_t *scene, window_t *win)
{
    if (ennemy == NULL || scene == NULL || win == NULL || ennemy->obj == NULL) {
        return (false);
    }
    ennemy->dir = get_path_find_dir(ennemy->obj, scene);
    if (ennemy->dir == UNKNOWN_STATE) {
        ennemy->dir = UP;
    }
    if (check_is_dashing(ennemy, win) == true) {
        ennemy->state = ATTACKING;
    }
    return (true);
}

static void cross_time(any_t *rect_speed, ennemy_t *ennemy, any_t *rect_list)
{
    for (; ennemy->move_delta_time >= rect_speed->value.f;
        ennemy->move_delta_time -= rect_speed->value.f) {
        ennemy->rect_id += 1;
        if (ennemy->rect_id >= rect_list->value.array->len) {
            ennemy->rect_id = 0;
        }
    }
}

void update_ennemy_move(ennemy_t *ennemy, scene_t *scene, window_t *win,
    float time)
{
    any_t *rect_speed = NULL;
    any_t *move_speed = NULL;
    any_t *rect_list = NULL;
    any_t *data = dico_t_get_any((ennemy == NULL || ennemy->obj == NULL) ?
        NULL : ennemy->obj->components, ENNEMY_DATA);

    return;
    if (get_data(&rect_speed, &move_speed, data, &rect_list) != RET_OK ||
        set_new_dir(ennemy, scene, win) == false) {
        return;
    }
    ennemy->move_delta_time += time;
    cross_time(rect_speed, ennemy, rect_list);
    set_new_data(ennemy, time * move_speed->value.f,
        get_rect(ennemy, win, data));
    if (is_player_in_range(ennemy, win) == false) {
        ennemy->rect_id = 0;
        ennemy_set_stop(ennemy);
    }
}
