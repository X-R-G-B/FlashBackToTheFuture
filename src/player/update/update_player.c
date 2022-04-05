/*
** EPITECH PROJECT, 2022
** my rpg
** File description:
** update player
*/

#include "my_rpg.h"
#include "my_json.h"

void (*update_ptr[])(player_t *, scene_t *, window_t *, float) = {
    update_attack,
    update_movements
};

void update_player(__attribute__((unused)) object_t *obj, scene_t *scene,
    window_t *win, float dtime)
{
    player_t *player = dico_t_get_value(win->components, "player");

    if (player == NULL) {
        return;
    } else if (player->state >= 0 && player->state <= 1) {
        update_ptr[player->state](player, scene, win, dtime);
    }
}
