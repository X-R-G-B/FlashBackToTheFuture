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

static int add_obj_in_plan(plan_t *plan, object_t *obj)
{
    if (list_add_to_end(plan->object, obj) == NULL || (obj->update != NULL &&
        list_add_to_end(plan->updates, obj) == NULL) || (obj->display != NULL &&
        list_add_to_end(plan->displayables, obj) == NULL)) {
        return BGS_ERR_MALLOC;
    }
    return BGS_OK;
}

static int create_plan(scene_t *scene, object_t *object, int id, int pos)
{
    plan_t *plan = malloc(sizeof(plan_t));

    if (plan == NULL) {
        return BGS_ERR_MALLOC;
    }
    plan->id = id;
    plan->displayables = list_create();
    plan->object = list_create();
    plan->updates = list_create();
    if (plan->displayables == NULL || plan->object == NULL ||
        plan->updates == NULL || (pos >= 0 &&
        list_add_to_i(scene->plan, plan, pos) == NULL) || (pos < 0 &&
        list_add_to_end(scene->plan, plan) == NULL)) {
        return BGS_ERR_MALLOC;
    }
    return add_obj_in_plan(plan, object);
}

static int add_to_plan(scene_t *scene, object_t *object, int plan)
{
    list_t *elem = scene->plan->start;
    plan_t *ptr = NULL;

    if (scene->plan->len == 0) {
        return create_plan(scene, object, plan, 0);
    }
    for (int i = 0; i < scene->plan->len; i++, elem = elem->next) {
        ptr = elem->var;
        if (plan < ptr->id) {
            return create_plan(scene, object, plan, i);
        } else if (plan == ptr->id) {
            return add_obj_in_plan(ptr, object);
        }
    }
    return create_plan(scene, object, plan, -1);
}

int scene_add_object(scene_t *scene, object_t *object, int plan)
{
    if (scene == NULL || object == NULL) {
        return BGS_ERR_INPUT;
    }
    if (add_to_plan(scene, object, plan) != BGS_OK) {
        return BGS_ERR_MALLOC;
    } else if (object->type == UNSET &&
            list_add_to_end(scene->objects, object) == NULL) {
        return BGS_ERR_MALLOC;
    }
    return BGS_OK;
}
