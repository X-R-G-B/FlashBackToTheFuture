/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** view_with_height
*/

#include "my_bgs.h"
#include "my_rpg.h"

extern const char can_player_up_scale[];
extern const char can_player_down_scale[];

static bool can_move_scale(object_t *obj, const char key[])
{
    dico_t *can_move_scale = NULL;

    if (obj == NULL || obj->components == NULL) {
        return false;
    }
    can_move_scale = dico_t_get_elem(obj->components, key);
    if (can_move_scale == NULL) {
        return false;
    }
    return (bool) can_move_scale->value;
}

int update_player_view(object_t *obj, window_t *win, float time)
{
    if (obj == NULL || obj->drawable.sprite == NULL || win == NULL ||
            win->components == NULL) {
        return RET_ERR_INPUT;
    }
    if (can_move_scale(obj, can_player_up_scale) == true) {
        set_up_scale(obj, time);
    } else if (can_move_scale(obj, can_player_down_scale) == true) {
        set_down_scale(obj, time);
    }
    return RET_OK;
}
