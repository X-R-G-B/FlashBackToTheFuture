/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** stats_component
*/

#include "my_bgs_button_generator.h"
#include "my_bgs.h"
#include "my_rpg.h"
#include "main_menu.h"
#include "macro.h"

static const char STATS_UPGRADE[] = "./assets/data/player/stats_upgrade.json";

extern const char PLAYER[];

static int set_hud_list(list_t *elem, list_ptr_t *stat_upgrade,
    list_ptr_t *uid_elements, player_t *player)
{
    if (stat_upgrade == NULL) {
        return RET_ERR_INPUT;
    }
    elem = stat_upgrade->start;
    if (elem == NULL || uid_elements == NULL || player == NULL) {
        return RET_ERR_INPUT;
    }
    for (int i = 0; i != stat_upgrade->len; i++) {
        hud_apply_right_pos(elem->var, player->obj);
        list_add_to_end(uid_elements, elem->var);
        elem = elem->next;
    }
    return RET_OK;
}

int init_stat_upgrade_pop_up(scene_t *scene, list_ptr_t *uid_elements,
    window_t *win)
{
    list_ptr_t *stat_upgrade = NULL;
    list_t *elem = NULL;
    player_t *player = NULL;

    if (scene == NULL || win->components == NULL) {
        return RET_ERR_INPUT;
    }
    stat_upgrade = create_button(scene, STATS_UPGRADE);
    player = dico_t_get_value(win->components, PLAYER);
    if (stat_upgrade == NULL || player == NULL) {
        return BGS_ERR_MALLOC;
    }
    if (window_add_component(win, stat_upgrade,
        STATS_UPGRADE_KEY, free_pop_up)
        != RET_OK || set_hud_list(elem, stat_upgrade,
        uid_elements, player) != RET_OK) {
        return RET_ERR_INPUT;
    }
    check_if_pop_up_true(win->components, STATS_UPGRADE_KEY);
    return RET_OK;
}
