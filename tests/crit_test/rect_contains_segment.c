/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** test the function rect_contains_segment
*/

#include <SFML/Graphics/Rect.h>
#include <SFML/System/Vector2.h>
#include <criterion/criterion.h>
#include <stdbool.h>
#include "macro.h"

Test(rect_contains_segment, not_true_neg)
{
    sfFloatRect rect = {0, 0, 10, 10};
    sfVector2f pa = {-2, -2};
    sfVector2f pb = {-1, -1};
    bool rep = false;

    rep = rect_contains_segment(rect, pa, pb);
    cr_assert_eq(rep, false);
}

Test(rect_contains_segment, not_true_pos)
{
    sfFloatRect rect = {0, 0, 10, 10};
    sfVector2f pa = {11, 10};
    sfVector2f pb = {20, 10};
    bool rep = false;

    rep = rect_contains_segment(rect, pa, pb);
    cr_assert_eq(rep, false);
}

Test(rect_contains_segment, true_neg)
{
    sfFloatRect rect = {-1, -1, 10, 10};
    sfVector2f pa = {-2, -2};
    sfVector2f pb = {-1, -1};
    bool rep = false;

    rep = rect_contains_segment(rect, pa, pb);
    cr_assert_eq(rep, true);
}

Test(rect_contains_segment, true_pos)
{
    sfFloatRect rect = {20, 20, 10, 10};
    sfVector2f pa = {25, 25};
    sfVector2f pb = {26, 26};
    bool rep = false;

    rep = rect_contains_segment(rect, pa, pb);
    cr_assert_eq(rep, true);
}
