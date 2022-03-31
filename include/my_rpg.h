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
    STOP,
    MOVING,
    ATTACKING,
    DYING,
    DIE,
    STUNT
} state_t;

typedef enum player_dir_e {
    PLAYER_RIGHT,
    PLAYER_DOWN,
    PLAYER_LEFT,
    PLAYER_UP
} player_dir_t;

typedef struct player_s {
    state_t state;
    object_t *obj;
    player_dir_t player_dir;
} player_t;

#endif /* !RPG_H_ */
