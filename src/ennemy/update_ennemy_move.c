/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** update ennemy move
*/

#include <stdlib.h>
#include "ennemies.h"

static int get_data(any_t **rect_speed, any_t **move_speed, any_t *data,
    any_t **rect_list)
{
    *rect_speed = dico_t_get_any(data->value.dict,
        "rect actualisation");
    *move_speed = dico_t_get_any(data->value.dict, "speed");
    *rect_list = get_from_any(data, "da", "move", 0);
    if (*rect_speed == NULL || (*rect_speed)->type != FLOAT ||
        *move_speed == NULL || (*move_speed)->type != FLOAT ||
        *rect_list == NULL || (*rect_list)->type != ARRAY) {
        return RET_ERR_INPUT;
    }
    return RET_OK;
}

static void set_new_data(ennemy_t *ennemy, float move, any_t *data, int rect_id)
{
    sfVector2f news[4] = {{0, 0 - move}, {0 - move, 0}, {0, move}, {move, 0}};
    int *rect = get_any_int_array(get_from_any(data, "daa", "move", ennemy->dir,
        rect_id));

    ennemy->obj->bigdata.sprite_bigdata.pos.x += news[ennemy->dir].x;
    ennemy->obj->bigdata.sprite_bigdata.pos.y += news[ennemy->dir].y;
    if (rect == NULL) {
        return;
    }
    ennemy->obj->bigdata.sprite_bigdata.rect = (sfIntRect) {rect[0], rect[1],
        rect[2], rect[3]};
    free(rect);
}

static void check_next_move(ennemy_t *ennemy, window_t *win)
{
    dir_t prev_dir = ennemy->dir;

    if (is_player_in_range(ennemy, win) == true) {
        ennemy->dir = get_new_dir(ennemy->obj, win);
        if (prev_dir != RIGHT && ennemy->dir == RIGHT) {
            sfSprite_setScale(ennemy->obj->drawable.sprite,
                (sfVector2f) {-1, 1});
        } else if (prev_dir == RIGHT && ennemy->dir != RIGHT) {
            sfSprite_setScale(ennemy->obj->drawable.sprite,
                (sfVector2f) {1, 1});
        }
    } else {
        ennemy_set_stop(ennemy);
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

    if (data == NULL ||
        get_data(&rect_speed, &move_speed, data, &rect_list) != RET_OK) {
        return;
    }
    for (dtime += time; dtime >= rect_speed->value.f;
        dtime -= rect_speed->value.f) {
        rect_id += 1;
        if (rect_id >= rect_list->value.array->len) {
            rect_id = 0;
        }
    }
    set_new_data(ennemy, time * move_speed->value.f, data, rect_id);
    check_next_move(ennemy, win);
}
