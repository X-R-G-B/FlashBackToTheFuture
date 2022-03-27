/*
** EPITECH PROJECT, 2022
** libbgs
** File description:
** internal loop for a scene
*/

#include <stdlib.h>
#include "list.h"
#include "my_bgs.h"
#include "libbgs_private.h"
#include "my_dico.h"

void scene_loading_handling(window_t *win)
{
    if (win == NULL || win->loading == NULL || win->loading->thread == NULL) {
        return;
    }
    sfMutex_lock(win->loading->mutex);
    win->loading->need_terminate = 1;
    sfMutex_unlock(win->loading->mutex);
    sfThread_destroy(win->loading->thread);
    win->loading->need_terminate = 0;
    win->loading->thread = NULL;
    if (win->loading->scene_name != NULL) {
        free(win->loading->scene_name);
        win->loading->scene_name = NULL;
    }
}

static void window_display(scene_t *scene, window_t *win)
{
    object_t *obj = NULL;
    list_t *elem = scene->displayables->start;

    for (int i = 0; i < scene->displayables->len &&
            sfRenderWindow_isOpen(win->win); i++) {
        obj = ((object_t *) elem->var);
        obj->display(obj, scene->components, win->components, win->win);
        elem = elem->next;
        scene_loading_handling(win);
    }
    if (sfRenderWindow_isOpen(win->win)) {
        sfRenderWindow_display(win->win);
    }
}

static void window_update(scene_t *scene, window_t *win, float seconds)
{
    object_t *obj = NULL;
    list_t *elem = scene->updates->start;
    list_t *tmp;

    window_update_event(win, scene);
    scene_update_event(win, scene);
    for (int i = 0; i < scene->updates->len &&
            sfRenderWindow_isOpen(win->win); i++) {
        tmp = elem->next;
        obj = ((object_t *) elem->var);
        if (obj->components != NULL || obj->update != NULL) {
            object_update(obj, scene, win, seconds);
            scene_loading_handling(win);
        }
        elem = tmp;
    }
}

int scene_handling(window_t **win, time_clock_t *timer, const char *scene_name)
{
    scene_t *scene = NULL;

    if (win == NULL || *win == NULL || timer == NULL || scene_name == NULL) {
        return (BGS_ERR_INPUT);
    }
    scene = dico_t_get_value((*win)->scenes, scene_name);
    if (scene == NULL) {
        return BGS_ERR_INPUT;
    }
    sfRenderWindow_clear((*win)->win, scene->bg_color);
    timer->time = sfClock_restart(timer->clock);
    timer->seconds = sfTime_asSeconds(timer->time);
    window_update(scene, *win, timer->seconds);
    window_display(scene, *win);
    window_remove(scene, *win);
    return BGS_OK;
}
