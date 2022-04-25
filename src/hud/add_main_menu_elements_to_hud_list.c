/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** add main menu element to hud list
*/

#include "my_rpg.h"
#include "main_menu.h"

void add_list_obj_to_hud_list(list_ptr_t *hud_elements,
    list_ptr_t *to_cpy, player_t *player)
{
    list_t *elem = NULL;

    if (player == NULL || hud_elements == NULL || to_cpy == NULL) {
        return;
    }
    elem = to_cpy->start;
    for (int i = 0; i < to_cpy->len; i++, elem = elem->next) {
        hud_apply_right_pos(elem->var, player->obj);
        list_add_to_end(hud_elements, elem->var);
    }
}

void add_main_menu_elements_to_hud_list(window_t *win, scene_t *scene,
    list_ptr_t *hud_list)
{
    player_t *player = NULL;
    list_ptr_t *setting_menu = NULL;

    if (win == NULL || scene == NULL || hud_list == NULL) {
        return;
    }
    player = dico_t_get_value(win->components, PLAYER);
    setting_menu = dico_t_get_value(win->components, SETTINGS_MENU);
    if (player == NULL || setting_menu == NULL) {
        return;
    }
    add_list_obj_to_hud_list(hud_list, setting_menu, player);
}
