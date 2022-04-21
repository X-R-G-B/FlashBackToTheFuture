/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** is player on square
*/

#include "my_rpg.h"

static bool check_foot_collision(player_t *player, sfIntRect square_rect)
{
    sfIntRect rect = player->obj->bigdata.sprite_bigdata.rect;
    sfIntRect left_foot = {rect.left + (rect.width * (1 / 10)),
        rect.top + (rect.height * (4 / 5)), rect.width / 4,
        rect.height * (2 / 10)};
    sfIntRect right_foot = {rect.left + rect.width - (rect.width * (1 / 10)),
        rect.top + (rect.height * (4 / 5)), rect.width / 4,
        rect.height * (2 / 10)};

    printf("%f %f %f %f\n", rect.height, rect.top, rect.width, rect.)
    if (sfIntRect_intersects(&left_foot, &square_rect, NULL) == sfTrue ||
        sfIntRect_intersects(&right_foot, &square_rect, NULL) == sfTrue) {
        return true;
    }
    return false;
}

bool is_player_on_square(window_t *win, sfIntRect rect)
{
    player_t *player = NULL;

    if (win == NULL) {
        return false;
    }
    player = dico_t_get_value(win->components, "player");
    if (player == NULL) {
        return false;
    }
    return check_foot_collision(player, rect);
}
