/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** knockback.c
*/

#include "my_rpg.h"

void knockback(object_t *obj, scene_t *scene, window_t *win,
    __attribute__((unused)) float time)
{
    player_t *player = NULL;
    sfFloatRect rect_f = sfSprite_getGlobalBounds(obj->drawable.sprite);
    sfIntRect rect = {rect_f.left, rect_f.top, rect_f.width, rect_f.height};

    if (is_player_on_square(win, rect) == false) {
        return;
    }
    player = dico_t_get_value(win->components, "player");
    if (player == NULL) {
        return;
    }
    change_player_pos(player, 10, scene);
    sfRenderWindow_setView(win->win, player->view);
}
