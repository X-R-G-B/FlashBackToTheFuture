/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** knockback.c
*/

#include "my_rpg.h"

void knockback(object_t *obj, scene_t *scene, window_t *win, set_event_t *evt)
{
    player_t *player = NULL;

    printf("oe\n");
    if (is_player_on_square(win, obj) == false) {
        return;
    }
    player = dico_t_get_value(win->components, "player");
    if (player == NULL) {
        return;
    }
    player->obj->bigdata.sprite_bigdata.pos.y += 10;
}
