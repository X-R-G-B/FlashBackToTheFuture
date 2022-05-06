/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** update ennemy attack
*/

#include <SFML/System/Vector2.h>
#include "my_bgs.h"
#include "my_dico.h"
#include "my_json.h"
#include "ennemies.h"
#include "my_rpg.h"

static const char dash_time_key[] = "dash time";
static const char charge_time_key[] = "charge time";
extern const char components_direction[];

int get_data(any_t **rect_speed, any_t **move_speed, any_t *data,
    any_t **rect_list);

static sfVector2f get_vector_use(ennemy_t *ennemy, float speed)
{
    sfVector2f *dir = dico_t_get_value(ennemy->obj->components,
        components_direction);
    sfVector2f news[4] = {
        {0, 0 - speed},
        {0 - speed, 0},
        {0, speed},
        {speed, 0}};

    if (dir == NULL) {
        return (news[ennemy->dir]);
    }
    news[0].x = dir->x * speed;
    news[0].y = dir->y * speed;
    return (news[0]);
}

static void update_move(ennemy_t *ennemy, float speed, window_t *win)
{
    sfVector2f vect = {0};

    vect = get_vector_use(ennemy, speed);
    if (check_wall(ennemy, (sfVector2f) {vect.x * -1, vect.y * -1},
            win) == true) {
        return;
    }
    ennemy->obj->bigdata.sprite_bigdata.pos.x += vect.x;
    ennemy->obj->bigdata.sprite_bigdata.pos.y += vect.y;
}

static int check_ennemy(ennemy_t *ennemy)
{
    if (ennemy == NULL || ennemy->obj == NULL) {
        return RET_ERR_INPUT;
    }
    if (ennemy->delta_time == 0) {
        ennemy_set_stop(ennemy);
        ennemy->state = ATTACKING;
    }
    return RET_OK;
}

static void check_ennemy_delta_time(ennemy_t *ennemy, float dtime,
    window_t *win, any_t *dash_time)
{
    any_t *rect_speed = NULL;
    any_t *move_speed = NULL;
    any_t *rect_list = NULL;
    any_t *charge_time = NULL;
    any_t *data = NULL;

    data = dico_t_get_value(ennemy->obj->components, ENNEMY_DATA);
    charge_time = get_from_any(data, "d", charge_time_key);
    if (ennemy->delta_time > dash_time->value.f || get_data(&rect_speed,
            &move_speed, data, &rect_list) != RET_OK || charge_time == NULL ||
            charge_time->type != FLOAT) {
        ennemy_set_stop(ennemy);
        ennemy->delta_time = 0;
        ennemy->obj->components = dico_t_rem(ennemy->obj->components,
            components_direction);
    } else if (ennemy->delta_time > charge_time->value.f) {
        update_move(ennemy, move_speed->value.f, dtime * 1, win);
    } else {
        update_move(ennemy, move_speed->value.f, dtime * -0.2, win);
    }
}

void update_ennemy_attack(ennemy_t *ennemy,
    __attribute__((unused)) scene_t *scene,
    window_t *win, float dtime)
{
    any_t *dash_time = NULL;

    if (check_ennemy(ennemy) != RET_OK) {
        return;
    }
    ennemy->delta_time += dtime;
    dash_time = dico_t_get_value(ennemy->obj->components, ENNEMY_DATA);
    dash_time = get_from_any(dash_time, "d", dash_time_key);
    if (dash_time == NULL || dash_time->type != FLOAT) {
        return;
    }
    check_ennemy_delta_time(ennemy, dtime, win, dash_time);
}
