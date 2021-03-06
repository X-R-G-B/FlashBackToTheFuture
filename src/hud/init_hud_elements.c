/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** init hud elements
*/

#include "my_dico.h"
#include "my_rpg.h"
#include "my_bgs_components.h"
#include "main_menu.h"
#include "macro.h"
#include "stage.h"
#include "player.h"

static list_ptr_t *create_hud_list(window_t *win, scene_t *scene)
{
    list_ptr_t *hud_elements = NULL;

    if (win == NULL || scene == NULL) {
        return NULL;
    }
    hud_elements = list_create();
    if (hud_elements == NULL || window_add_component(win, hud_elements,
        HUD_ELEMENTS, free_pop_up) != BGS_OK) {
        return NULL;
    }
    return hud_elements;
}

static int create_hud_elements(window_t *win, scene_t *scene,
    list_ptr_t *hud_elements)
{
    list_ptr_t *pause_menu = create_pause_menu(scene, win);
    player_t *player = NULL;

    if (win == NULL) {
        return (RET_ERR_INPUT);
    }
    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL || pause_menu == NULL ||
        init_pause_button(win, pause_menu, scene, hud_elements) != RET_OK ||
        init_dead_menu(win, scene) != RET_OK ||
        init_hud(win, scene) != RET_OK ||
        init_movement(player, win, scene) != RET_OK) {
        return RET_ERR_MALLOC;
    }
    add_main_menu_elements_to_hud_list(win, scene, hud_elements);
    return RET_OK;
}

int init_hud_elements(window_t *win, scene_t *scene)
{
    list_ptr_t *hud_elements = create_hud_list(win, scene);

    if (hud_elements == NULL ||
        create_hud_elements(win, scene, hud_elements) != RET_OK) {
        return RET_ERR_INPUT;
    }
    return RET_OK;
}
