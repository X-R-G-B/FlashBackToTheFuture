/*
** EPITECH PROJECT, 2022
** libbgs
** File description:
** scene loading thread
*/

#include <SFML/System/Clock.h>
#include <SFML/System/Mutex.h>
#include <SFML/System/Thread.h>
#include <stdlib.h>
#include "my_bgs.h"
#include "libbgs_private.h"

static int get_state(scene_loading_t *load)
{
    int terminate = 0;

    if (load == NULL) {
        return (1);
    }
    sfMutex_lock(load->mutex);
    terminate = load->need_terminate;
    sfMutex_unlock(load->mutex);
    return (terminate);
}

static void scene_loading_loop(void *win)
{
    int ret = BGS_OK;
    int need_terminate = 0;
    time_clock_t *timer = init_clock();
    window_t *window = win;

    if (window == NULL || window->loading == NULL ||
            window->loading->thread == NULL || timer == NULL) {
        return;
    }
    while (sfRenderWindow_isOpen(window->win) && ret == BGS_OK &&
            need_terminate == 0) {
        ret = scene_handling(&window, timer, window->loading->index);
        if (ret == BGS_OK) {
            ret = event_handling(window->win, window);
        }
        need_terminate = get_state(window->loading);
    }
    sfClock_destroy(timer->clock);
    free(timer);
}

int launch_scene_loading(window_t *window, int index)
{
    if (window == NULL || window->loading == NULL ||
            window->loading->thread != NULL) {
        return (BGS_ERR_INPUT);
    }
    window->loading->thread = sfThread_create(scene_loading_loop, window);
    window->loading->index = index;
    if (window->loading->thread != NULL) {
        sfThread_launch(window->loading->thread);
    }
    return (BGS_OK);
}
