/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** update ennemy hurt
*/

#include "ennemies.h"
#include "my_bgs.h"
#include "my_json.h"

static const char blink_time_key[] = "blink time";

bool check_wall(ennemy_t *ennemy, sfVector2f new, window_t *win)
{
    int x = 0;
    int y = 0;
    scene_t *scene = NULL;
    char **map = NULL;

    if (win == NULL || ennemy == NULL || ennemy->obj == NULL) {
        return (true);
    }
    scene = dico_t_get_value(win->scenes, win->current_scene);
    x = ennemy->obj->bigdata.sprite_bigdata.pos.x - new.x;
    y = ennemy->obj->bigdata.sprite_bigdata.pos.y - new.y;
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

    if (dir == UNKNOWN_STATE || check_wall(ennemy, news[dir], win) == true) {
        return;
    }
    ennemy->obj->bigdata.sprite_bigdata.pos.x -= news[dir].x;
    ennemy->obj->bigdata.sprite_bigdata.pos.y -= news[dir].y;
}

static void update_when_ennemy_die(ennemy_t *ennemy, window_t *win,
    scene_t *scene)
{
    ennemy->obj->components = dico_t_rem(ennemy->obj->components, "hurt");
    if (ennemy->life <= 0) {
        update_xp(ennemy, win, scene);
        check_drop(ennemy);
        ennemy->state = DYING;
    }
}

void ennemy_update_hurt(ennemy_t *ennemy, float dtime, window_t *win,
    scene_t *scene)
{
    static float time = 0;
    float blink_time = get_blink_time(ennemy);
    any_t *json = NULL;
    float speed = 10;

    if (blink_time < 0 || ennemy == NULL || ennemy->obj == NULL) {
        return;
    }
    json = dico_t_get_value(ennemy->obj->components, ENNEMY_DATA);
    json = get_from_any(json, "d", "speed");
    time += dtime;
    speed = (json == NULL || json->type != FLOAT) ? speed : json->value.f;
    move_ennemy(ennemy, (dtime * speed / (time * speed)) * 20, win);
    if (time >= blink_time) {
        time = 0;
        update_when_ennemy_die(ennemy, win, scene);
    }
}
