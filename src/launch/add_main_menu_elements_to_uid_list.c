/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** add main menu element to uid list
*/

#include "my_rpg.h"
#include "main_menu.h"

void add_list_obj_to_uid_list(list_ptr_t *uid_elements,
    list_ptr_t *to_cpy, player_t *player)
{
    list_t *elem = NULL;

    if (player == NULL || uid_elements == NULL || to_cpy == NULL) {
        return;
    }
    elem = to_cpy->start;
    for (int i = 0; i < to_cpy->len; i++, elem = elem->next) {
        uid_apply_right_pos(elem->var, player->obj);
        list_add_to_end(uid_elements, elem->var);
    }
}

void add_main_menu_elements_to_uid_list(window_t *win, scene_t *scene,
    list_ptr_t *uid_list)
{
    player_t *player = NULL;
    list_ptr_t *setting_menu = NULL;

    if (win == NULL || scene == NULL || uid_list == NULL) {
        return;
    }
    player = dico_t_get_value(win->components, "player");
    setting_menu = dico_t_get_value(scene->components, SETTINGS_MENU);
    if (player == NULL || setting_menu == NULL) {
        return;
    }
    add_list_obj_to_uid_list(uid_list, setting_menu, player);
}
