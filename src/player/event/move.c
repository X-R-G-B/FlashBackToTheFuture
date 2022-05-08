/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** player_inputs_movements
*/

#include "my_bgs.h"
#include "my_bgs_components.h"
#include "meteo.h"
#include "macro.h"

static const dir_t player_dir[] = {UP, LEFT, DOWN, RIGHT};
static const sfKeyCode key[] = {sfKeyZ, sfKeyQ, sfKeyS, sfKeyD, -1};

static int handle_changings_movements(player_t *player, int dir)
{
    dir_t prev_dir = player->dir;
    sfVector2f scale = {0};

    player->dir = player_dir[dir];
    scale = sfSprite_getScale(player->obj->drawable.sprite);
    if (player->dir == RIGHT && prev_dir != RIGHT) {
        scale.x = (scale.x < 0) ? scale.x : scale.x * -1;
    } else if (player->dir != RIGHT && prev_dir == RIGHT) {
        scale.x = (scale.x < 0) ? scale.x * -1 : scale.x;
    }
    sfSprite_setScale(player->obj->drawable.sprite, scale);
    return RET_OK;
}

void move_on(object_t *object, scene_t *scene, window_t *win,
    set_event_t *event)
{
    player_t *player = NULL;

    if (scene->pause == true || object == NULL || scene == NULL ||
        win == NULL || event == NULL) {
        return;
    }
    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL || (player->state != MOVING && player->state != STOP)) {
        return;
    }
    player->state = MOVING;
    add_dirt_player(win, player);
    for (int dir = 0; key[dir] != -1; dir++) {
        if (event->input_key.event_code.key == key[dir]) {
            handle_changings_movements(player, dir);
        }
    }
}

void move_off(object_t *obj, scene_t *scene, window_t *win, set_event_t *event)
{
    player_t *player = NULL;

    if (scene->pause == true || obj == NULL || scene == NULL || win == NULL ||
        event == NULL) {
        return;
    }
    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL || player->state != MOVING) {
        return;
    }
    set_stop(player);
}
