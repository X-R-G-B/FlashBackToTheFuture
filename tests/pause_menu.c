/*
** EPITECH PROJECT, 2022
** t
** File description:
** t
*/

#include "my_rpg.h"
#include "my_bgs.h"

const char *str_on_hover[] = {NULL};

void (*on_hover[])(object_t *, scene_t *, window_t *, set_event_t *);

const char *str_off_hover[] = {NULL};

void (*off_hover[])(object_t *, scene_t *, window_t *, set_event_t *);

const char *str_on_click[] = {"resume", "home", "exit", "settings",
    "restart", NULL};

void (*on_click[])(object_t *, scene_t *, window_t *, set_event_t *) =
    {pressed_button_on, pressed_button_on, pressed_button_on,
    pressed_button_on, pressed_button_on};

const char *str_off_click[] = {"resume", "home", "exit", "settings",
    "restart", NULL};

void (*off_click[])(object_t *, scene_t *, window_t *, set_event_t *) =
    {resume_event_off, home_button_off, exit_button_off,
    settings_button_off, restart_button_off};

int main(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    window_t *win = create_window(mode, "tests", sfResize | sfClose);
    scene_t *scene = create_scene(win, sfBlack, "START");

    create_pause_menu(scene);
    window_change_scene(win, "START");
    loop(win);
    remove_window(win);
}
