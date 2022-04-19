/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** temp
*/

#include <math.h>
#include "my_rpg.h"

static const double pi = 3.1415926535;

static sfVector2f get_position_player(window_t *win)
{
    sfVector2f pos = {500, 500};
    player_t *player = dico_t_get_value(win->components, "player");

    if (player == NULL) {
        return (pos);
    }
    pos = player->obj->bigdata.sprite_bigdata.pos;
    return (pos);
}

dir_t get_new_dir(object_t *obj, window_t *win)
{
    sfVector2f dir = get_position_player(win);
    sfVector2f cur = sfSprite_getPosition(obj->drawable.sprite);
    double angle = 0;

    angle = atan2(cur.y - dir.y, cur.x - dir.x) * 180 / pi;
    if (45 <= angle && angle < 135) {
        return UP;
    }
    if (135 <= angle || -135 > angle) {
        return RIGHT;
    }
    if (-135 <= angle && angle < -45) {
        return DOWN;
    }
    if (-45 <= angle && angle < 45) {
        return LEFT;
    }
    return UNKNOWN_STATE;
}
