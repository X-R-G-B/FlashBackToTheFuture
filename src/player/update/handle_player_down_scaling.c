/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** handle_player_down_scale
*/

#include "my_rpg.h"
#include "my_bgs.h"

static const float scale_time_factor = 0.01;
static const float min_scale = 1;
extern const char can_player_down_scale[];

static void stop_scaling(object_t *obj)
{
    dico_t *can_move_scale = NULL;

    if (obj == NULL || obj->components == NULL) {
        return;
    }
    can_move_scale = dico_t_get_elem(obj->components, can_player_down_scale);
    if (can_move_scale == NULL) {
        return;
    }
    can_move_scale->value = (void *) false;
}

static void update_down_scale(float time_elapsed, sfVector2f *current_scale)
{
    while (time_elapsed >= scale_time_factor) {
        if (current_scale->x < 0) {
            current_scale->x += scale_time_factor;
        } else {
            current_scale->x -= scale_time_factor;
        }
        current_scale->y -= scale_time_factor;
        time_elapsed -= scale_time_factor;
    }
    if (current_scale->x < min_scale) {
        current_scale->x = min_scale;
        current_scale->y = min_scale;
    } else if (current_scale->x > min_scale * -1) {
        current_scale->x = min_scale * -1;
        current_scale->y = min_scale;
    }
}

void set_down_scale(object_t *obj, float time)
{
    static float time_elapsed = 0;
    sfVector2f current_scale = {0};

    time_elapsed += time;
    current_scale = sfSprite_getScale(obj->drawable.sprite);
    if (current_scale.x <= min_scale) {
        stop_scaling(obj);
        return;
    }
    update_down_scale(time_elapsed, &current_scale);
    sfSprite_setScale(obj->drawable.sprite, current_scale);
}
