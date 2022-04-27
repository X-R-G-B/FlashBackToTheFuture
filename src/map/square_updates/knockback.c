/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** knockback.c
*/

#include "my_rpg.h"

void knockback(object_t *obj, __attribute__((unused)) scene_t *scene,
    window_t *win, __attribute__((unused)) float time)
{
    player_t *player = NULL;

    if (obj == NULL || win == NULL || is_player_on_square(win,
        sfSprite_getGlobalBounds(obj->drawable.sprite)) == false) {
        return;
    }
    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL || player->view == NULL) {
        return;
    }
    change_player_pos(player, 10, win);
    sfRenderWindow_setView(win->win, player->view);
}
