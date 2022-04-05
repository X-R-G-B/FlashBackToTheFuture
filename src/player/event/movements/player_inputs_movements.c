/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** player_inputs_movements
*/

#include "my_bgs.h"
#include "my_bgs_components.h"
#include "my_rpg.h"

static const dir_t player_dir[] = {UP, LEFT, DOWN, RIGHT};
static const sfKeyCode key[] = {sfKeyUp, sfKeyLeft, sfKeyDown, sfKeyRight, 0};

int handle_changings_movements(player_t *player, int dir)
{
    dir_t prev_dir = player->dir;

    player->dir = player_dir[dir];
    if (player->dir == RIGHT && prev_dir != RIGHT) {
        sfSprite_setScale(player->obj->drawable.sprite,
            (sfVector2f) {-1, 1});
    } else if (player->dir != RIGHT && prev_dir == RIGHT) {
        sfSprite_setScale(player->obj->drawable.sprite,
            (sfVector2f) {1, 1});
    }
    return RET_OK;
}

void event_movements(object_t *object, scene_t *scene, window_t *win,
    set_event_t *event)
{
    player_t *player = NULL;

    if (object == NULL || scene == NULL || win == NULL || event == NULL) {
        return;
    }
    player = dico_t_get_value(win->components, "player");
    if (player == NULL) {
        return;
    }
    player->state = MOVING;
    for (int dir = 0; key[dir] != 0; dir++) {
        if (event->input_key.event_code.key == key[dir]) {
            handle_changings_movements(player, dir);
        }
    }
}
