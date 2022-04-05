/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** pause button event
*/

#include "my_rpg.h"

void settings_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    pressed_button_off(obj, scene, win, evt);
}

void restart_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    pressed_button_off(obj, scene, win, evt);
}

void exit_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    pressed_button_off(obj, scene, win, evt);
    sfRenderWindow_close(win->win);
}

void resume_event_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    pressed_button_off(obj, scene, win, evt);
}

void home_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    pressed_button_off(obj, scene, win, evt);
}
