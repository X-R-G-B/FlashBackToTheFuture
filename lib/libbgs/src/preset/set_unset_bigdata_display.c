/*
** EPITECH PROJECT, 2022
** defender
** File description:
** set and unset bigdata display
*/

#include "my_bgs.h"
#include "my_bgs_components.h"

void set_display(object_t *object)
{
    object->is_visible = true;
}

void unset_display(object_t *object)
{
    object->is_visible = false;
}
