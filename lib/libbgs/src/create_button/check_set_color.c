/*
** EPITECH PROJECT, 2022
** defender
** File description:
** check set color
*/

#include <stdlib.h>
#include "my_bgs_button_generator.h"

sfColor get_color(any_t *color_arr)
{
    int *color = get_any_int_array(color_arr);

    if (color == NULL) {
        return sfWhite;
    }
    return sfColor_fromRGBA(color[0], color[1], color[2], color[3]);
}

int set_color(object_t *object, dico_t *dico)
{
    any_t *color = NULL;

    if (object->type == SPRITE) {
        color = dico_t_get_any(dico, "color");
        if (color == NULL || color->type != ARRAY) {
            return BGS_OK;
        }
        sfSprite_setColor(object->drawable.sprite, get_color(color));
    } else {
        color = dico_t_get_any(dico, "text color");
        if (color == NULL)
            return BGS_ERR_MALLOC;
        sfText_setColor(object->drawable.text, get_color(color));
    }
    return BGS_OK;
}
