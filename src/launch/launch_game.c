/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** init game
*/

#include "my_rpg.h"
#include "main_menu.h"

int launch_game(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    window_t *win = create_window(mode, "My_Rpg", sfResize | sfClose);

    if (win == NULL || init_menu(win) != RET_OK ||
        window_change_scene(win, "MAIN MENU") != BGS_OK ||
        loop(win) != BGS_OK) {
        return 84;
    }
    remove_window(win);
    return RET_OK;
}
