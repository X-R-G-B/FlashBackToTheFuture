/*
** EPITECH PROJECT, 2022
** my rpg
** File description:
** header
*/

#ifndef RPG_H_
#define RPG_H_

#include "my_bgs.h"

typedef enum state_e {
    STOP,
    MOVING,
    ATTACKING,
    DYING,
    DIE,
    STUNT
} state_t;

typedef enum dir_e {
    UP,
    RIGHT,
    DOWN,
    LEFT
} dir_t;

typedef struct player_s {
    state_t state;
    dir_t dir;
    object_t *obj;
} player_t;

#endif /* !RPG_H_ */
