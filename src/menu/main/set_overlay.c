/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** set_overlay
*/

#include "main_menu.h"

void set_sandbox_overlay(__attribute__((unused)) object_t *obj,
    scene_t *scene, __attribute__((unused)) window_t *win,
    __attribute__((unused)) set_event_t *event)
{
    list_ptr_t *list = NULL;
    object_t *overlay = NULL;

    if (scene == NULL) {
        return;
    }
    list = dico_t_get_value(scene->components, MENU);
    if (list == NULL) {
        return;
    }
    overlay = get_element_i_var(list, 5);
    if (overlay == NULL) {
        return;
    }
    overlay->bigdata.sprite_bigdata.pos = (sfVector2f) {340.0, 500.0};
}

void set_play_overlay(__attribute__((unused)) object_t *obj,
    scene_t *scene,
    __attribute__((unused)) window_t *win,
    __attribute__((unused)) set_event_t *event)
{
    list_ptr_t *list = NULL;
    object_t *overlay = NULL;

    if (scene == NULL) {
        return;
    }
    list = dico_t_get_value(scene->components, MENU);
    if (list == NULL) {
        return;
    }
    overlay = get_element_i_var(list, 5);
    if (overlay == NULL) {
        return;
    }
    overlay->bigdata.sprite_bigdata.pos = (sfVector2f) {340.0, 375.0};
}

void set_settings_overlay(__attribute__((unused)) object_t *obj,
    scene_t *scene,
    __attribute__((unused)) window_t *win,
    __attribute__((unused))set_event_t *event)
{
    list_ptr_t *list = NULL;
    object_t *overlay = NULL;

    if (scene == NULL) {
        return;
    }
    list = dico_t_get_value(scene->components, MENU);
    if (list == NULL) {
        return;
    }
    overlay = get_element_i_var(list, 5);
    if (overlay == NULL) {
        return;
    }
    overlay->bigdata.sprite_bigdata.pos = (sfVector2f) {340.0, 615.0};
}

void set_exit_overlay(__attribute__((unused)) object_t *obj,
    scene_t *scene,
    __attribute__((unused)) window_t *win,
    __attribute__((unused)) set_event_t *event)
{
    list_ptr_t *list = NULL;
    object_t *overlay = NULL;

    if (scene == NULL) {
        return;
    }
    list = dico_t_get_value(scene->components, MENU);
    if (list == NULL) {
        return;
    }
    overlay = get_element_i_var(list, 5);
    if (overlay == NULL) {
        return;
    }
    overlay->bigdata.sprite_bigdata.pos = (sfVector2f) {325.0, 735.0};
}
