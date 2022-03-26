/*
** EPITECH PROJECT, 2022
** bgs
** File description:
** loop
*/

#include <SFML/System/Mutex.h>
#include <SFML/System/Thread.h>
#include <stdlib.h>
#include "my_bgs.h"
#include "my_bgs_components.h"
#include "libbgs_private.h"

time_clock_t *init_clock(void)
{
    time_clock_t *timer = malloc(sizeof(time_clock_t));

    if (timer == NULL) {
        return NULL;
    }
    timer->clock = sfClock_create();
    return timer;
}

static void destroy_loop_data(window_t *win, time_clock_t *timer, int ret)
{
    if (ret != BGS_OK) {
        sfRenderWindow_close(win->win);
    }
    sfClock_destroy(timer->clock);
    free(timer);
}

int loop(window_t *win)
{
    int ret = BGS_OK;
    time_clock_t *timer = init_clock();

    if (timer == NULL || win == NULL || win->scenes->len == 0) {
        return 0;
    }
    window_setup_scene(win);
    while (sfRenderWindow_isOpen(win->win) && ret == BGS_OK) {
        ret = scene_handling(&win, timer, win->scene_index);
        if (ret == BGS_OK) {
            ret = event_handling(win->win, win);
        }
    }
    destroy_loop_data(win, timer, ret);
    return ret;
}
