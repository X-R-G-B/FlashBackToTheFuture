/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** object change scene
*/

#include "my_rpg.h"
#include "main_menu.h"

static int move_list_element(dico_t *dico, char *elem_key, scene_t *fst_scene,
    scene_t *scd_scene)
{
    list_ptr_t *list = NULL;
    list_t *elem = NULL;
    int ret = RET_OK;

    if (dico == NULL || elem_key == NULL || fst_scene == NULL ||
        scd_scene == NULL) {
        return RET_ERR_INPUT;
    }
    list = dico_t_get_value(dico, elem_key);
    if (list == NULL) {
        return RET_OK;
    }
    scd_scene->components = dico_t_add_data(scd_scene->components, elem_key,
        list, NULL);
    elem = list->start;
    for (int i = 0; i < list->len && ret == RET_OK; i++, elem = elem->next) {
        ret = object_change_scene(elem->var, fst_scene, scd_scene);
    }
    return ret;
}

static int move_player(dico_t *dico, scene_t *fst_scene, scene_t *scd_scene)
{
    player_t *player = NULL;

    if (dico == NULL || fst_scene == NULL || scd_scene == NULL) {
        return RET_ERR_MALLOC;
    }
    player = dico_t_get_value(dico, "player");
    if (player == NULL) {
        return RET_OK;
    }
    return object_change_scene(player->obj, fst_scene, scd_scene);
}

int move_object_between_scene(window_t *win, char *fst_scene_key,
    char *scd_scene_key)
{
    scene_t *fst_scene = NULL;
    scene_t *scd_scene = NULL;

    if (win == NULL || fst_scene_key == NULL || scd_scene_key == NULL) {
        return RET_ERR_INPUT;
    }
    fst_scene = dico_t_get_value(win->scenes, fst_scene_key);
    scd_scene = dico_t_get_value(win->scenes, scd_scene_key);
    if (fst_scene == NULL || scd_scene ||
        move_list_element(fst_scene->components, SETTINGS_MENU, fst_scene,
        scd_scene) != RET_OK || move_list_element(fst_scene->components,
        UID_ELEMENTS, fst_scene, scd_scene) != RET_OK ||
        move_player(win->components, fst_scene, scd_scene) != RET_OK) {
        return RET_ERR_INPUT;
    }
    return RET_OK;
}
