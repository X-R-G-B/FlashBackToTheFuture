/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** hud apply right pos
*/

#include "my_rpg.h"

void hud_replace_pos_in_next_stage()

void hud_apply_right_pos(object_t *obj, object_t *player)
{
    sfVector2f screen_pos = {0};

    if (obj == NULL || player == NULL) {
        return;
    }
    screen_pos = (sfVector2f) {
        player->bigdata.sprite_bigdata.pos.x - (WIN_SIZE_X / 2),
        player->bigdata.sprite_bigdata.pos.y - (WIN_SIZE_Y / 2)
    };
    printf("player pos %f %f\n", player->bigdata.sprite_bigdata.pos.x, player->bigdata.sprite_bigdata.pos.y);
    printf("obj pos before %f %f\n", obj->bigdata.sprite_bigdata.pos.x, obj->bigdata.sprite_bigdata.pos.y);
    if (obj->type == SPRITE) {
        obj->bigdata.sprite_bigdata.pos.x += screen_pos.x;
        obj->bigdata.sprite_bigdata.pos.y += screen_pos.y;
    } else if (obj->type == TEXT) {
        obj->bigdata.text_bigdata.pos.x += screen_pos.x;
        obj->bigdata.text_bigdata.pos.y += screen_pos.y;
    }
    printf("obj pos after %f %f\n", obj->bigdata.sprite_bigdata.pos.x, obj->bigdata.sprite_bigdata.pos.y);
}
