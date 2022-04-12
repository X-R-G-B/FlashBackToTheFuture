/*
** EPITECH PROJECT, 2022
** libbgs
** File description:
** obj_change_scene
*/

#include "my_bgs.h"
#include "libbgs_private.h"

static int change_scene_in_obj_components(object_t *obj, scene_t *dest)
{
    obj->components = dico_t_rem(obj->components, "scene");
    obj->components = dico_t_add_data(obj->components, "scene", dest, NULL);
    if (obj->components == NULL) {
        return BGS_ERR_MALLOC;
    }
    return BGS_OK;
}

static int remove_obj_from_src(object_t *obj, scene_t *src)
{
    layer_t *layer = get_layer(src, obj->layer);

    if (layer == NULL) {
        return BGS_ERR_INPUT;
    }
    check_list(layer->displayables, obj);
    check_list(layer->updates, obj);
    check_list(layer->object, obj);
    check_list(src->objects, obj);
    return BGS_OK;
}

static bool check_obj_have_event(object_t *obj)
{
    dico_t *cursor = obj->components;

    if (cursor == NULL) {
        return;
    }
    do {
        if (my_strstartswith(cursor->key, SET_EVENT) == 1) {
            return true;
        }
        cursor = cursor->next;
    } while (cursor != obj->components);
    return false;
}

static int add_obj_to_dest(object_t *obj, scene_t *dest)
{
    layer_t *layer = NULL;

    if (scene_add_object(dest, obj, obj->layer) != 0) {
        return 1;
    }
    if (obj->update == NULL && check_obj_have_event(obj) == true) {
        layer = get_layer(dest, obj->layer);
        if (layer == NULL || list_add_to_end(layer->updates, obj) == NULL) {
            return 1;
        }
    }
    return 0;
}

int obj_change_scene(object_t *obj, scene_t *src, scene_t *dest)
{
    if (obj == NULL || src == NULL || dest == NULL) {
        return BGS_ERR_INPUT;
    } else if (change_scene_in_obj_components(obj, dest) != 0 ||
        remove_obj_from_src(obj, src) != 0 || add_obj_to_dest(obj, dest) != 0) {
        return BGS_ERR_MALLOC;
    }
    return BGS_OK;
}
