/*
** EPITECH PROJECT, 2022
** bgs
** File description:
** object set origin
*/

#include <SFML/Graphics.h>
#include "my_bgs.h"

static void set_sprite_bigdata(object_t *object)
{
    sfFloatRect rect = {0};

    if (object->bigdata.sprite_bigdata.rect.height != -1) {
        sfSprite_setTextureRect(object->drawable.sprite,
            object->bigdata.sprite_bigdata.rect);
    }
    if (object->bigdata.sprite_bigdata.pos.x != -1) {
        sfSprite_setPosition(object->drawable.sprite,
            object->bigdata.sprite_bigdata.pos);
    }
    rect = sfSprite_getGlobalBounds(object->drawable.sprite);
    sfSprite_setOrigin(object->drawable.sprite,
        (sfVector2f) {rect.width / 2, rect.height / 2});
}

void object_set_origin(object_t *object)
{
    sfFloatRect rect = {0};

    if (object->type == TEXT) {
        sfText_setPosition(object->drawable.text,
            object->bigdata.text_bigdata.pos);
        rect = sfText_getGlobalBounds(object->drawable.text);
        sfText_setOrigin(object->drawable.text,
            (sfVector2f) {rect.width / 2, rect.height / 2});
    } else if (object->type == SPRITE) {
        set_sprite_bigdata(object);
    }
}
