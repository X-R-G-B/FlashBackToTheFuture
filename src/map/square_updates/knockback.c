/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** knockback.c
*/

#include "my_rpg.h"

void knockback(object_t *obj, scene_t *scene, window_t *win, float time)
{
    player_t *player = NULL;
    sfVector2f move[4] = {{0, -10}, {-10, 0}, {0, 10}, {10, 0}};

    if (is_player_on_square(win, obj) == false) {
        return;
    }
    player = dico_t_get_value(win->components, "player");
    if (player == NULL) {
        return;
    }
    player->obj->bigdata.sprite_bigdata.pos.y += move[player->dir].y;
    player->obj->bigdata.sprite_bigdata.pos.x += move[player->dir].x;
    sfView_move(player->view, move[player->dir]);
}
