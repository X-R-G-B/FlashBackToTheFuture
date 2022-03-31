/*
** EPITECH PROJECT, 2022
** my rpg
** File description:
** header
*/

#ifndef RPG_H_
    #define RPG_H_

    #include "my_bgs.h"

    #define RET_OK 0
    #define RET_ERR_MALLOC 1
    #define RET_ERR_INPUT 2

typedef enum state_e {
    ATTACKING,
    STOP,
    DYING,
    DIE,
    MOVING,
    STUNT
} state_t;

typedef enum player_dir_e {
    PLAYER_RIGHT,
    PLAYER_DOWN,
    PLAYER_LEFT,
    PLAYER_UP
} player_dir_t;
typedef enum dir_e {
    UP,
    LEFT,
    DOWN,
    RIGHT
} dir_t;

typedef struct player_s {
    state_t state;
    dir_t dir;
    object_t *obj;
    player_dir_t player_dir;
} player_t;

void update_player(object_t *obj, scene_t *scene, window_t *win, float dtime);

void update_attack(player_t *player, scene_t *scene, window_t *win,
    float dtime);

void set_stop(player_t *player);

void attack(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *set_event);

void attack_event(object_t *obj, scene_t *scene,
    window_t *win, set_event_t *set_event);

#endif /* !RPG_H_ */
