/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** ennemy update
*/

#include "my_rpg.h"
#include "my_json.h"
#include "ennemy_pathfind.h"
#include "ennemies.h"

static void update_ennemy_attack(ennemy_t *ennemy, scene_t *scene,
    window_t *win, float time);

static void update_ennemy_dying(ennemy_t *ennemy, scene_t *scene, window_t *win,
    float time);

static void update_ennemy_stop(ennemy_t *ennemy, scene_t *scene, window_t *win,
    float time);

static void (*update_state[])(ennemy_t *ennemy, scene_t *scene, window_t *win,
    float time) = {
        update_ennemy_attack, update_ennemy_move, update_ennemy_dying,
            update_ennemy_stop
};

static void update_ennemy_attack(__attribute__((unused)) ennemy_t *ennemy,
    __attribute__((unused)) scene_t *scene,
    __attribute__((unused)) window_t *win, __attribute__((unused)) float time)
{

}

static void update_ennemy_dying(__attribute__((unused)) ennemy_t *ennemy,
    __attribute__((unused)) scene_t *scene,
    __attribute__((unused)) window_t *win, __attribute__((unused)) float time)
{

}

static void update_ennemy_stop(ennemy_t *ennemy,
    __attribute__((unused)) scene_t *scene,
    window_t *win, __attribute__((unused)) float time)
{
    if (is_player_in_range(ennemy, win) == false) {
        return;
    }
    ennemy->state = MOVING;
}

void update_ennemy(object_t *obj, scene_t *scene, window_t *win,
    float dtime)
{
    ennemy_t *ennemy = dico_t_get_value(obj->components, "struct");

    if (ennemy == NULL) {
        return;
    }
    if (ennemy->state >= 0 && ennemy->state <= 3) {
        update_state[ennemy->state](ennemy, scene, win, dtime);
    }
}
