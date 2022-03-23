/*
** EPITECH PROJECT, 2022
** bgs
** File description:
** scene reload lists
*/

#include "my_strings.h"
#include "my_bgs.h"
#include "my_bgs_components.h"

int reset_list(scene_t *scene)
{
    free_list(scene->displayables);
    free_list(scene->updates);
    scene->displayables = list_create();
    scene->updates = list_create();
    if (scene->displayables == NULL || scene->updates == NULL) {
        return BGS_OK;
    }
    return BGS_OK;
}

static bool obj_is_update(object_t *object)
{
    sprite_health_t *sprite_health = NULL;
    on_collision_t *on_collision = NULL;
    dico_t *cursor = NULL;

    if (object->update != NULL) {
        return true;
    } else if (object->components == NULL) {
        return false;
    }
    cursor = object->components;
    do {
        if (my_strstartswith(cursor->key, SET_EVENT) == 1) {
            return true;
        }
        cursor = cursor->next;
    } while (cursor != object->components);
    sprite_health = dico_t_get_value(object->components, COMP_HEALTH);
    on_collision = dico_t_get_value(object->components, ON_COLLISION);
    return (sprite_health != NULL || on_collision != NULL) ? true : false;
}

int scene_reload_lists(scene_t *scene)
{
    list_t *elem = NULL;
    object_t *object = NULL;

    if (scene == NULL || reset_list(scene) != BGS_OK) {
        return BGS_ERR_MALLOC;
    }
    elem = scene->objects->start;
    for (int i = 0; i < scene->objects->len; i++, elem = elem->next) {
        object = ((object_t *) elem->var);
        if (obj_is_update(object) == true &&
            list_add_to_end(scene->updates, object) == NULL) {
            return BGS_ERR_MALLOC;
        }
        if (object->display != NULL &&
            list_add_to_end(scene->displayables, object) == NULL) {
            return BGS_ERR_MALLOC;
        }
    }
    return BGS_OK;
}
