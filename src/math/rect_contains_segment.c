/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** check if segment is in rect
*/

#include <SFML/Config.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System/Vector2.h>
#include <stdbool.h>
#include "my_bgs.h"
#include "my_macro.h"
#include "maths_function.h"

static int nb_intervals = 100;

bool rect_contains_segment(
    sfFloatRect rect,
    sfVector2f point_a,
    sfVector2f point_b)
{
    sfVector2f delta_x = get_distance(point_a, point_b);
    sfVector2f cursor = {.x = point_a.x, .y = point_a.y};

    if (sfFloatRect_contains(&rect, point_a.x, point_b.y) == sfTrue ||
        sfFloatRect_contains(&rect, point_b.x, point_b.y) == sfTrue) {
        return (true);
    }
    delta_x.x = delta_x.x / nb_intervals;
    delta_x.y = delta_x.y / nb_intervals;
    for (int i = 0; i < nb_intervals; i++) {
        if (sfFloatRect_contains(&rect, cursor.x, cursor.y) == sfTrue) {
            return (true);
        }
        cursor.x += delta_x.x;
        cursor.y += delta_x.y;
    }
    return (false);
}
