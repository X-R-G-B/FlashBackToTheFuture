/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** next level
*/

#include "my_rpg.h"

void next_stage(object_t *obj,
    __attribute__((unused)) scene_t *scene, window_t *win, float time)
{
    if (is_player_on_square(win, obj) == false) {
        return;
    }
    launch_next_stage(win);
}
