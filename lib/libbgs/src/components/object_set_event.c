/*
** EPITECH PROJECT, 2022
** Defender
** File description:
** object set event
*/

#include <stdlib.h>
#include "my_strings.h"
#include "my_bgs.h"
#include "my_bgs_components.h"
#include "../include/libbgs_private.h"

void destroy_event(void *data)
{
    set_event_t *event = data;
    list_t *elem = NULL;

    if (event == NULL) {
        return;
    }
    if (event->list_event == NULL) {
        free(event);
        return;
    }
    elem = event->list_event->start;
    for (int i = 0; i < event->list_event->len; i++, elem = elem->next) {
        free(elem->var);
    }
    free_list(event->list_event);
    free(event);
}

static bool check_elem_in_list(list_ptr_t *list, void *data)
{
    list_t *elem = list->start;

    for (int i = 0; i < list->len; i++, elem = elem->next) {
        if (elem->var == data) {
            return true;
        }
    }
    return false;
}

layer_t *get_layer(scene_t *scene, int layer)
{
    list_t *elem = scene->layer->start;
    layer_t *layer_elem = NULL;

    for (int i = 0; i < scene->layer->len; i++, elem = elem->next) {
        layer_elem = elem->var;
        if (layer_elem->id == layer) {
            return layer_elem;
        }
    }
    return NULL;
}

static void check_obj_in_update_list(object_t *obj)
{
    scene_t *scene = dico_t_get_value(obj->components, "scene");
    layer_t *layer = NULL;

    if (scene == NULL) {
        return;
    }
    layer = get_layer(scene, obj->layer);
    if (layer == NULL) {
        return;
    }
    if (check_elem_in_list(layer->updates, obj) == false) {
        list_add_to_end(layer->updates, obj);
    }
}

int object_set_event(object_t *object, set_event_t *event)
{
    char key[255] = {0};

    my_strcpy(key, SET_EVENT);
    if (object == NULL || event == NULL) {
        return BGS_ERR_INPUT;
    }
    if (event == NULL) {
        return BGS_ERR_MALLOC;
    }
    get_id_generator_cat(key);
    object->components = dico_t_add_data(object->components, key, event,
            &destroy_event);
    check_obj_in_update_list(object);
    return (BGS_OK);
}
