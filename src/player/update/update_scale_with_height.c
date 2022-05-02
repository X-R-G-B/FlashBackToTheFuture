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
extern const char can_player_up_scale[];
extern const char can_player_down_scale[];

static bool can_move_scale(object_t *obj, char key[])
{
    bool *can_move_scale = false;

    if (obj == NULL || obj->components == NULL) {
        return false;
    }
    can_move_scale = dico_t_get_value(obj->components, key);
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
    if (can_move_scale(obj, can_player_up_scale) == true) {
        set_up_scale(obj, time);
    } else if (can_move_scale(obj, can_player_down_scale) == true) {
        set_down_scale(obj, time);
    }
    return RET_OK;
}
