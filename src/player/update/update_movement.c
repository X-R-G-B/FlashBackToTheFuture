/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** player_movements
*/

#include <SFML/Graphics/View.h>
#include <SFML/System/Vector2.h>
#include <stdlib.h>
#include "my_bgs.h"
#include "my_bgs_components.h"
#include "my_json.h"
#include "my_rpg.h"
#include "macro.h"
#include "player.h"

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
        (sfVector2f) {rect[2] / 2.0, rect[3] / 2.0});
    free(rect);
    return RET_OK;
}

void change_player_pos(player_t *player, float move,
    window_t *win)
{
    sfVector2f news[4] = {{0, 0 - move}, {0 - move, 0}, {0, move}, {move, 0}};
    scene_t *scene = NULL;

    if (player == NULL || win == NULL) {
        return;
    }
    scene = dico_t_get_value(win->scenes, win->current_scene);
    if (scene == NULL || check_collision(player, scene) == true) {
        return;
    }
    player->obj->bigdata.sprite_bigdata.pos.x += news[player->dir].x;
    player->obj->bigdata.sprite_bigdata.pos.y += news[player->dir].y;
    sfView_move(player->view, news[player->dir]);
    increment_hud_pos(win, news[player->dir]);
    return;
}

static int move_player(player_t *player, float delta_time,
    any_t *movements_rect, window_t *win)
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
    change_player_pos(player, delta_time * speed->value.i, win);
    ret = apply_player_positions(player, state, movements_rect);
    return ret;
}

static void handle_move_player(player_t *player, float delta_time,
    window_t *win)
{
    any_t *move = NULL;
    any_t *data = NULL;

    data = dico_t_get_any(player->obj->components, PLAYER_DATA);
    if (data == NULL) {
        return;
    }
    move = dico_t_get_any(data->value.dict, "move");
    if (move == NULL || move->type != DICT) {
        return;
    }
    move_player(player, delta_time, move, win);
}

void update_movements(player_t *player, scene_t *scene, window_t *win,
    float delta_time)
{
    if (player == NULL || player->state != MOVING || scene == NULL ||
        win == NULL) {
        return;
    }
    handle_move_player(player, delta_time, win);
    sfRenderWindow_setView(win->win, player->view);
}
