/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** pause button event
*/

#include "my_rpg.h"
#include "my_bgs_button_generator.h"

void settings_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    if (scene->pause == false) {
        return;
    }
    pressed_button_off(obj, scene, win, evt);
}

void restart_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    if (scene->pause == false) {
        return;
    }
    pressed_button_off(obj, scene, win, evt);
}

void exit_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    if (scene->pause == false) {
        return;
    }
    pressed_button_off(obj, scene, win, evt);
    sfRenderWindow_close(win->win);
}

void resume_event_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    if (scene->pause == false) {
        return;
    }
    pressed_button_off(obj, scene, win, evt);
    toggle_pop_up(win->components, "pause");
    scene->pause = false;
}

void home_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    if (scene->pause == false) {
        return;
    }
    window_change_scene(win, "MAIN MENU");
    pressed_button_off(obj, scene, win, evt);
    list_add_to_end(win->to_remove, scene);
}
