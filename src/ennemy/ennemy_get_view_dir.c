/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** ennemy get new dir
*/

#include "math.h"
#include "my_rpg.h"
#include "ennemies.h"
#include "my_json.h"

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

static dir_t ennemy_get_view_dir(object_t *obj, window_t *win)
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

int *get_rect(ennemy_t *ennemy, window_t *win, any_t *data, int rect_id)
{
    dir_t view_dir = ennemy_get_view_dir(ennemy->obj, win);
    any_t *scale = dico_t_get_value(data->value.dict, "scale");
    float scale_value = 1;

    if (ennemy == NULL || win == NULL || data == NULL) {
        return NULL;
    }
    if (scale != NULL && scale->type == FLOAT) {
        scale_value = scale->value.f;
    }
    if (view_dir == RIGHT && ennemy->dir != RIGHT) {
        sfSprite_setScale(ennemy->obj->drawable.sprite,
            (sfVector2f) {scale_value * -1, scale_value});
    } else if (view_dir != RIGHT && ennemy->dir == RIGHT) {
        sfSprite_setScale(ennemy->obj->drawable.sprite,
            (sfVector2f) {scale_value, scale_value});
    }
    return get_any_int_array(get_from_any(data, "daa", "move", view_dir,
        rect_id));
}
