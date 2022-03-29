/*
** EPITECH PROJECT, 2022
** t
** File description:
** t
*/

#include "my_bgs.h"

int main(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    window_t *win = create_window(mode, "t", sfResize | sfClose);
    scene_t *scene = create_scene(win, sfBlack, "TEST");

    window_change_scene(win, "TEST");
    loop(win);
    remove_window(win);
    return 0;
}