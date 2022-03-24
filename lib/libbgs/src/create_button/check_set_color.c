/*
** EPITECH PROJECT, 2022
** defender
** File description:
** check set color
*/

#include <stdlib.h>
#include "my_bgs_button_generator.h"

int set_clr(object_t *object, dico_t *dico)
{
    int *color = NULL;

    if (object->type == SPRITE) {
        color = get_any_int_array(dico_t_get_any(dico, "color"));
        if (color == NULL) {
            return BGS_ERR_MALLOC;
        }
        sfSprite_setColor(object->drawable.sprite, sfColor_fromRGBA(color[0],
            color[1], color[2], color[3]));
    } else {
        color = get_any_int_array(dico_t_get_any(dico, "text color"));
        if (color == NULL)
            return BGS_ERR_MALLOC;
        sfText_setColor(object->drawable.text, sfColor_fromRGB(color[0],
            color[1], color[2]));
    }
    if (color != NULL) {
        free(color);
    }
    return BGS_OK;
}
