/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** object change scene
*/

#include "my_rpg.h"
#include "main_menu.h"

static void object_list_change_scene(list_ptr_t *list, scene_t *fstscene,
    scene_t *scdscene)
{
    list_t *elem = list->start;

    for (int i = 0; i < list->len; i++, elem = elem->next) {
        object_change_scene
    }
    
}

int move_object_between_scene(window_t *win, char *fst_scene_key,
    char *scd_scene_key)
{
    scene_t *scene = NULL;
    list_ptr_t *setting_menu = NULL;

    if (win == NULL || fst_scene_key == NULL || scd_scene_key == NULL) {
        return RET_ERR_INPUT;
    }
    scene = dico_t_get_value(win->scenes, "MAIN MENU");
    if (scene == NULL) {
        return RET_ERR_INPUT;
    }
    setting_menu = dico_t_get_value(scene, SETTINGS_MENU);
    if (setting_menu == NULL) {
        return RET_ERR_INPUT;
    }

}