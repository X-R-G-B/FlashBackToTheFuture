/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** update hurt
*/

#include "my_rpg.h"
#include "my_json.h"

void check_blink_time_end(float *since_start, float dtime, any_t *data,
    player_t *player)
{
    any_t *blink_time = dico_t_get_any(data->value.dict, "blink time");

    if (blink_time == NULL || blink_time->type != FLOAT) {
        return;
    }
    *since_start += dtime;
    if (*since_start >= blink_time->value.f) {
        *since_start = 0;
        player->obj->components = dico_t_rem(player->obj->components, "hurt");
    }
}

void update_hurt(player_t *player, __attribute__((unused)) scene_t *scene,
    __attribute__((unused)) window_t *win, float dtime)
{
    static float since_start = 0;
    any_t *data = NULL;

    if (player == NULL || player->obj == NULL) {
        return;
    }
    data = dico_t_get_value(player->obj->components, "data");
    if (data == NULL) {
        return;
    }
    check_blink_time_end(&since_start, dtime, data, player);
}
