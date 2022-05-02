/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** header for math functions
*/

#ifndef MATH_RPG_H_
    #define MATH_RPG_H_

    #include <SFML/Graphics/Rect.h>
    #include <SFML/System/Vector2.h>
    #include <stdbool.h>
    #include "my_bgs.h"

bool check_circle_col(sfFloatRect rect, sfVector2f circle, float rad);

bool rect_contains_segment(
    sfFloatRect rect,
    sfVector2f point_a,
    sfVector2f point_b
);

int randomise(int min, int max);

int add_gore_sword(window_t *win, sfVector2f pos);

#endif
