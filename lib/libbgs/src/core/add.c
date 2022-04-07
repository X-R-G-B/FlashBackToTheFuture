/*
** EPITECH PROJECT, 2022
** bgs
** File description:
** add object
*/

#include <stdlib.h>
#include "my_bgs.h"
#include "my_bgs_components.h"
#include "libbgs_private.h"
#include "my_dico.h"

int window_add_scene(window_t *win, scene_t *scene, const char *scene_name)
{
    if (win == NULL || scene == NULL) {
        return BGS_ERR_INPUT;
    }
    win->scenes = dico_t_add_data(win->scenes, scene_name, scene,
            remove_scene);
    if (win->scenes == NULL) {
        return (BGS_ERR_MALLOC);
    }
    return BGS_OK;
}

static int add_obj_in_layer(layer_t *layer, object_t *obj)
{
    if (list_add_to_end(layer->object, obj) == NULL ||
        (obj->update != NULL && list_add_to_end(layer->updates, obj) == NULL) ||
        (obj->display != NULL &&
        list_add_to_end(layer->displayables, obj) == NULL)) {
        return BGS_ERR_MALLOC;
    }
    return BGS_OK;
}

static int create_layer(scene_t *scene, object_t *object, int id, int pos)
{
    layer_t *layer = malloc(sizeof(layer_t));

    if (layer == NULL) {
        return BGS_ERR_MALLOC;
    }
    layer->id = id;
    layer->displayables = list_create();
    layer->object = list_create();
    layer->updates = list_create();
    if (layer->displayables == NULL || layer->object == NULL ||
        layer->updates == NULL || (pos >= 0 &&
        list_add_to_i(scene->layer, layer, pos) == NULL) || (pos < 0 &&
        list_add_to_end(scene->layer, layer) == NULL)) {
        return BGS_ERR_MALLOC;
    }
    return add_obj_in_layer(layer, object);
}

static int add_to_layer(scene_t *scene, object_t *object, int layer)
{
    list_t *elem = scene->layer->start;
    layer_t *ptr = NULL;

    if (scene->layer->len == 0) {
        return create_layer(scene, object, layer, 0);
    }
    for (int i = 0; i < scene->layer->len; i++, elem = elem->next) {
        ptr = elem->var;
        if (layer < ptr->id) {
            return create_layer(scene, object, layer, i);
        } else if (layer == ptr->id) {
            return add_obj_in_layer(ptr, object);
        }
    }
    return create_layer(scene, object, layer, -1);
}

int scene_add_object(scene_t *scene, object_t *object, int layer)
{
    if (scene == NULL || object == NULL) {
        return BGS_ERR_INPUT;
    }
    if (add_to_layer(scene, object, layer) != BGS_OK) {
        return BGS_ERR_MALLOC;
    } else if (object->type == UNSET &&
            list_add_to_end(scene->objects, object) == NULL) {
        return BGS_ERR_MALLOC;
    }
    return BGS_OK;
}
