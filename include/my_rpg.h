/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** header
*/

#ifndef RPG_H_
    #define RPG_H_

    #define RET_OK 0
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
