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
#include "my_dico.h"
#include "my_strings.h"

int window_change_scene(window_t *window, const char *scene_name)
{
    if (window == NULL || scene_name == NULL) {
        return (BGS_ERR_INPUT);
    }
    if (window->current_scene != NULL) {
        free(window->current_scene);
    }
    window->current_scene = my_strdup(scene_name);
    if (window->current_scene == NULL) {
        return (BGS_ERR_MALLOC);
    }
    return (BGS_OK);
}

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
    dico_t *dict = NULL;

    if (timer == NULL || win == NULL || win->scenes == NULL) {
        return 0;
    }
    while (sfRenderWindow_isOpen(win->win) && ret == BGS_OK) {
        ret = scene_handling(&win, timer, win->current_scene);
        dict = win->scenes;
        //printf("\nframe*****\n");
        do {
            //printf("dico key: %s\n", dict->key);
            dict = dict->next;
        } while (dict != win->scenes);
        if (ret == BGS_OK) {
            ret = event_handling(win->win);
        }
    }
    destroy_loop_data(win, timer, ret);
    return ret;
}
