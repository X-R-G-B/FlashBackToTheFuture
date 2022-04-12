/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** event_menu
*/

#include "my_bgs_button_generator.h"
#include "main_menu.h"
#include "my_rpg.h"

void click_save(__attribute__((unused)) object_t *obj,
    __attribute__((unused)) scene_t *scene, window_t *win,
    __attribute__((unused)) set_event_t *event)
{
    launch_story_mode(win, STORY_DATA_PATH);
}

void close_window(__attribute__((unused)) object_t *obj,
    __attribute__((unused)) scene_t *scene,
    window_t *win, __attribute__((unused)) set_event_t *event)
{
    sfRenderWindow_close(win->win);
}

void go_back(__attribute__((unused)) object_t *obj, scene_t *scene,
    __attribute__((unused)) window_t *win,
    __attribute__((unused)) set_event_t *event)
{
    /*set_is_visible_false(dico_t_get_value(scene->components, PLAY));
    set_is_visible_false(dico_t_get_value(scene->components, SETTINGS_MENU));*/
}

void play_pop_up(__attribute__((unused)) object_t *obj, scene_t *scene,
    __attribute__((unused)) window_t *win,
    __attribute__((unused)) set_event_t *event)
{
    if (check_if_pop_up_true(scene->components, SETTINGS_MENU)) {
        set_is_visible_false(dico_t_get_value(scene->components,
            SETTINGS_MENU));
    }
    toggle_pop_up(scene->components, PLAY);
}

void settings_pop_up(__attribute__((unused)) object_t *obj, scene_t *scene,
    __attribute__((unused)) window_t *win,
    __attribute__((unused)) set_event_t *event)
{
    if (check_if_pop_up_true(scene->components, PLAY)) {
        set_is_visible_false(dico_t_get_value(scene->components, PLAY));
    }
    toggle_pop_up(scene->components, SETTINGS_MENU);
}
