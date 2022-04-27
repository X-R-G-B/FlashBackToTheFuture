/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** set_frame
*/

#include "main_menu.h"
#include "my_bgs.h"

static const int circle_i = 7;

static list_ptr_t *get_settings_components(window_t *win, object_t *obj)
{
    list_ptr_t *list = NULL;

    if (win == NULL || obj == NULL || obj->is_visible == false) {
        win->click = NULL;
        return (NULL);
    }
    list = dico_t_get_value(win->components, SETTINGS_MENU);
    return (list);
}

void set_60_fps(object_t *obj, __attribute__((unused)) scene_t *scene,
    window_t *win, __attribute__((unused)) set_event_t *event)
{
    list_ptr_t *list = NULL;
    object_t *circle = NULL;

    list = get_settings_components(win, obj);
    if (list == NULL) {
        return;
    }
    circle = get_element_i_var(list, circle_i);
    if (circle == NULL) {
        return;
    }
    window_set_framerate_limit(win, 60);
    circle->bigdata.sprite_bigdata.pos = obj->bigdata.sprite_bigdata.pos;
}

void set_120_fps(object_t *obj, __attribute__((unused)) scene_t *scene,
    window_t *win, __attribute__((unused)) set_event_t *event)
{
    list_ptr_t *list = NULL;
    object_t *circle = NULL;

    list = get_settings_components(win, obj);
    if (list == NULL) {
        return;
    }
    circle = get_element_i_var(list, circle_i);
    if (circle == NULL) {
        return;
    }
    window_set_framerate_limit(win, 120);
    circle->bigdata.sprite_bigdata.pos = obj->bigdata.sprite_bigdata.pos;
}

void set_144_fps(object_t *obj, __attribute__((unused)) scene_t *scene,
    window_t *win, __attribute__((unused)) set_event_t *event)
{
    list_ptr_t *list = NULL;
    object_t *circle = NULL;

    list = get_settings_components(win, obj);
    if (list == NULL) {
        return;
    }
    circle = get_element_i_var(list, circle_i);
    if (circle == NULL) {
        return;
    }
    window_set_framerate_limit(win, 144);
    circle->bigdata.sprite_bigdata.pos = obj->bigdata.sprite_bigdata.pos;
}

void set_165_fps(object_t *obj, __attribute__((unused)) scene_t *scene,
    window_t *win, __attribute__((unused)) set_event_t *event)
{
    list_ptr_t *list = NULL;
    object_t *circle = NULL;

    list = get_settings_components(win, obj);
    if (list == NULL) {
        return;
    }
    circle = get_element_i_var(list, circle_i);
    if (circle == NULL) {
        return;
    }
    window_set_framerate_limit(win, 165);
    circle->bigdata.sprite_bigdata.pos = obj->bigdata.sprite_bigdata.pos;
}
