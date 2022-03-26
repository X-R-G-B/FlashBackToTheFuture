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

bool check_list(list_ptr_t *list, void *data)
{
    list_t *elem = list->start;

    for (int i = 0; i < list->len; i++, elem = elem->next) {
        if (elem->var == data) {
            rm_elem_i(list, i);
            return true;
        }
    }
    return false;
}

void remove_object(object_t *object)
{
    switch (object->type) {
        case SPRITE:
            sfSprite_destroy(object->drawable.sprite);
            sfTexture_destroy(object->bigdata.sprite_bigdata.texture);
            sfImage_destroy(object->bigdata.sprite_bigdata.image);
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

void remove_scene(scene_t *scene)
{
    list_t *elem = scene->objects->start;

    for (int i = 0; i < scene->objects->len; i++, elem = elem->next) {
        remove_object(((object_t *) elem->var));
    }
    if (scene->components != NULL) {
        dico_t_destroy(scene->components);
    }
    free_list(scene->displayables);
    free_list(scene->updates);
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
    //if (win->loading->is_end == 0) {
    //sfRenderWindow_destroy(win->win);
    //}
    free(win->loading);
}

void remove_window(window_t *win)
{
    list_t *elem = NULL;
    scene_t *scene = NULL;

    if (win == NULL) {
        return;
    }
    elem = win->scenes->start;
    for (int i = 0; i < win->scenes->len; i++) {
        scene = ((scene_t *) elem->var);
        remove_scene(scene);
        elem = elem->next;
    }
    free_list(win->scenes);
    free_list(win->to_remove);
    dico_t_destroy(win->components);
    remove_loading_scene(win);
    free(win);
}
