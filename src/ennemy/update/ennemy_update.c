/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** ennemy update
*/

#include "my_bgs.h"
#include "my_dico.h"
#include "my_rpg.h"
#include "my_json.h"
#include "ennemy_pathfind.h"
#include "ennemies.h"

void update_ennemy_attack(ennemy_t *ennemy, scene_t *scene,
    window_t *win, float time);

static void update_ennemy_dying(ennemy_t *ennemy, scene_t *scene, window_t *win,
    float time);

static void update_ennemy_stop(ennemy_t *ennemy, scene_t *scene, window_t *win,
    float time);

static void (*update_state[])(ennemy_t *ennemy, scene_t *scene, window_t *win,
    float time) = {
        update_ennemy_attack, update_ennemy_move, update_ennemy_stop,
        update_ennemy_dying
};

static void update_ennemy_dying(ennemy_t *ennemy, scene_t *scene,
    __attribute__((unused)) window_t *win, __attribute__((unused)) float time)
{
    destroy_ennemy(ennemy, scene);
}

static void update_ennemy_stop(ennemy_t *ennemy,
    __attribute__((unused)) scene_t *scene,
    window_t *win, __attribute__((unused)) float time)
{
    if (ennemy == NULL || ennemy->obj == NULL ||
        is_player_in_range(ennemy, win) == false) {
        return;
    }
    ennemy->state = MOVING;
}

void update_ennemy(object_t *obj, scene_t *scene, window_t *win,
    float dtime)
{
    ennemy_t *ennemy = NULL;

    if (scene == NULL || scene->pause == true || obj == NULL) {
        return;
    }
    ennemy = dico_t_get_value(obj->components, "struct");
    if (ennemy == NULL) {
        return;
    } else if (ennemy->state >= 0 && ennemy->state <= 3 &&
        ennemy_check_hurt(ennemy, scene, win, dtime) == false) {
        update_state[ennemy->state](ennemy, scene, win, dtime);
    }
}
