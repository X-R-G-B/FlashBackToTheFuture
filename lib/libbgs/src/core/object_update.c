/*
** EPITECH PROJECT, 2022
** Defender
** File description:
** object update
*/

#include "my_bgs.h"
#include "my_bgs_components.h"
#include "../include/libbgs_private.h"

sfFloatRect get_object_global_bounces(object_t *object)
{
    if (object == NULL) {
        return (sfFloatRect) {-1, -1, -1, -1};
    }
    if (object->type == SPRITE) {
        return sfSprite_getGlobalBounds(object->drawable.sprite);
    } else if (object->type == TEXT) {
        return sfText_getGlobalBounds(object->drawable.text);
    } else {
        return (sfFloatRect) {-1, -1, -1, -1};
    }
}

void call_collision_fct(object_t *this, object_t *other,
    scene_t *scene, window_t *win)
{
    on_collision_t *this_col = NULL;
    on_collision_t *other_col = NULL;

    if (this == NULL || other == NULL || scene == NULL ||
        win == NULL) {
        return;
    }
    if (this == other) {
        return;
    }
    this_col = dico_t_get_value(this->components, ON_COLLISION);
    other_col = dico_t_get_value(other->components, ON_COLLISION);
    if (this_col == NULL || other_col == NULL) {
        return;
    } else if (dico_t_get_elem(this_col->collisions_dico, other_col->key)) {
        return;
    }
    dico_t_add_data(this_col->collisions_dico, other_col->key, NULL, NULL);
    this_col->collision(this, other, scene, win);
}

void remove_object_this(object_t *this, object_t *other)
{
    on_collision_t *other_col = dico_t_get_value(other->components,
        ON_COLLISION);
    on_collision_t *this_col = dico_t_get_value(this->components,
        ON_COLLISION);
    dico_t *dict_other_col = NULL;

    if (other_col == NULL || this_col == NULL) {
        return;
    }
    dict_other_col = dico_t_get_elem(this_col->collisions_dico, other_col->key);
    if (dict_other_col != NULL) {
        dico_t_rem(this_col->collisions_dico, other_col->key);
        this_col->collisions_dico = NULL;
    }
}

void object_update_collision_event(object_t *this, scene_t *scene,
    window_t *win)
{
    list_ptr_t *list = dico_t_get_value(scene->components, ON_COLLISION);
    list_t *elem = NULL;
    object_t *other = NULL;
    sfFloatRect this_rect;
    sfFloatRect other_rect;

    if (list == NULL || this == NULL) {
        return;
    }
    this_rect = get_object_global_bounces(this);
    elem = list->start;
    for (int i = 0; i < list->len; i++, elem = elem->next) {
        other = ((object_t *) elem->var);
        other_rect = get_object_global_bounces(other);
        if (check_collision(&this_rect, &other_rect, this, other) == true) {
            call_collision_fct(this, other, scene, win);
        } else {
            remove_object_this(this, other);
        }
    }
}

void object_update(object_t *object, scene_t *scene,
    window_t *win, float seconds)
{
    if (object == NULL) {
        return;
    }
    if (object != NULL && object->update != NULL) {
        object->update(object, scene, win, seconds);
    }
    if (object->components == NULL) {
        return;
    }
    object_check_health(object, scene, win);
    object_check_event(object, scene, win);
    object_update_mouse_event(object, scene, win);
    object_update_collision_event(object, scene, win);
}
