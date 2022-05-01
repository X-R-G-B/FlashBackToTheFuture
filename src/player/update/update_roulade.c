/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** update roulade
*/

#include <stdlib.h>
#include "my_rpg.h"

static const char rect_key[] = "rect";
static const char rect_time_key[] = "rect time";
static const char speed_key[] = "speed";

static void apply_rect(player_t *player, int current_id)
{
    any_t *player_data = dico_t_get_value(player->obj->components, PLAYER_DATA);
    int *rect = get_any_int_array(get_from_any(player_data, "ddaa", roulade_key,
        rect_key, player->dir, current_id));
    any_t *rect_list = get_from_any(player_data, "ddaa", roulade_key, rect_key,
        player->dir, current_id);

    if (rect == NULL || rect_list == NULL || rect_list->type != ARRAY ||
        rect_list->value.array->len != 4) {
        if (rect != NULL) {
            free(rect);
        }
        return;
    }
    player->obj->bigdata.sprite_bigdata.rect = (sfIntRect) {rect[0], rect[1],
        rect[2], rect[3]};
    sfSprite_setOrigin(player->obj->drawable.sprite,
        (sfVector2f) {rect[2] / 2, rect[3] / 2});
    free(rect);
}

static void increment_id(int *current_id, float *time, float dtime,
    player_t *player)
{
    any_t *player_data = dico_t_get_value(player->obj->components,
        PLAYER_DATA);
    any_t *rect_time = get_from_any(player_data, "dd", roulade_key,
        rect_time_key);
    any_t *list = get_from_any(player_data, "dda", roulade_key, rect_key, 1);

    *time += dtime;
    if (rect_time == NULL || rect_time->type != FLOAT || list == NULL ||
        list->type != ARRAY) {
        return;
    }
    while (*time >= rect_time->value.f) {
        *time -= rect_time->value.f;
        *current_id += 1;
        if (*current_id >= list->value.array->len) {
            set_stop(player);
            *current_id = 0;
            *time = 0;
        }
    }
}

static void move_player(player_t *player, window_t *win, float dtime)
{
    any_t *player_data = dico_t_get_value(player->obj->components,
        PLAYER_DATA);
    any_t *speed = get_from_any(player_data, "dd", roulade_key,
        speed_key);

    if (speed == NULL || speed->type != FLOAT) {
        return;
    }
    change_player_pos(player, speed->value.f * dtime, win);
}

void update_roulade(player_t *player, scene_t *scene, window_t *win,
    float dtime)
{
    static float time = 0;
    static int current_id = 0;

    if (player == NULL || player->obj == NULL || scene == NULL || win == NULL) {
        return;
    }
    apply_rect(player, current_id);
    move_player(player, win, dtime);
    increment_id(&current_id, &time, dtime, player);
}
