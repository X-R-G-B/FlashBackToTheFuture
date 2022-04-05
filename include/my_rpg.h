/*
** EPITECH PROJECT, 2022
** my rpg
** File description:
** header
*/

#ifndef RPG_H_
    #define RPG_H_

    #define RET_OK 0
    #define RET_ERR_MALLOC 1
    #define RET_ERR_INPUT 2

    #include "my_bgs.h"

typedef enum state_e {
    ATTACKING,
    STOP,
    DYING,
    DIE,
    MOVING,
    STUNT
} state_t;

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
} player_t;

void update_player(object_t *obj, scene_t *scene, window_t *win, float dtime);

void update_attack(player_t *player, scene_t *scene, window_t *win,
    float dtime);

void set_stop(player_t *player);

player_t *create_player(window_t *win, scene_t *scene, const char *stats);

void attack_event(object_t *obj, scene_t *scene,
    window_t *win, set_event_t *set_event);
    #define RET_ERR_INPUT 1
    #define RET_ERR_MALLOC 2

    #include "my_bgs.h"

list_ptr_t *create_pause_menu(scene_t *scene);

void home_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt);

void pressed_button_on(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt);

void pressed_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt);

void exit_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt);

void resume_event_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt);

void settings_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt);

void restart_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt);

#endif /* !RPG_H_ */
