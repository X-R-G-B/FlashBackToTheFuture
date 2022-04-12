/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** uid apply right pos
*/

#include "my_rpg.h"

void uid_apply_right_pos(object_t *obj, sfVector2f screen_pos)
{
    if (obj == NULL) {
        return;
    }
    if (obj->type == SPRITE) {
        obj->bigdata.sprite_bigdata.pos.x = screen_pos.x +
            obj->bigdata.sprite_bigdata.pos.x;
        obj->bigdata.sprite_bigdata.pos.y = screen_pos.y +
            obj->bigdata.sprite_bigdata.pos.y;
    } else if (obj->type == TEXT) {
        obj->bigdata.text_bigdata.pos.x = screen_pos.x +
            obj->bigdata.text_bigdata.pos.x;
        obj->bigdata.text_bigdata.pos.y = screen_pos.y +
            obj->bigdata.text_bigdata.pos.y;
    }
}
