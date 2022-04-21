/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** uid apply right pos
*/

#include "my_rpg.h"

void uid_apply_right_pos(object_t *obj, object_t *player)
{
    sfVector2f screen_pos = {0};

    if (obj == NULL || player == NULL) {
        return;
    }
    screen_pos = (sfVector2f) {
        player->bigdata.sprite_bigdata.pos.x - WIN_SIZE_X / 2,
        player->bigdata.sprite_bigdata.pos.y - WIN_SIZE_Y / 2
    };
    if (obj->type == SPRITE) {
        obj->bigdata.sprite_bigdata.pos.x += screen_pos.x;
        obj->bigdata.sprite_bigdata.pos.y += screen_pos.y;
    } else if (obj->type == TEXT) {
        obj->bigdata.text_bigdata.pos.x += screen_pos.x;
        obj->bigdata.text_bigdata.pos.y += screen_pos.y;
    }
}
