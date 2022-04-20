/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** sprite set change
*/

#include "my_rpg.h"
#include "my_json.h"

int sprite_set_change(object_t *ennemy, any_t *ennemy_data)
{
    any_t *scale = NULL;

    if (ennemy == NULL || ennemy_data == NULL) {
        return RET_ERR_INPUT;
    }
    scale = dico_t_get_any(ennemy_data->value.dict, "scale");
    if (scale != NULL || scale->type == FLOAT) {
        sfSprite_setScale(ennemy->drawable.sprite,
            (sfVector2f) {scale->value.f, scale->value.f});
    }
    return RET_OK;
}
