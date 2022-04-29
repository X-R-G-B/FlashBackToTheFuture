/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** roulade
*/

#include "my_rpg.h"

void roulade_event(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    player_t *player = NULL;

    if (obj == NULL || scene == NULL || win == NULL || evt == NULL) {
        return;
    }
    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL || (player->state != STOP && player->state != MOVING)) {
        return;
    }
    player->state = ROULADE;
}
