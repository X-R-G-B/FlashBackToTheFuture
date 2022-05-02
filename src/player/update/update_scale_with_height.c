/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** view_with_height
*/

#include "my_bgs.h"
#include "my_rpg.h"

static const float scale_time_factor = 0.01;
static const float max_scale = 1.5;
extern const char can_player_move_scale[];

static bool can_move_up_scale(object_t *obj)
{
    bool *can_move_scale = false;

    if (obj == NULL || obj->components == NULL) {
        return false;
    }
    can_move_scale = dico_t_get_value(obj->components, can_player_move_scale);
    if (can_move_scale == NULL) {
        return false;
    }
    return *can_move_scale;
}

int update_player_view(object_t *obj, window_t *win, float time)
{
    if (obj == NULL || obj->drawable.sprite == NULL || win == NULL ||
            win->components == NULL) {
        return RET_ERR_INPUT;
    }
    if (can_move_up_scale(obj) == true) {
        set_up_scale(obj, win, time);
    } else if (can_move_down_scale(obj) == true) {
        set_down_scale(obj, win, time);
    }
    return RET_OK;
}
