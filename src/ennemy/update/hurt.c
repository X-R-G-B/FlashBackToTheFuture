/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** update ennemy hurt
*/

#include "ennemies.h"

static const char blink_time_key[] = "blink time";

static bool check_wall(ennemy_t *ennemy, sfVector2f new, window_t *win)
{
    scene_t *scene = dico_t_get_value(win->scenes, win->current_scene);
    int x = ennemy->obj->bigdata.sprite_bigdata.pos.x - new.x;
    int y = ennemy->obj->bigdata.sprite_bigdata.pos.y - new.y;
    char **map = NULL;

    if (scene == NULL) {
        return true;
    }
    map = dico_t_get_value(scene->components, COLLISION_ARRAY);
    if (map == NULL || map[y / SQUARE_SIZE][x / SQUARE_SIZE] == '#') {
        return true;
    }
    return false;
}

static float get_blink_time(ennemy_t *ennemy)
{
    any_t *ennemy_data = NULL;
    any_t *blink_time = NULL;

    if (ennemy == NULL) {
        return -1;
    }
    ennemy_data = dico_t_get_any(ennemy->obj->components, ENNEMY_DATA);
    if (ennemy_data == NULL || ennemy_data->type != DICT) {
        return -1;
    }
    blink_time = dico_t_get_any(ennemy_data->value.dict, blink_time_key);
    if (blink_time == NULL || blink_time->type != FLOAT) {
        return -1;
    }
    return blink_time->value.f;
}

static void move_ennemy(ennemy_t *ennemy, float move, window_t *win)
{
    sfVector2f news[4] = {{0, 0 - move}, {0 - move, 0}, {0, move}, {move, 0}};
    dir_t dir = ennemy_get_view_dir(ennemy->obj, win);

    if (check_wall(ennemy, news[dir], win) == true) {
        return;
    }
    ennemy->obj->bigdata.sprite_bigdata.pos.x -= news[dir].x;
    ennemy->obj->bigdata.sprite_bigdata.pos.y -= news[dir].y;
}

void ennemy_update_hurt(ennemy_t *ennemy, float dtime, window_t *win)
{
    static float time = 0;
    float blink_time = get_blink_time(ennemy);

    if (blink_time < 0) {
        return;
    }
    move_ennemy(ennemy, dtime * 150, win);
    time += dtime;
    if (time >= blink_time) {
        time = 0;
        ennemy->obj->components = dico_t_rem(ennemy->obj->components, "hurt");
        if (ennemy->life <= 0) {
            ennemy->state = DYING;
        }
    }
}
