/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** set_frame
*/

#include "main_menu.h"

static list_ptr_t *get_settings_components(scene_t *scene)
{
    list_ptr_t *list = NULL;

    if (scene == NULL) {
        return (NULL);
    }
    list = dico_t_get_value(scene->components, SETTINGS_MENU);
    return (list);
}

void set_60_fps(object_t *obj, scene_t *scene,
    window_t *win, __attribute__((unused)) set_event_t *event)
{
    list_ptr_t *list = NULL;
    object_t *circle = NULL;

    list = get_settings_components(scene);
    if (list == NULL) {
        return;
    }
    circle = get_element_i_var(list, 7);
    if (circle == NULL) {
        return;
    }
    sfRenderWindow_setFramerateLimit(win->win, 60);
    circle->bigdata.sprite_bigdata.pos = obj->bigdata.sprite_bigdata.pos;
}

void set_120_fps(object_t *obj,
    scene_t *scene, window_t *win,
    __attribute__((unused)) set_event_t *event)
{
    list_ptr_t *list = NULL;
    object_t *circle = NULL;

    list = get_settings_components(scene);
    if (list == NULL) {
        return;
    }
    circle = get_element_i_var(list, 7);
    if (circle == NULL) {
        return;
    }
    sfRenderWindow_setFramerateLimit(win->win, 120);
    circle->bigdata.sprite_bigdata.pos = obj->bigdata.sprite_bigdata.pos;
}

void set_144_fps(object_t *obj,
    scene_t *scene,
    window_t *win,
    __attribute__((unused)) set_event_t *event)
{
    list_ptr_t *list = NULL;
    object_t *circle = NULL;

    list = get_settings_components(scene);
    if (list == NULL) {
        return;
    }
    circle = get_element_i_var(list, 7);
    if (circle == NULL) {
        return;
    }
    sfRenderWindow_setFramerateLimit(win->win, 144);
    circle->bigdata.sprite_bigdata.pos = obj->bigdata.sprite_bigdata.pos;
}

void set_165_fps(object_t *obj,
    scene_t *scene, window_t *win,
    __attribute__((unused)) set_event_t *event)
{
    list_ptr_t *list = NULL;
    object_t *circle = NULL;

    list = get_settings_components(scene);
    if (list == NULL) {
        return;
    }
    circle = get_element_i_var(list, 7);
    if (circle == NULL) {
        return;
    }
    sfRenderWindow_setFramerateLimit(win->win, 165);
    circle->bigdata.sprite_bigdata.pos = obj->bigdata.sprite_bigdata.pos;
}
