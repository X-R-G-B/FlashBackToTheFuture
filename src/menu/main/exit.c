/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** exit
*/

#include "my_bgs.h"

void exit_game(__attribute__((unused)) object_t *obj,
    __attribute__((unused)) scene_t *scene, window_t *win,
    __attribute__((unused)) set_event_t *event)
{
    if (win == NULL) {
        return;
    }
    sfRenderWindow_close(win->win);
}
