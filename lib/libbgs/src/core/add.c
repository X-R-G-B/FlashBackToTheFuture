/*
** EPITECH PROJECT, 2022
** bgs
** File description:
** add object
*/

#include "my_bgs.h"
#include "my_bgs_components.h"
#include "libbgs_private.h"

int window_add_scene(window_t *win, scene_t *scene)
{
    if (win == NULL || scene == NULL) {
        return BGS_ERR_INPUT;
    }
    if (list_add_to_end(win->scenes, scene) == NULL) {
        return BGS_ERR_MALLOC;
    }
    return BGS_OK;
}

int add_object_to_lists(scene_t *scene, object_t *object)
{
    int ret = BGS_OK;

    if (object == NULL || scene == NULL) {
        return BGS_ERR_INPUT;
    }
    if (object->display != NULL) {
        if (list_add_to_end(scene->displayables, object) == NULL) {
            ret = BGS_ERR_MALLOC;
        }
    }
    if (object->update != NULL || object->components != NULL) {
        if (list_add_to_end(scene->updates, object) == NULL) {
            ret = BGS_ERR_MALLOC;
        }
    }
    return ret;
}

void check_scene(scene_t *scene)
{
    list_t *object_elem = NULL;
    object_t *object = NULL;

    if (scene == NULL) {
        return;
    }
    object_elem = scene->objects->start;
    for (int x = 0; x < scene->objects->len; x++) {
        object = ((object_t *) object_elem->var);
        add_object_to_lists(scene, object);
        object_elem = object_elem->next;
    }
}

void window_setup_scene(window_t *win)
{
    list_t *scene_elem = NULL;
    scene_t *scene = NULL;

    if (win == NULL || win->scenes == NULL) {
        return;
    }
    scene_elem = win->scenes->start;
    for (int i = 0; i < win->scenes->len; i++) {
        scene = ((scene_t *) scene_elem->var);
        check_scene(scene);
        scene_elem = scene_elem->next;
    }
}

int scene_add_object(scene_t *scene, object_t *object)
{
    if (scene == NULL || object == NULL) {
        return BGS_ERR_INPUT;
    }
    if (object->type == UNSET &&
            list_add_to_end(scene->objects, object) == NULL) {
        return BGS_ERR_MALLOC;
    }
    return BGS_OK;
}
