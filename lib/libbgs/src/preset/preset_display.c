/*
** EPITECH PROJECT, 2022
** Defender
** File description:
** preset display
*/

#include "my_bgs.h"

void display_sprite(object_t *object,
    __attribute__((unused)) dico_t *scene_compoenents,
    __attribute__((unused)) dico_t *win_components, sfRenderWindow *win)
{
    if (object->type != SPRITE ||
        object->is_visible == false) {
        return;
    }
    if (object->bigdata.sprite_bigdata.pos.x != -1) {
        sfSprite_setPosition(object->drawable.sprite,
            object->bigdata.sprite_bigdata.pos);
    }
    if (object->bigdata.sprite_bigdata.rect.height > -1 &&
            object->bigdata.sprite_bigdata.rect.width > -1) {
        sfSprite_setTextureRect(object->drawable.sprite,
            object->bigdata.sprite_bigdata.rect);
    }
    sfRenderWindow_drawSprite(win, object->drawable.sprite, NULL);
}

void display_text(object_t *object,
    __attribute__((unused)) dico_t *scene_components,
    __attribute__((unused)) dico_t *win_components, sfRenderWindow *win)
{
    if (object->type != TEXT ||
        object->is_visible == false) {
        return;
    }
    if (object->bigdata.text_bigdata.pos.x > -1) {
        sfText_setPosition(object->drawable.text,
            object->bigdata.text_bigdata.pos);
    }
    sfRenderWindow_drawText(win, object->drawable.text, NULL);
}
