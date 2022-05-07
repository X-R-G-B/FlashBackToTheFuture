/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** play_sound
*/

#include "my_rpg.h"

void play_sound(window_t *win, const char *comp_key)
{
    object_t *obj = NULL;

    if (win == NULL || comp_key == NULL) {
        return;
    }
    obj = dico_t_get_value(win->components, comp_key);
    if (obj == NULL) {
        return;
    }
    sfSound_play(obj->drawable.sound);
}