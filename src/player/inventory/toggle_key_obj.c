/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** toggle_key_obj
*/

#include "my_rpg.h"
#include "player.h"

static const int max_key_obj = 5;

static void toggle_nbr_keyobj(scene_t *scene, int nbr_keyobj)
{
    list_ptr_t *list = NULL;
    list_t *elem = NULL;
    object_t *obj = NULL;

    list = dico_t_get_value(scene->components, KEY_OBJ);
    if (list == NULL || list->len < nbr_keyobj) {
        return;
    }
    elem = list->start;
    for (int i = 0; i < nbr_keyobj; i++) {
        obj = elem->var;
        obj->is_visible = true;
        elem = elem->next;
    }
}

static int get_nbr_keyobj(window_t *win)
{
    any_t *acutal_data = NULL;
    any_t *key_objdata = NULL;

    if (win == NULL) {
        return -1;
    }
    acutal_data = get_player_stats(win);
    if (acutal_data == NULL) {
        return -1;
    }
    key_objdata = dico_t_get_value(acutal_data->value.dict, INFINITY_86);
    if (key_objdata == NULL) {
        return -1;
    }
    return key_objdata->value.i;
}

static scene_t *get_scene(window_t *win)
{
    scene_t *scene = NULL;

    if (win == NULL) {
        return NULL;
    }
    scene = dico_t_get_value(win->scenes, INV_SCENE);
    if (scene == NULL) {
        return NULL;
    }
    return scene;
}

void toggle_key_obj(window_t *win)
{
    scene_t *scene = get_scene(win);
    int nbr_keyobj = 0;

    nbr_keyobj = get_nbr_keyobj(win);
    if (scene == NULL || nbr_keyobj <= -1) {
        return;
    }
    if (nbr_keyobj >= max_key_obj) {
        nbr_keyobj = max_key_obj;
    }
    toggle_nbr_keyobj(scene, nbr_keyobj);
}
