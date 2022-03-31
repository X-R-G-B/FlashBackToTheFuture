/*
** EPITECH PROJECT, 2022
** bgs lib
** File description:
** start
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "libbgs_private.h"
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

static void create_scene_loading(window_t *win)
{
    if (win == NULL) {
        return;
    }
    win->loading = malloc(sizeof(scene_loading_t));
    if (win->loading == NULL) {
        return;
    }
    win->loading->mutex = sfMutex_create();
    if (win->loading->mutex == NULL) {
        free(win->loading);
        win->loading = NULL;
    }
    win->loading->thread = NULL;
    win->loading->need_terminate = 0;
    win->loading->countor = 0;
    win->loading->scene_name = NULL;
}

window_t *create_window(sfVideoMode mode, const char *title, sfUint32 style)
{
    window_t *win = malloc(sizeof(window_t));

    if (win == NULL || title == NULL) {
        return NULL;
    }
    win->components = NULL;
    win->win = sfRenderWindow_create(mode, title, style, NULL);
    sfRenderWindow_setPosition(win->win, (sfVector2i) {0, 0});
    if (win->win == NULL) {
        return NULL;
    }
    win->scenes = NULL;
    win->to_remove = list_create();
    if (win->to_remove == NULL) {
        return NULL;
    }
    win->click = NULL;
    win->current_scene = NULL;
    create_scene_loading(win);
    return win;
}
