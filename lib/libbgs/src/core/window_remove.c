/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** window remove
*/

#include "my_bgs.h"
#include "my_dico.h"

static void scene_remove_obj(scene_t *scene, void *elem)
{
    list_t *list_elem = scene->plan->start;
    plan_t *plan = NULL;

    for (int i = 0; i < scene->plan->len; i++, list_elem = list_elem->next) {
        plan = list_elem->var;
        if (check_list(plan->object, elem) == true) {
            check_list(plan->displayables, elem);
            check_list(plan->updates, elem);
        }
    }
    rm_fst_elem(scene->to_remove);
}

static void check_remove_scene_obj(scene_t *scene)
{
    list_t *elem = NULL;

    while (scene->to_remove->len > 0 && scene->to_remove->start != NULL) {
        elem = scene->to_remove->start->var;
        scene_remove_obj(scene, elem);
        rm_fst_elem(scene->to_remove);
    }
}

void window_remove(scene_t *scene, window_t *win)
{
    void *elem = NULL;
    dico_t *scene_elem = NULL;

    check_remove_scene_obj(scene);
    if (win == NULL) {
        return;
    }
    while (win->to_remove->len > 0 && win->to_remove->start != NULL) {
        elem = win->to_remove->start->var;
        scene_elem = dico_t_get_elem_ptr(win->scenes, elem);
        if (scene_elem != NULL) {
            win->scenes = dico_t_rem(win->scenes, scene_elem->key);
        }
        rm_fst_elem(win->to_remove);
    }
}
