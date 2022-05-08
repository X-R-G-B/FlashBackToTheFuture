/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** define structure for the rpg
*/

#ifndef MYRPG_STRUCT_PLAYER_H_
    #define MYRPG_STRUCT_PLAYER_H_

    #include "my_bgs.h"

typedef enum state_e {
    ATTACKING,
    MOVING,
    STOP,
    DYING,
    ROULADE,
    DIE,
    IN_POP_UP,
    STUNT
} state_t;

typedef enum dir_e {
    UNKNOWN_STATE = -1,
    UP = 0,
    LEFT = 1,
    DOWN = 2,
    RIGHT = 3
} dir_t;

typedef struct player_s {
    state_t state;
    dir_t dir;
    object_t *obj;
    sfView *view;
    float life;
    float energy;
    framebuffer_t *buf;
} player_t;

#endif
