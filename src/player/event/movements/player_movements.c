/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** player_movements
*/

#include <stdlib.h>
#include "my_bgs.h"
#include "my_bgs_components.h"
#include "my_json.h"
#include "my_rpg.h"

static const char *rects_keys[] = {"up", "left", "down", "right", NULL};

void move_off(object_t *obj, scene_t *scene, window_t *win, set_event_t *event)
{
    player_t *player = NULL;

    if (obj == NULL || scene == NULL || win == NULL || event == NULL) {
        return;
    }
    player = dico_t_get_value(win->components, "player");
    if (player == NULL) {
        return;
    }
    set_stop(player);
}

static int apply_player_positions(player_t *player, int state,
    any_t *movements_rect)
{
    int *rect = NULL;

    rect = get_any_int_array(get_from_any(movements_rect, "da",
        rects_keys[player->dir], state));
    if (rect == NULL) {
        return RET_ERR_MALLOC;
    }
    player->obj->bigdata.sprite_bigdata.rect =
        (sfIntRect) {rect[0], rect[1], rect[2], rect[3]};
    free(rect);
    return RET_OK;
}

static int move_player(player_t *player, float delta_time,
    any_t *movements_rect)
{
    static int state = 1;
    static float timer = 0;
    int ret = RET_OK;

    for (timer += delta_time; timer >= 0.09; timer -= 0.09) {
        state += 1;
        if (dico_t_get_any(movements_rect->value.dict,
            rects_keys[player->dir])->value.array->len <= state) {
            state = 0;
        }
    }
    ret = apply_player_positions(player, state, movements_rect);
    return ret;
}

static void handle_move_player(player_t *player, float delta_time)
{
    any_t *move = NULL;
    any_t *data = NULL;

    data = dico_t_get_any(player->obj->components, "data");
    if (data == NULL || player->state != MOVING) {
        return;
    }
    move = dico_t_get_any(data->value.dict, "move");
    if (move == NULL || move->type != DICT) {
        return;
    }
    move_player(player, delta_time, move);
}

void update_movements(player_t *player, scene_t *scene, window_t *win,
    float delta_time)
{
    if (player == NULL || scene == NULL || win == NULL) {
        return;
    }
    handle_move_player(player, delta_time);
}
