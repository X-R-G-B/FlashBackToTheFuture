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

void stop_player_after_movments(object_t *obj, scene_t *scene,
    window_t *win, set_event_t *event)
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

int apply_player_positions(object_t *obj, player_t *player, int state,
    any_t *movements_rect)
{
    const char *rects_keys[] = {"up", "left", "down", "right", NULL};
    int *rect = NULL;

    rect = get_any_int_array(get_from_any(movements_rect, "da",
        rects_keys[player->dir], state));
    if (rect == NULL) {
        return RET_ERR_MALLOC;
    }
    obj->bigdata.sprite_bigdata.rect =
        (sfIntRect) {rect[0], rect[1], rect[2], rect[3]};
    free(rect);
    return RET_OK;
}

int move_player(object_t *obj, player_t *player, float delta_time,
    any_t *movements_rect)
{
    const char *rects_keys[] = {"up", "left", "down", "right", NULL};
    static int state = 1;
    static float timer = 0;
    int ret = RET_OK;

    timer += delta_time;
    for (; timer >= 0.09; timer -= 0.09) {
        state += 1;
        if (dico_t_get_any(movements_rect->value.dict,
            rects_keys[player->dir])->value.array->len <= state) {
            state = 0;
        }
    }
    ret = apply_player_positions(obj, player, state, movements_rect);
    if (ret != RET_OK) {
        return RET_ERR_MALLOC;
    }
    return RET_OK;
}

void handle_move_player(object_t *obj, window_t *win, float delta_time)
{
    any_t *movements_rect = NULL;
    player_t *player = dico_t_get_value(win->components, "player");

    movements_rect = dico_t_get_any(player->obj->components,
        "movements_rect");
    if (player == NULL || movements_rect == NULL || player->state != MOVING) {
        return;
    }
    move_player(obj, player, delta_time, movements_rect);
}

void update_movements(object_t *object, scene_t *scene, window_t *win,
    float delta_time)
{
    if (object == NULL || scene == NULL || win == NULL) {
        return;
    }
    handle_move_player(object, win, delta_time);
}
