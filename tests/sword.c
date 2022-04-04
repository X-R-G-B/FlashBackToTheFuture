/*
** EPITECH PROJECT, 2022
** t
** File description:
** t
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_json.h"

int main(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    window_t *win = create_window(mode, "t", sfResize | sfClose);
    scene_t *scene = create_scene(win, sfBlack, "TEST");
    player_t *player = create_player(win, scene,
        "./assets/data/player/stats.json");

    window_change_scene(win, "TEST");
    loop(win);
    remove_window(win);
    return 0;
}
