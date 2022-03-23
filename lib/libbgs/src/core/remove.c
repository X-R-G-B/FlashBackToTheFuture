/*
** EPITECH PROJECT, 2022
** bgs
** File description:
** remove
*/

#include <stdlib.h>
#include "list.h"
#include "my_bgs.h"

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

void window_remove(scene_t *scene, window_t *win)
{
    object_t *elem = NULL;

    if (scene->to_remove == NULL) {
        check_list(win->scenes, scene);
        remove_scene(scene);
        return;
    }
    if (scene == NULL || scene->to_remove->len == 0) {
        return;
    }
    elem = scene->to_remove->start->var;
    for (; scene->to_remove->len > 0; elem = (scene->to_remove->start != NULL)
        ? scene->to_remove->start->var : NULL) {
        if (check_list(scene->objects, elem) == true) {
            check_list(scene->displayables, elem);
            check_list(scene->updates, elem);
            rm_fst_elem(scene->to_remove);
            remove_object(elem);
        }
    }
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

void remove_window(window_t *win)
{
    list_t *elem = win->scenes->start;
    scene_t *scene = NULL;

    for (int i = 0; i < win->scenes->len; i++) {
        scene = ((scene_t *) elem->var);
        remove_scene(scene);
        elem = elem->next;
    }
    free_list(win->scenes);
    dico_t_destroy(win->components);
    sfRenderWindow_destroy(win->win);
    free(win);
}
