/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** check circle collision
*/

#include <stdbool.h>
#include <SFML/System/Vector2.h>
#include <SFML/Graphics/Rect.h>
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
