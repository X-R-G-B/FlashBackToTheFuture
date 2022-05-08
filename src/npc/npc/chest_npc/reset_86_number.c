/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** reset 86 number
*/

#include "my_rpg.h"
#include "rpg_struct.h"
#include "player.h"

extern const char stats_path_key[];

void reset_86_number(player_t *player)
{
    any_t *stats = NULL;
    any_t *infinity_86 = NULL;

    if (player == NULL || player->obj == NULL) {
        return;
    }
    stats = dico_t_get_value(player->obj->components, PLAYER_STATS);
    infinity_86 = get_from_any(stats, "d", INFINITY_86);
    if (infinity_86 == NULL || infinity_86->type != INT) {
        return;
    }
    infinity_86->value.i = 0;
    write_json(stats, dico_t_get_value(player->obj->components,
        stats_path_key));
}
