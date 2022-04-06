/*
** EPITECH PROJECT, 2022
** create button
** File description:
** check layer
*/

#include "my_bgs_button_generator.h"

int check_layer(dico_t *dico)
{
    any_t *layer = dico_t_get_any(dico, "plan");

    if (layer == NULL || layer->type != INT) {
        return 0;
    }
    return layer->value.i;
}
