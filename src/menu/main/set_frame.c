/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** set_frame
*/

#include "main_menu.h"

void set_60_fps(__attribute__((unused)) object_t *obj, scene_t *scene,
    window_t *win, __attribute__((unused)) set_event_t *event)
{
    list_ptr_t *list = dico_t_get_value(scene->components, SETTINGS_MENU);
    object_t *circle = NULL;

    if (list == NULL) {
        return;
    }
    circle = get_element_i_var(list, 7);
    if (circle == NULL) {
        return;
    }
    sfRenderWindow_setFramerateLimit(win->win, 60);
    circle->bigdata.sprite_bigdata.pos = (sfVector2f) {860.0, 740.0};
}

void set_120_fps(__attribute__((unused)) object_t *obj,
    scene_t *scene, window_t *win,
    __attribute__((unused)) set_event_t *event)
{
    list_ptr_t *list = dico_t_get_value(scene->components, SETTINGS_MENU);
    object_t *circle = NULL;

    if (list == NULL) {
        return;
    }
    circle = get_element_i_var(list, 7);
    if (circle == NULL) {
        return;
    }
    sfRenderWindow_setFramerateLimit(win->win, 120);
    circle->bigdata.sprite_bigdata.pos = (sfVector2f) {1020.0, 740.0};
}

void set_144_fps(__attribute__((unused)) object_t *obj,
    scene_t *scene,
    window_t *win,
    __attribute__((unused)) set_event_t *event)
{
    list_ptr_t *list = dico_t_get_value(scene->components, SETTINGS_MENU);
    object_t *circle = NULL;

    if (list == NULL) {
        return;
    }
    circle = get_element_i_var(list, 7);
    if (circle == NULL) {
        return;
    }
    sfRenderWindow_setFramerateLimit(win->win, 144);
    circle->bigdata.sprite_bigdata.pos = (sfVector2f) {1220.0, 740.0};
}

void set_165_fps(__attribute__((unused)) object_t *obj,
    scene_t *scene, window_t *win,
    __attribute__((unused)) set_event_t *event)
{
    list_ptr_t *list = dico_t_get_value(scene->components, SETTINGS_MENU);
    object_t *circle = NULL;

    if (list == NULL) {
        return;
    }
    circle = get_element_i_var(list, 7);
    if (circle == NULL) {
        return;
    }
    sfRenderWindow_setFramerateLimit(win->win, 165);
    circle->bigdata.sprite_bigdata.pos = (sfVector2f) {1430.0, 740.0};
}
