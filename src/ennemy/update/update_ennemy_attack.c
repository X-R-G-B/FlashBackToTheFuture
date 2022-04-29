/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** update ennemy attack
*/

#include "my_bgs.h"
#include "my_json.h"
#include "ennemies.h"
#include "my_rpg.h"
#include <SFML/System/Vector2.h>

static const float time_charging_dash = 0.5;
static const float time_dash = 1.5;

int get_data(any_t **rect_speed, any_t **move_speed, any_t *data,
    any_t **rect_list);

static void update_move(ennemy_t *ennemy, float inverse, float speed,
    float dtime)
{
    sfVector2f news[4] = {
        {0, 0 - speed},
        {0 - speed, 0},
        {0, speed},
        {speed, 0}};
    sfVector2f vect = {0};

    vect = news[ennemy->dir];
    vect.y *= inverse * dtime * 2;
    vect.x *= inverse * dtime * 2;
    ennemy->obj->bigdata.sprite_bigdata.pos.x += vect.x;
    ennemy->obj->bigdata.sprite_bigdata.pos.y += vect.y;
}

void update_ennemy_attack(__attribute__((unused)) ennemy_t *ennemy,
    __attribute__((unused)) scene_t *scene,
    __attribute__((unused)) window_t *win,
    __attribute__((unused)) float dtime)
{
    any_t *rect_speed = NULL;
    any_t *move_speed = NULL;
    any_t *data = NULL;
    any_t *rect_list = NULL;

    if (ennemy == NULL || ennemy->obj == NULL) {
        return;
    }
    ennemy->delta_time += dtime;
    data = dico_t_get_value(ennemy->obj->components, ENNEMY_DATA);
    if (ennemy->delta_time > time_dash || get_data(&rect_speed, &move_speed,
            data, &rect_list) != RET_OK) {
        ennemy_set_stop(ennemy);
        ennemy->delta_time = 0;
    } else if (ennemy->delta_time > time_charging_dash) {
        update_move(ennemy, 1, move_speed->value.f, dtime);
    } else {
        update_move(ennemy, -0.2, move_speed->value.f, dtime);
    }
}
