/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** button event array
*/

#include "main_menu.h"
#include "my_rpg.h"

const char *str_on_hover[] = {NULL};

void (*on_hover[])(object_t *, scene_t *, window_t *win, set_event_t *) = {
    NULL
};

const char *str_off_hover[] = {NULL};

void (*off_hover[])(object_t *, scene_t *, window_t *win, set_event_t *) = {
    NULL
};

const char *str_on_click[] = {
    "resume", "home", "exit", "settings", "restart", NULL
};

void (*on_click[])(object_t *, scene_t *, window_t *win, set_event_t *) = {
    pressed_button_on, pressed_button_on, pressed_button_on, pressed_button_on,
    pressed_button_on
};

const char *str_off_click[] = {
    "QUIT", "PLAY", "Retour", "BACK", "First save", "resume", "home", "exit",
    "settings", "restart", "SETTINGS menu", NULL
};

void (*off_click[])(object_t *, scene_t *, window_t *, set_event_t *) = {
    close_window, play_pop_up, go_back, go_back, click_save, resume_event_off,
    home_button_off, exit_button_off, settings_button_off, restart_button_off,
    settings_pop_up
};
