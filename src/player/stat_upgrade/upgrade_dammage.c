/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** upgrade_dammage
*/

#include "my_rpg.h"

const char dammages_key[] = "player dammages";

void upgrade_dammage(any_t *player_stat)
{
    any_t *dammages = NULL;

    dammages = get_from_any(player_stat, "d", dammages_key);
    if (dammages == NULL || dammages->type != FLOAT) {
        return;
    }
    dammages->value.f *= 1.10;
}