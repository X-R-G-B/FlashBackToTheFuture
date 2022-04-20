/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** window remove
*/

#include "my_bgs.h"
#include "my_bgs_framebuffer.h"
#include "my_dico.h"

static void scene_remove_obj(scene_t *scene, void *elem)
{
    list_t *list_elem = NULL;
    layer_t *layer = NULL;

    if (scene == NULL || scene->layer == NULL) {
        return;
    }
    list_elem = scene->layer->start;
    for (int i = 0; i < scene->layer->len; i++, list_elem = list_elem->next) {
        layer = list_elem->var;
        if (check_list(layer->object, elem) == true) {
            check_list(layer->displayables, elem);
            check_list(layer->updates, elem);
        }
    }
    rm_fst_elem(scene->to_remove);
}

static void check_remove_scene_obj(scene_t *scene)
{
    list_t *elem = NULL;

    if (scene == NULL || scene->to_remove == NULL) {
        return;
    }
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
    if (win == NULL || win->to_remove == NULL) {
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
