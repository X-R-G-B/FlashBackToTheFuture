/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** event_menu
*/

#include "my_bgs_button_generator.h"
#include "main_menu.h"
#include "my_rpg.h"
#include "stage.h"
#include "audio.h"

void click_save(object_t *obj, scene_t *scene, window_t *win,
    __attribute__((unused)) set_event_t *event)
{
    if (obj == NULL || win == NULL || obj->is_visible == false) {
        win->click = NULL;
        return;
    }
    launch_story_mode(win, scene);
}

void close_window(__attribute__((unused)) object_t *obj,
    __attribute__((unused)) scene_t *scene,
    window_t *win, __attribute__((unused)) set_event_t *event)
{
    if (win == NULL || scene == NULL) {
        return;
    }
    if (check_if_pop_up_true(scene->components, PLAY) == 1 ||
        check_if_pop_up_true(win->components, SETTINGS_MENU) == 1) {
        set_is_visible_false(dico_t_get_value(scene->components, PLAY));
        set_is_visible_false(dico_t_get_value(win->components,
        SETTINGS_MENU));
        return;
    }
    sfRenderWindow_close(win->win);
}

void go_back(__attribute__((unused)) object_t *obj, scene_t *scene,
    __attribute__((unused)) window_t *win,
    __attribute__((unused)) set_event_t *event)
{
    set_is_visible_false(dico_t_get_value(scene->components, PLAY));
    set_is_visible_false(dico_t_get_value(win->components, SETTINGS_MENU));
    toggle_pop_up(win->components, PAUSE_MENU);
}

void play_pop_up(__attribute__((unused)) object_t *obj, scene_t *scene,
    window_t *win, __attribute__((unused)) set_event_t *event)
{
    list_ptr_t *buttons = NULL;

    if (win == NULL || scene == NULL) {
        return;
    }
    buttons = dico_t_get_value(scene->components, MENU);
    if (check_if_pop_up_true(win->components, SETTINGS_MENU) == 1) {
        win->click = NULL;
        set_is_visible_false(dico_t_get_value(win->components,
            SETTINGS_MENU));
    }
    play_sound(win, PARCHEMIN_SOUND);
    toggle_pop_up(scene->components, PLAY);
    if (buttons == NULL) {
        return;
    }
    obj = get_element_i_var(buttons, 1);
    obj->bigdata.sprite_bigdata.rect = (sfIntRect) {273, 9, 231, 76};
}

void settings_pop_up(__attribute__((unused)) object_t *obj, scene_t *scene,
    __attribute__((unused)) window_t *win,
    __attribute__((unused)) set_event_t *event)
{
    list_ptr_t *buttons = NULL;

    if (scene == NULL || win == NULL) {
        return;
    }
    buttons = dico_t_get_value(scene->components, MENU);
    if (buttons == NULL) {
        return;
    }
    if (check_if_pop_up_true(scene->components, PLAY) == 1) {
        win->click = NULL;
        set_is_visible_false(dico_t_get_value(scene->components, PLAY));
    }
    obj = get_element_i_var(buttons, 3);
    play_sound(win, PARCHEMIN_SOUND);
    toggle_pop_up(win->components, SETTINGS_MENU);
    obj->bigdata.sprite_bigdata.rect.left = 17;
}
