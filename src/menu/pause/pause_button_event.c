/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** pause button event
*/

#include "my_rpg.h"
#include "my_bgs_button_generator.h"
#include "main_menu.h"

void settings_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    if (scene->pause == false) {
        pressed_button_off(obj, scene, win, evt);
        return;
    }
    toggle_pop_up(scene->components, SETTINGS_MENU);
    pressed_button_off(obj, scene, win, evt);
}

void restart_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    if (scene->pause == false) {
        pressed_button_off(obj, scene, win, evt);
        return;
    }
    pressed_button_off(obj, scene, win, evt);
}

void exit_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    if (scene->pause == false) {
        pressed_button_off(obj, scene, win, evt);
        return;
    }
    pressed_button_off(obj, scene, win, evt);
    sfRenderWindow_close(win->win);
}

void resume_event_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    if (scene->pause == false) {
        pressed_button_off(obj, scene, win, evt);
        return;
    }
    pressed_button_off(obj, scene, win, evt);
    set_is_visible_false(dico_t_get_value(scene->components, SETTINGS_MENU));
    toggle_pop_up(win->components, "pause");
    scene->pause = false;
}

void home_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    if (scene->pause == false) {
        pressed_button_off(obj, scene, win, evt);
        return;
    }
    go_to_home(scene, win);
    pressed_button_off(obj, scene, win, evt);
}