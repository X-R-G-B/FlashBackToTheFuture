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
    sfSprite_setOrigin(player->obj->drawable.sprite,
        (sfVector2f) {rect[2] / 2, rect[3] / 2});
    free(rect);
    return RET_OK;
}

static int change_player_pos(player_t *player, float delta_time, int speed)
{
    switch (player->dir) {
        case RIGHT:
            player->obj->bigdata.sprite_bigdata.pos.x += delta_time * speed;
            break;
        case DOWN:
            player->obj->bigdata.sprite_bigdata.pos.y += delta_time * speed;
            break;
        case LEFT:
            player->obj->bigdata.sprite_bigdata.pos.x -= delta_time * speed;
            break;
        case UP:
            player->obj->bigdata.sprite_bigdata.pos.y -= delta_time * speed;
            player->state = DYING;
            break;
        default:
            break;
    }
    return 0;
}

static int move_player(player_t *player, float delta_time,
    any_t *movements_rect)
{
    static int state = 1;
    static float timer = 0;
    int ret = RET_OK;
    any_t *speed = NULL;

    for (timer += delta_time; timer >= 0.09; timer -= 0.09) {
        state += 1;
        if (dico_t_get_any(movements_rect->value.dict,
            rects_keys[player->dir])->value.array->len <= state) {
            state = 0;
        }
    }
    speed = dico_t_get_any(movements_rect->value.dict, "speed");
    if (speed == NULL || speed->type != INT) {
        return RET_ERR_INPUT;
    }
    change_player_pos(player, delta_time, speed->value.i);
    ret = apply_player_positions(player, state, movements_rect);
    return ret;
}

static void handle_move_player(player_t *player, float delta_time)
{
    any_t *move = NULL;
    any_t *data = NULL;

    data = dico_t_get_any(player->obj->components, "data");
    if (data == NULL) {
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
    if (player == NULL || player->state != MOVING || scene == NULL ||
        win == NULL) {
        return;
    }
    handle_move_player(player, delta_time);
}
