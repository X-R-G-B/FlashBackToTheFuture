/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** meteo handler header
*/

#ifndef METEO_RPG_H_
    #define METEO_RPG_H_

    #include "my_bgs.h"
    #include "my_rpg.h"

    #define METEO_HANDLER_COMP "meteo_handler"

struct meteo_rpg_s {
    enum meteo_type_e {
        UNKNOWN = 0,
        LEAF = 1,
        SNOW = 2,
        SUN = 3,
    } type_now;
};

    #define NB_VECTORS_SUN 26
    #define DEFAULT_METEO SUN

void update_meteo_handler(
    object_t *obj,
    scene_t *scene,
    window_t *win,
    float dtime
);

int add_leaf(window_t *win, int x);
int add_snow(window_t *win, int x);
int add_sun(window_t *win, int x);

/**
** @brief create the meteo data and object to manage it
**
** @param win window to use
** @param scene scene in which the manager will go
**
** @return {
** RET_ERR_INPUT : win or scene is NULL,
** RET_ERR_MALLOC : malloc failed,
** RET_ERR_MALLOC : the components already exists (but not error in some case)
** RET_OK : componenet meteo created and managor too
** }
**/
int create_meteo_handler(window_t *win, scene_t *scene);

/**
** @brief change the meteo (change component in window)
**
** @param win window to change the meteo
** @param type meteo to use (SNOW LEAF SUN UNKNOW)
**
** @return {
** RET_ERR_INPUT : win is NULL,
** RET_ERR_INPUT : meteo struct is not on window,
** RET_OK : meteo has been changed
** }
**/
int change_meteo(window_t *win, enum meteo_type_e type);

int add_dirt_player(window_t *win, player_t *player);

int change_meteo_to_json(window_t *win, scene_t *scene);

#endif
