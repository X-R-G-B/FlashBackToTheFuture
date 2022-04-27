/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** destroy pos array
*/

#include <stdlib.h>

void destroy_pos_array(float *text, float *pos)
{
    if (text != NULL) {
        free(text);
    }
    if (pos != NULL) {
        free(pos);
    }
}
