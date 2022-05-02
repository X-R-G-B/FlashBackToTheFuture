/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** is player in range
*/

#include "ennemies.h"
#include "maths.h"

bool is_player_in_range(ennemy_t *ennemy, window_t *win)
{
    player_t *player = NULL;
    any_t *data = NULL;
    sfFloatRect rect = {0};
    any_t *range = NULL;

    if (ennemy == NULL || ennemy->obj == NULL || win == NULL) {
        return false;
    }
    data = dico_t_get_value(ennemy->obj->components, ENNEMY_DATA);
    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL || data == NULL || data->type != DICT) {
        return false;
    }
    range = dico_t_get_any(data->value.dict, "range");
    if (range == NULL || range->type != FLOAT) {
        return false;
    }
    rect = sfSprite_getGlobalBounds(player->obj->drawable.sprite);
    return check_circle_col(rect, ennemy->obj->bigdata.sprite_bigdata.pos,
        range->value.f);
}
