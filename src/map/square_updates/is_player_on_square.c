/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** is player on square
*/

#include "my_rpg.h"

static bool check_foot_collision(sfFloatRect rect, sfFloatRect square_rect)
{
    float top = (rect.height * 0.75) + rect.top;
    float right_foot_left = (rect.width * 0.6) + rect.left;
    sfFloatRect left_foot = {(rect.width * 0.15) + rect.left, top,
        rect.width / 4, rect.height * 0.2};
    sfFloatRect right_foot = {right_foot_left, top, rect.width / 4,
        rect.height * 0.2};

    if (sfFloatRect_intersects(&left_foot, &square_rect, NULL) == sfTrue ||
        sfFloatRect_intersects(&right_foot, &square_rect, NULL) == sfTrue) {
        return true;
    }
    return false;
}

bool is_player_on_square(window_t *win, sfFloatRect rect)
{
    player_t *player = NULL;
    sfFloatRect player_rect = {0};

    if (win == NULL) {
        return false;
    }
    player = dico_t_get_value(win->components, "player");
    if (player == NULL) {
        return false;
    }
    player_rect = sfSprite_getGlobalBounds(player->obj->drawable.sprite);
    return check_foot_collision(player_rect, rect);
}
