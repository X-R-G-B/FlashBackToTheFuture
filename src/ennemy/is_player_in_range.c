/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** is player in range
*/

#include "ennemies.h"
#include "my_macro.h"

bool check_circle_col(sfFloatRect rect, sfVector2f circle, float rad)
{
    sfVector2f distance = {ABSOL(circle.x - rect.left),
        ABSOL(circle.y - rect.top)};
    sfVector2f corner = {distance.x - rect.width / 2,
        distance.y - rect.height / 2};
    float corner_distance_sq = 0;

    if ((distance.x > (rect.width / 2 + rad)) ||
        (distance.y > (rect.height / 2 + rad))) {
        return false;
    } else if ((distance.x <= rect.width / 2) ||
        (distance.x <= rect.height / 2)) {
        return true;
    }
    corner_distance_sq = ((corner.x * corner.x) + (corner.y * corner.y));
    if (corner_distance_sq <= (rad * rad)) {
        return true;
    }
    return false;
}

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
