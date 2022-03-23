/*
** EPITECH PROJECT, 2022
** bgs lib
** File description:
** start
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my_bgs.h"

void window_toglle_vsync(window_t *win)
{
    static sfBool is_vsynced = sfFalse;

    if (is_vsynced == sfFalse) {
        sfRenderWindow_setVerticalSyncEnabled(win->win, sfTrue);
        is_vsynced = sfTrue;
    } else {
        sfRenderWindow_setVerticalSyncEnabled(win->win, sfFalse);
        is_vsynced = sfFalse;
    }
}

void window_set_framerate_limit(window_t *win, unsigned int limit)
{
    sfRenderWindow_setFramerateLimit(win->win, limit);
}

window_t *create_window(sfVideoMode mode, const char *title, sfUint32 style)
{
    window_t *win = malloc(sizeof(window_t));

    if (win == NULL || title == NULL) {
        return NULL;
    }
    win->components = NULL;
    win->win = sfRenderWindow_create(mode, title, style, NULL);
    if (win->win == NULL) {
        return NULL;
    }
    win->scenes = list_create();
    if (win->scenes == NULL) {
        return NULL;
    }
    win->click_prev_call = false;
    win->scene_index = 0;
    return win;
}
