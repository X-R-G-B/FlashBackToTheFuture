/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** roulade
*/

#include "my_rpg.h"
#include "macro.h"

static const char energy_cost_key[] = "energy cost";

static int spend_energy(player_t *player)
{
    any_t *player_data = dico_t_get_value(player->obj->components, PLAYER_DATA);
    any_t *energy_cost = get_from_any(player_data, "dd", roulade_key,
        energy_cost_key);

    if (energy_cost == NULL || energy_cost->type != FLOAT) {
        return RET_ERR_INPUT;
    }
    if (player->energy >= energy_cost->value.f) {
        player->energy -= energy_cost->value.f;
        return RET_OK;
    }
    return RET_ERR_INPUT;
}

void roulade_event(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    player_t *player = NULL;

    if (obj == NULL || scene == NULL || win == NULL || evt == NULL) {
        return;
    }
    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL || player->obj == NULL ||
        (player->state != STOP && player->state != MOVING) ||
        spend_energy(player) != RET_OK) {
        return;
    }
    player->state = ROULADE;
}
