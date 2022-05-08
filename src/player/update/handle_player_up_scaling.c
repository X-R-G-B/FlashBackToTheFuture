/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** handle_player_up_scaling
*/

#include "my_rpg.h"
#include "my_bgs.h"
#include "rpg_struct.h"

static const float scale_time_factor = 0.97;
static const float max_scale = 1820;
static const float update_time = 0.1;
extern const char can_player_up_scale[];

static void stop_scaling(object_t *obj)
{
    dico_t *can_move_scale = NULL;

    if (obj == NULL || obj->components == NULL) {
        return;
    }
    can_move_scale = dico_t_get_elem(obj->components, can_player_up_scale);
    if (can_move_scale == NULL) {
        return;
    }
    can_move_scale->value = (void *) false;
}

void set_up_scale(object_t *obj, float time, player_t *player)
{
    static float time_elapsed = 0;
    sfVector2f current_scale = {0};

    time_elapsed += time;
    if (obj == NULL || player == NULL || time_elapsed < update_time ||
            player->view == NULL) {
        return;
    }
    current_scale = sfView_getSize(player->view);
    if (current_scale.x <= max_scale) {
        stop_scaling(obj);
        return;
    }
    time_elapsed -= update_time;
    current_scale.x *= scale_time_factor;
    current_scale.y *= scale_time_factor;
    sfView_setSize(player->view, current_scale);
}
