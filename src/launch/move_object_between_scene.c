/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** object change scene
*/

#include "my_rpg.h"
#include "main_menu.h"
#include "macro.h"
#include "player.h"

static int obj_list_change_scene(dico_t *dict, const char *key,
    scene_t *fst_scene, scene_t *scd_scene)
{
    list_ptr_t *list = NULL;
    list_t *elem = NULL;
    int ret = RET_OK;

    if (dict == NULL || key == NULL || fst_scene == NULL || scd_scene == NULL) {
        return RET_ERR_INPUT;
    }
    list = dico_t_get_value(dict, key);
    if (list == NULL) {
        return RET_ERR_INPUT;
    }
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
        return RET_ERR_INPUT;
    }
    player = dico_t_get_value(dico, PLAYER);
    if (player == NULL) {
        return RET_OK;
    }
    return object_change_scene(player->obj, fst_scene, scd_scene);
}

int move_object_between_scene(window_t *win, scene_t *fst_scene,
    scene_t *scd_scene)
{
    if (win == NULL || fst_scene == NULL || scd_scene == NULL) {
        return RET_ERR_INPUT;
    }
    if (obj_list_change_scene(win->components, HUD_ELEMENTS,
        fst_scene, scd_scene) != RET_OK) {
        if (obj_list_change_scene(win->components, SETTINGS_MENU, fst_scene,
            scd_scene) != RET_OK) {
            return RET_ERR_INPUT;
        }
    }
    return move_player(win->components, fst_scene, scd_scene);
}
