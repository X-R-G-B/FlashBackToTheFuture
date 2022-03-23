/*
** EPITECH PROJECT, 2022
** bgs
** File description:
** loop
*/

#include <stdlib.h>
#include "my_bgs.h"
#include "my_bgs_components.h"
#include "libbgs_private.h"

static void window_display(scene_t *scene, window_t *win)
{
    object_t *obj = NULL;
    list_t *elem = scene->displayables->start;

    for (int i = 0; i < scene->displayables->len; i++) {
        obj = ((object_t *) elem->var);
        obj->display(obj, scene->components, win->components, win->win);
        elem = elem->next;
    }
    sfRenderWindow_display(win->win);
}

static void window_update(scene_t *scene, window_t *win, float seconds)
{
    object_t *obj = NULL;
    list_t *elem = scene->updates->start;
    list_t *tmp;

    window_update_event(win, scene);
    scene_update_event(win, scene);
    for (int i = 0; i < scene->updates->len; i++) {
        tmp = elem->next;
        obj = ((object_t *) elem->var);
        if (obj->components != NULL || obj->update != NULL) {
            object_update(obj, scene, win, seconds);
        }
        elem = tmp;
    }
}

static time_clock_t *init_clock(void)
{
    time_clock_t *timer = malloc(sizeof(time_clock_t));

    if (timer == NULL) {
        return NULL;
    }
    timer->clock = sfClock_create();
    return timer;
}

static int scene_handling(window_t **win, scene_t **scene, time_clock_t *timer)
{
    static int last_index = -1;

    if (last_index != (*win)->scene_index) {
        *scene = get_scene_i((*win)->scenes, (*win)->scene_index);
        last_index = (*win)->scene_index;
    }
    if (*scene == NULL) {
        return BGS_ERR_INPUT;
    }
    sfRenderWindow_clear((*win)->win, (*scene)->bg_color);
    timer->time = sfClock_restart(timer->clock);
    timer->seconds = sfTime_asSeconds(timer->time);
    window_update(*scene, *win, timer->seconds);
    window_display(*scene, *win);
    window_remove(*scene, *win);
    return BGS_OK;
}

int loop(window_t *win)
{
    int ret = BGS_OK;
    scene_t *scene = NULL;
    time_clock_t *timer = init_clock();

    if (timer == NULL || win->scenes->len == 0) {
        return 0;
    }
    window_setup_scene(win);
    while (sfRenderWindow_isOpen(win->win) && ret == BGS_OK) {
        ret = scene_handling(&win, &scene, timer);
        if (ret == BGS_OK) {
            ret = event_handling(win->win, win);
        }
    }
    if (ret != BGS_OK) {
        sfRenderWindow_close(win->win);
    }
    sfClock_destroy(timer->clock);
    free(timer);
    return ret;
}
