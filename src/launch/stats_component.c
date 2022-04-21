/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** stats_component
*/

#include "my_rpg.h"
#include "my_bgs_button_generator.h"

static const char STATS_UPGRADE[] = "./assets/data/player/stats_upgrade.json";

int init_stat_upgrade_pop_up(scene_t *scene, list_ptr_t *uid_elements,
    window_t *win)
{
    list_ptr_t *stat_upgrade = NULL;
    list_t *elem = NULL;
    player_t *player = dico_t_get_value(win->components, "player");

    if (scene == NULL || player == NULL) {
        return RET_ERR_INPUT;
    }
    stat_upgrade = create_button(scene, STATS_UPGRADE);
    if (stat_upgrade == NULL) {
        return BGS_ERR_MALLOC;
    }
    elem = uid_elements->start;
    for (int i = 0; i != stat_upgrade->len; i++) {
        uid_apply_right_pos(elem->var, player->obj);
        list_add_to_end(uid_elements, elem->var);
        elem = elem->next;
    }
    scene_add_components(scene, stat_upgrade, STATS_UPGRADE_KEY, free_pop_up);
    return RET_OK;
}
