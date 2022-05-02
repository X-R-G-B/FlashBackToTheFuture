/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** activate_player_down_scale
*/

#include "my_bgs.h"
#include "my_rpg.h"

extern const char can_player_down_scale[];

void activate_up_scale(object_t *obj, scene_t *scene,
    window_t *win, float time)
{
    player_t *player = NULL;
    bool *can_move_scale = NULL;

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
    can_move_scale = dico_t_get_value(player->obj->components,
        can_player_down_scale);
    if (can_move_scale == NULL || *can_move_scale == true) {
        return;
    }
    *can_move_scale = true;
    printf("ok ca passe\n");
}
