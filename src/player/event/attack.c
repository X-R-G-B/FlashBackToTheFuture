/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** attack event
*/

#include "my_rpg.h"

static const char energy_cost_key[] = "energy cost";

static int check_energy(player_t *player)
{
    any_t *data = NULL;
    any_t *energy_cost = NULL;

    data = dico_t_get_value(player->obj->components, "data");
    energy_cost = get_from_any(data, "ddd", "attack", "sword",
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

void attack_event(__attribute__((unused)) object_t *obj, __attribute__((unused))
    scene_t *scene, window_t *win,
    __attribute__((unused)) set_event_t *set_event)
{
    player_t *player = dico_t_get_value(win->components, PLAYER);

    if (scene->pause == true || player == NULL ||
        (player->state != STOP && player->state != MOVING) ||
        check_energy(player) != RET_OK) {
        return;
    }
    player->state = ATTACKING;
}
