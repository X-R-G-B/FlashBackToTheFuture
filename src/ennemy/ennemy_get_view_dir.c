/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** ennemy get new dir
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Vector2.h>
#include <math.h>
#include "maths_function.h"
#include "my_bgs.h"
#include "my_macro.h"
#include "my_rpg.h"
#include "ennemies.h"
#include "my_json.h"

static const double pi = 3.1415926535;

static sfVector2f get_position_player(window_t *win)
{
    sfVector2f pos = {500, 500};
    player_t *player = dico_t_get_value(win->components, PLAYER);

    if (player == NULL) {
        return (pos);
    }
    pos = player->obj->bigdata.sprite_bigdata.pos;
    return (pos);
}

dir_t get_view_dir(sfVector2f cur_pos, sfVector2f next_pos)
{
    double angle = 0;

    angle = atan2(cur_pos.y - next_pos.y, cur_pos.x - next_pos.x) * 180 / pi;
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

dir_t ennemy_get_view_dir(object_t *obj, window_t *win)
{
    sfVector2f cur = {0};
    sfVector2f dir = {0};

    if (obj == NULL || win == NULL) {
        return (UNKNOWN_STATE);
    }
    dir = get_position_player(win);
    cur = sfSprite_getPosition(obj->drawable.sprite);
    return (get_view_dir(cur, dir));
}

int *get_rect(ennemy_t *ennemy, window_t *win, any_t *data)
{
    dir_t dir = UNKNOWN_STATE;
    sfVector2f scale = {0};
    int *arr = NULL;

    if (ennemy == NULL || ennemy->obj == NULL || data == NULL) {
        return NULL;
    }
    dir = ennemy_get_view_dir(ennemy->obj, win);
    dir = (dir == UNKNOWN_STATE) ? DOWN : dir;
    scale = sfSprite_getScale(ennemy->obj->drawable.sprite);
    if (dir == RIGHT) {
        scale.x = MIN(scale.x, scale.x * -1);
        sfSprite_setScale(ennemy->obj->drawable.sprite, scale);
    } else {
        scale.x = MAX(scale.x, scale.x * -1);
        sfSprite_setScale(ennemy->obj->drawable.sprite, scale);
    }
    arr = get_any_int_array(get_from_any(data, "daa", "move", dir,
        ennemy->rect_id));
    return arr;
}
