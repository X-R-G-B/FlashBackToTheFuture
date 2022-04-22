/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** is player on square
*/

#include "my_rpg.h"

static bool check_foot_collision(sfIntRect rect, sfIntRect square_rect)
{
    float height_f = rect.height;
    int top = (height_f * 0.8) + rect.top;
    int height = height_f * 0.2;
    float width_f = rect.width;
    int left_foot_left = (width_f * 0.1) + rect.left;
    int right_foot_left = rect.left + rect.width - (width_f * 0.1);
    sfIntRect left_foot = {left_foot_left, top, rect.width / 4, height};
    sfIntRect right_foot = {right_foot_left, top, rect.width / 4, height};

    if (sfIntRect_intersects(&left_foot, &square_rect, NULL) == sfTrue ||
        sfIntRect_intersects(&right_foot, &square_rect, NULL) == sfTrue) {
        return true;
    }
    return false;
}

bool is_player_on_square(window_t *win, sfIntRect rect)
{
    player_t *player = NULL;
    sfFloatRect rect_f = {0};
    sfIntRect player_rect = {0};

    if (win == NULL) {
        return false;
    }
    player = dico_t_get_value(win->components, "player");
    if (player == NULL) {
        return false;
    }
    rect_f = sfSprite_getGlobalBounds(player->obj->drawable.sprite);
    player_rect = (sfIntRect) {rect_f.left, rect_f.top, rect_f.width,
        rect_f.height};
    return check_foot_collision(player_rect, rect);
}
