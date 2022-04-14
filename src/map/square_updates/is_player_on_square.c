/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** is player on square
*/

#include "my_rpg.h"

bool is_player_on_square(window_t *win, object_t *square)
{
    player_t *player = NULL;
    sfFloatRect player_rect;
    sfFloatRect square_rect;

    if (win == NULL || square == NULL || square->type != SPRITE) {
        return false;
    }
    player = dico_t_get_value(win->components, "player");
    if (player == NULL) {
        return false;
    }
    player_rect = sfSprite_getGlobalBounds(player->obj->drawable.sprite);
    square_rect = sfSprite_getGlobalBounds(square->drawable.sprite);
    if (sfFloatRect_intersects(&player_rect, &square_rect, NULL) == sfTrue) {
        return true;
    }
    return false;
}
