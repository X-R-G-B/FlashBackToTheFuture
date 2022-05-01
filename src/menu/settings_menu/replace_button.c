/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** replace button
*/

#include <stdlib.h>
#include "my_bgs.h"
#include "my_json.h"
#include "audio.h"

void replace_button(object_t *obj, dico_t *dico)
{
    float *pos = NULL;
    object_t *bar = NULL;
    sfFloatRect rect = {0};
    any_t *pos_list = dico_t_get_any(dico, "pos");

    if (obj == NULL || pos_list == NULL || pos_list->type != ARRAY ||
        pos_list->value.array->len != 2) {
        return;
    }
    bar = dico_t_get_value(obj->components, BAR);
    pos = get_any_float_array(pos_list);
    if (pos == NULL || bar == NULL) {
        return;
    }
    sfSprite_setPosition(bar->drawable.sprite, bar->bigdata.sprite_bigdata.pos);
    rect = sfSprite_getGlobalBounds(bar->drawable.sprite);
    obj->bigdata.sprite_bigdata.pos.y = pos[0];
    obj->bigdata.sprite_bigdata.pos.x = rect.left + rect.width;
    free(pos);
}
