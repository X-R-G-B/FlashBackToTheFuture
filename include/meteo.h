/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** meteo handler header
*/

#ifndef METEO_RPG_H_
    #define METEO_RPG_H_

    #include "my_bgs.h"

    #define METEO_HANDLER_COMP "meteo_handler"

struct meteo_rpg_s {
    enum meteo_type_e {
        UNKNOWN = 0,
        LEAF = 1,
        SNOW = 2,
        SUN = 3,
    } type_now;
};

void update_meteo_handler(
    object_t *obj,
    scene_t *scene,
    window_t *win,
    float dtime
);

int add_leaf(window_t *win, int x);
int add_snow(window_t *win, int x);
int add_sun(window_t *win, int x);

int create_meteo_handler(window_t *win, scene_t *scene);

#endif
