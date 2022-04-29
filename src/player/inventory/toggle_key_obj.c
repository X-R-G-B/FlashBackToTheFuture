/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** toggle_key_obj
*/

#include "my_rpg.h"

static int get_nbr_keyobj(window_t *win)
{
    any_t *key_objdata = NULL;

    if (win == NULL) {
        return -1;
    }
    key_objdata = parse_json_file(DATA_INV);
    if (key_objdata == NULL) {
        return -1;
    }
    key_objdata = dico_t_get_any(key_objdata->value.dict, "86 infinity");
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

int toggle_key_obj(window_t *win)
{
    scene_t *scene = get_scene(win);
    list_ptr_t *list = NULL;
    list_t *elem = NULL;
    object_t *obj = NULL;
    int nbr_keyobj = 0;

    nbr_keyobj = get_nbr_keyobj(win);
    if (scene == NULL || nbr_keyobj <= -1) {
        return RET_ERR_MALLOC;
    }
    list = dico_t_get_value(scene->components, KEY_OBJ);
    if (list == NULL || list->len < nbr_keyobj) {
        return RET_ERR_MALLOC;
    }
    elem = list->start;
    for (int i = 0; i < nbr_keyobj; i++) {
        obj = elem->var;
        obj->is_visible = true;
        elem = elem->next;
    }
}
