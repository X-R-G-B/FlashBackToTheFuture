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
#include "my_strings.h"

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
        ret = scene_handling(&window, timer, window->loading->scene_name);
        if (ret == BGS_OK) {
            ret = event_handling(window->win);
        }
        need_terminate = get_state(window->loading);
    }
    sfClock_destroy(timer->clock);
    free(timer);
}

int launch_scene_loading(window_t *window, const char *scene_name)
{
    if (window == NULL || window->loading == NULL ||
            window->loading->thread != NULL) {
        return (BGS_ERR_INPUT);
    }
    window->loading->scene_name = NULL;
    window->loading->thread = sfThread_create(scene_loading_loop, window);
    if (window->loading->thread == NULL) {
        return (BGS_ERR_MALLOC);
    }
    window->loading->scene_name = my_strdup(scene_name);
    if (window->loading->scene_name == NULL) {
        sfThread_destroy(window->loading->thread);
        return (BGS_ERR_MALLOC);
    }
    window->loading->countor += 1;
    sfThread_launch(window->loading->thread);
    return (BGS_OK);
}
