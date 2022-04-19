/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** header for ennemy
*/

#ifndef ENNEMY_H_
    #define ENNEMY_H_

    #include "my_json.h"
    #include "my_rpg.h"

typedef struct ennemy_s {
    state_t state;
    dir_t dir;
    float life;
    object_t *obj;
} ennemy_t;

static const char ENNEMY_DATA[] = "ennemy_data";

static const char ENNEMY_LIST[] = "ennemy_list";

int create_ennemy(scene_t *scene, const char *path, sfVector2f pos);

bool is_player_in_range(ennemy_t *ennemy, window_t *win);

void update_ennemy(object_t *obj, scene_t *scene, window_t *win,
    float dtime);

void update_ennemy_move(ennemy_t *ennemy, scene_t *scene, window_t *win,
    float time);

    #define SPEED_ENN_AMONGUS 200

int create_amongus(scene_t *scene, int pos_x, int pos_y);

int change_amongus_rect(any_t *dico, object_t *obj, window_t *win);

int ennemy_set_stop(ennemy_t *ennemy);

/**
** @brief update pos of the obj sprite to follow the ennemy
**
** @param obj obj to update
** @param scene scene in which the obj is
** @param dtime delta time (dtime)
**
** @return {
** RET_ERR_INPUT : obj ot scene is NULL,
** RET_ERR_INPUT : can't acces pathfind info,
** RET_OK : position has been updated
** }
**/
int follow_player(object_t *obj, scene_t *scene, float dtime);

#endif
