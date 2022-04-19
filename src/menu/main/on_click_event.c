/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** on_click_event
*/

#include "main_menu.h"

void click_play(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *event)
{
    list_ptr_t *buttons = NULL;
    object_t *play = NULL;

    if (scene == NULL) {
        return;
    }
    buttons  = dico_t_get_value(scene->components, MENU);
    if (buttons == NULL) {
        return;
    }
    play = get_element_i_var(buttons, 1);
    obj->bigdata.sprite_bigdata.rect.left = 8;
}

void click_settings(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *event)
{
    list_ptr_t *buttons = NULL;
    object_t *settings = NULL;

    if (scene == NULL) {
        return;
    }
    buttons  = dico_t_get_value(scene->components, MENU);
    if (buttons == NULL) {
        return;
    }
    settings = get_element_i_var(buttons, 2);
    obj->bigdata.sprite_bigdata.rect.left = 486;
}

void click_exit(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *event)
{
    list_ptr_t *buttons = NULL;
    object_t *exit = NULL;

    if (scene == NULL) {
        return;
    }
    buttons  = dico_t_get_value(scene->components, MENU);
    if (buttons == NULL) {
        return;
    }
    exit = get_element_i_var(buttons, 1);
    obj->bigdata.sprite_bigdata.rect.left = 243;
}
