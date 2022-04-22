/*
** EPITECH PROJECT, 2022
** defender
** File description:
** check set color
*/

#include <stdlib.h>
#include "my_bgs.h"
#include "my_bgs_button_generator.h"

sfColor get_color(any_t *color_arr)
{
    int *color_array = get_any_int_array(color_arr);
    sfColor color = {0};

    if (color_array == NULL) {
        return sfWhite;
    }
    color = (sfColor) {color_array[0], color_array[1],
        color_array[2], color_array[3]};
    free(color_array);
    return color;
}

int set_color(object_t *object, dico_t *dico)
{
    any_t *color = NULL;

    if (object == NULL || dico == NULL) {
        return (BGS_ERR_INPUT);
    }
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
