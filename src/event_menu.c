/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** event_menu
*/

#include "my_bgs_button_generator.h"
#include "menu.h"

void close_window(__attribute__((unused)) object_t *obj, scene_t *scene,
    window_t *win, __attribute__((unused)) set_event_t *event)
{
    if (check_if_pop_up_true(scene->components, PLAY))
        return;
    sfRenderWindow_close(win->win);
}

void go_back(__attribute__((unused)) object_t *obj, scene_t *scene,
    __attribute__((unused)) window_t *win,
    __attribute__((unused)) set_event_t *event)
{
    set_is_visible_false(dico_t_get_value(scene->components, PLAY));
}

void play_pop_up(__attribute__((unused)) object_t *obj, scene_t *scene,
    __attribute__((unused)) window_t *win,
    __attribute__((unused)) set_event_t *event)
{
    toggle_pop_up(scene->components, PLAY);
}
