/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** ativate_dash
*/

#include "my_bgs.h"
#include "my_rpg.h"

void activate_dash(object_t *obj, scene_t *scene,
    window_t *win, __attribute__((unused)) float time)
{
    player_t *player = NULL;

    if (obj == NULL || win == NULL || win->components == NULL ||
            scene == NULL || is_player_on_square(win,
            sfSprite_getGlobalBounds(obj->drawable.sprite)) == false) {
        return;
    }
    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL || player->obj == NULL ||
            player->obj->components == NULL) {
        return;
    }
    player->state = ROULADE;
}
