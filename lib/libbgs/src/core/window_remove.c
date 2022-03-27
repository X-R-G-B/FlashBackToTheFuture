/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** window remove
*/

#include "my_bgs.h"
#include "my_dico.h"

static void scene_remove_obj(scene_t *scene)
{
    void *elem = NULL;

    if (scene == NULL) {
        return;
    }
    while (scene->to_remove->len > 0 && scene->to_remove->start != NULL) {
        elem = scene->to_remove->start->var;
        if (check_list(scene->objects, elem) == true) {
            check_list(scene->displayables, elem);
            check_list(scene->updates, elem);
            remove_object((object_t *) elem);
        }
        rm_fst_elem(scene->to_remove);
    }
}

void window_remove(scene_t *scene, window_t *win)
{
    void *elem = NULL;
    dico_t *scene_elem = NULL;

    scene_remove_obj(scene);
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
