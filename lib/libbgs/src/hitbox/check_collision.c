/*
** EPITECH PROJECT, 2022
** defender
** File description:
** check collision
*/

#include <stdio.h>
#include "my_bgs_components.h"
#include "my_bgs.h"
#include "libbgs_private.h"

bool check_this_x_other_col(sfFloatRect this_pixel, sfFloatRect *other)
{
    for (int i = 0; other[i].height != -2; i++, other += 1) {
        if (sfFloatRect_intersects(&this_pixel, other, NULL) == sfTrue) {
            return true;
        }
    }
    return false;
}

bool check_rect(on_collision_t *this_col, on_collision_t *other_col,
    object_t *this, object_t *other)
{
    bool is_collide = false;
    sfFloatRect *other_rect_arr = get_rect_arr(other_col->solid_squares,
        other, sfSprite_getGlobalBounds(other->drawable.sprite));
    sfFloatRect *this_rect_arr = get_rect_arr(this_col->solid_squares,
        this, sfSprite_getGlobalBounds(this->drawable.sprite));

    if (other_rect_arr == NULL || this_rect_arr == NULL) {
        return false;
    }
    for (int i = 0; this_rect_arr[i].height != -2 && is_collide == false; i++) {
        is_collide = check_this_x_other_col(this_rect_arr[i], other_rect_arr);
    }
    return is_collide;
}

bool check_collision(sfFloatRect *this_rect, sfFloatRect *other_rect,
    object_t *this, object_t *other)
{
    on_collision_t *this_col = dico_t_get_value(this->components,
        ON_COLLISION);
    on_collision_t *other_col = dico_t_get_value(other->components,
        ON_COLLISION);

    if (this_col == NULL || other_col == NULL || this == NULL || other == NULL
        || this == other ||
        sfFloatRect_intersects(this_rect, other_rect, NULL) == false) {
        return false;
    }
    if (other->type == TEXT || this->type == TEXT ||
        this_col->is_pixel == false || other_col->is_pixel == false ||
        check_rect(this_col, other_col, this, other) == true) {
        return true;
    }
    return false;
}
