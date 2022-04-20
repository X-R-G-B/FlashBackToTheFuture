/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** on_click_event
*/

#include "main_menu.h"

void click_play(__attribute__((unused)) object_t *obj,
    scene_t *scene,
    __attribute__((unused)) window_t *win,
    __attribute__((unused)) set_event_t *event)
{
    list_ptr_t *buttons = NULL;
    object_t *play = NULL;

    if (scene == NULL) {
        return;
    }
    buttons = dico_t_get_value(scene->components, MENU);
    if (buttons == NULL) {
        return;
    }
    play = get_element_i_var(buttons, 1);
    play->bigdata.sprite_bigdata.rect.left = 8;
}

void click_settings(__attribute__((unused)) object_t *obj,
    scene_t *scene,
    __attribute__((unused)) window_t *win,
    __attribute__((unused)) set_event_t *event)
{
    list_ptr_t *buttons = NULL;
    object_t *settings = NULL;

    if (scene == NULL) {
        return;
    }
    buttons = dico_t_get_value(scene->components, MENU);
    if (buttons == NULL) {
        return;
    }
    settings = get_element_i_var(buttons, 2);
    settings->bigdata.sprite_bigdata.rect.left = 486;
}

void click_exit(__attribute__((unused)) object_t *obj,
    scene_t *scene,
    __attribute__((unused)) window_t *win,
    __attribute__((unused)) set_event_t *event)
{
    list_ptr_t *buttons = NULL;
    object_t *exit = NULL;

    if (scene == NULL) {
        return;
    }
    buttons = dico_t_get_value(scene->components, MENU);
    if (buttons == NULL) {
        return;
    }
    exit = get_element_i_var(buttons, 0);
    exit->bigdata.sprite_bigdata.rect.left = 243;
}
