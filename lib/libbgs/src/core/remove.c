/*
** EPITECH PROJECT, 2022
** bgs
** File description:
** remove
*/

#include <SFML/System/Mutex.h>
#include <SFML/System/Thread.h>
#include <stdlib.h>
#include "list.h"
#include "my_bgs.h"
#include "libbgs_private.h"
#include "my_dico.h"

void remove_object(object_t *object)
{
    switch (object->type) {
        case SPRITE:
            sfSprite_destroy(object->drawable.sprite);
            sfTexture_destroy(object->bigdata.sprite_bigdata.texture);
            break;
        case TEXT:
            sfText_destroy(object->drawable.text);
            sfFont_destroy(object->bigdata.text_bigdata.font);
            break;
        case AUDIO:
            sfMusic_setLoop(object->drawable.music, sfFalse);
            sfMusic_stop(object->drawable.music);
            sfMusic_destroy(object->drawable.music);
            break;
        default:
            break;
    }
    dico_t_destroy(object->components);
    free(object);
}

static void destroy_plan(list_ptr_t *list)
{
    list_t *elem = NULL;
    plan_t *plan = NULL;

    if (list == NULL) {
        return;
    }
    elem = list->start;
    for (int i = 0; i < list->len; i++, elem = elem->next) {
        plan = elem->var;
        free_list(plan->displayables);
        free_list(plan->updates);
        free_list(plan->object);
        free(plan);
    }
    free_list(list);
}

void remove_scene(void *scene_void)
{
    scene_t *scene = scene_void;
    list_t *elem = NULL;

    if (scene == NULL) {
        return;
    }
    elem = scene->objects->start;
    for (int i = 0; i < scene->objects->len; i++, elem = elem->next) {
        remove_object(((object_t *) elem->var));
    }
    if (scene->components != NULL) {
        dico_t_destroy(scene->components);
    }
    destroy_plan(scene->plan);
    free_list(scene->objects);
    if (scene->to_remove != NULL) {
        free_list(scene->to_remove);
    }
    free(scene);
}

void remove_loading_scene(window_t *win)
{
    if (win->loading == NULL) {
        return;
    }
    if (win->loading->mutex != NULL) {
        sfMutex_destroy(win->loading->mutex);
    }
    if (win->loading->thread != NULL) {
        sfThread_destroy(win->loading->thread);
    }
    if (win->loading->countor == 0) {
        sfRenderWindow_destroy(win->win);
    }
    free(win->loading);
}

void remove_window(window_t *win)
{
    if (win == NULL) {
        return;
    }
    dico_t_destroy(win->scenes);
    free_list(win->to_remove);
    dico_t_destroy(win->components);
    remove_loading_scene(win);
    if (win->current_scene != NULL) {
        free(win->current_scene);
    }
    free(win);
}
