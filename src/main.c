/*
** EPITECH PROJECT, 2022
** button generator
** File description:
** tests
*/

#include "menu.h"
#include "my_bgs_button_generator.h"
#include "my_bgs.h"
#include "my_bgs_components.h"
#include "my_rpg.h"

const char *str_on_hover[] = {NULL};

void (*on_hover[])(object_t *, scene_t *, window_t *win, set_event_t *) = {
    NULL
};

const char *str_off_hover[] = {NULL};

void (*off_hover[])(object_t *, scene_t *, window_t *win, set_event_t *) = {
    NULL
};
const char *str_on_click[] = {NULL};

void (*on_click[])(object_t *, scene_t *, window_t *win, set_event_t *) = {
    NULL
};

const char *str_off_click[] = {"QUIT", "PLAY", "Retour", "Back", NULL};

void (*off_click[])(object_t *, scene_t *, window_t *win, set_event_t *) = {
    &close_window, &play_pop_up, &go_back, &go_back, NULL
};

int main(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    window_t *win = create_window(mode, "My_Rpg", sfResize | sfClose);

    init_menu(win);
    window_change_scene(win, "MAIN MENU");
    loop(win);
    remove_window(win);
    return 0;
}
