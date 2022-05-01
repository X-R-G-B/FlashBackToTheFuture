/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** get distance between two point
*/

#include "my_rpg.h"
#include <SFML/System/Vector2.h>

sfVector2f get_distance(sfVector2f point_a, sfVector2f point_b)
{
    sfVector2f distance = {0};

    distance.x = point_a.x - point_b.x;
    distance.y = point_a.y - point_b.y;
    return (distance);
}

int fill_get_distance(sfVector2f point_a, sfVector2f point_b, sfVector2f *fill)
{
    sfVector2f distance = {0};

    if (fill == NULL) {
        return (RET_ERR_INPUT);
    }
    distance = get_distance(point_a, point_b);
    fill->x = distance.x;
    fill->y = distance.y;
    return (RET_OK);
}
