/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** window remove
*/

#include "my_bgs.h"
#include "my_dico.h"

static void check_scene_lists(scene_t *scene, void *elem)
{
    check_list(scene->displayables, elem);
    check_list(scene->updates, elem);
    rm_fst_elem(scene->to_remove);
}

void window_remove(scene_t *scene, window_t *win)
{
    void *elem = NULL;

    if (scene == NULL || win == NULL) {
        return;
    }
    while (scene->to_remove->len > 0 && scene->to_remove->start != NULL) {
        elem = scene->to_remove->start->var;
        if (check_list(scene->objects, elem) == true) {
            check_scene_lists(scene, elem);
            remove_object((object_t *) elem);
        }
    }
    while (win->to_remove->len > 0 && win->to_remove->start != NULL) {
        elem = win->to_remove->start->var;
        if (dico_t_rem_ptr(win->scenes, elem) == 1) {
            rm_fst_elem(win->to_remove);
        }
    }
}

