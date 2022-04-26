/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** header for ennemy
*/

#ifndef ENNEMY_H_
    #define ENNEMY_H_

    #define LVL_UP 3

    #include "my_json.h"
    #include "my_bgs.h"
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

bool ennemy_check_hurt(ennemy_t *ennemy, scene_t *scene, window_t *win,
    float dtime);

void destroy_ennemy(ennemy_t *ennemy, scene_t *scene);

dir_t ennemy_get_view_dir(object_t *obj, window_t *win);

sfFloatRect get_attack_hitbox_rect(sfFloatRect player_rect, player_t *player);

bool is_player_in_range(ennemy_t *ennemy, window_t *win);

void ennemy_update_hurt(ennemy_t *ennemy, float dtime, window_t *win,
    scene_t *scene);

void player_check_hurt(player_t *player, scene_t *scene);

int add_to_ennemy_list(ennemy_t *ennemy, scene_t *scene);

void update_ennemy(object_t *obj, scene_t *scene, window_t *win,
    float dtime);

void update_ennemy_move(ennemy_t *ennemy, scene_t *scene, window_t *win,
    float time);

int change_amongus_rect(any_t *dico, object_t *obj, window_t *win);

int *get_rect(ennemy_t *ennemy, window_t *win, any_t *data, int rect_id);

int get_rect_id(any_t *data, player_t *player);

int sprite_set_change(object_t *ennemy, any_t *ennemy_data);

void update_xp(ennemy_t *ennemy, window_t *win, scene_t *scene);

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
