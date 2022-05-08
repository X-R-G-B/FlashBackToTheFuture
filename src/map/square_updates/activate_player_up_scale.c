/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** view_with_height
*/

#include "my_bgs.h"
#include "player.h"

extern const char can_player_up_scale[];

void activate_up_scale(object_t *obj, scene_t *scene,
    window_t *win, __attribute__((unused)) float time)
{
    player_t *player = NULL;
    dico_t *can_move_scale = NULL;

    if (obj == NULL || obj->type != SPRITE || win == NULL ||
            win->components == NULL || scene == NULL || is_player_on_square(win,
            sfSprite_getGlobalBounds(obj->drawable.sprite)) == false) {
        return;
    }
    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL || player->obj == NULL ||
            player->obj->components == NULL) {
        return;
    }
    can_move_scale = dico_t_get_elem(player->obj->components,
        can_player_up_scale);
    if (can_move_scale == NULL || (bool) can_move_scale->value == true) {
        return;
    }
    can_move_scale->value = (void *) true;
}
