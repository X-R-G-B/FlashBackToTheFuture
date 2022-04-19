/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** set_frame
*/

#include "main_menu.h"

void set_60_fps(__attribute__((unused)) object_t *obj,
    __attribute__((unused)) scene_t *scene,
    window_t *win, __attribute__((unused)) set_event_t *event)
{
    sfRenderWindow_setFramerateLimit(win->win, 60);
}

void set_120_fps(__attribute__((unused)) object_t *obj,
    __attribute__((unused)) scene_t *scene, window_t *win,
    __attribute__((unused)) set_event_t *event)
{
    sfRenderWindow_setFramerateLimit(win->win, 120);
}

void set_144_fps(__attribute__((unused)) object_t *obj,
    __attribute__((unused)) scene_t *scene,
    window_t *win,
    __attribute__((unused)) set_event_t *event)
{
    sfRenderWindow_setFramerateLimit(win->win, 144);
}

void set_165_fps(__attribute__((unused)) object_t *obj,
    __attribute__((unused)) scene_t *scene, window_t *win,
    __attribute__((unused)) set_event_t *event)
{
    sfRenderWindow_setFramerateLimit(win->win, 165);
}
