/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** button event array
*/

#include "main_menu.h"
#include "my_rpg.h"

const char *str_on_hover[] = {
    "QUIT", "PLAY", "SETTINGS menu", NULL
};

void (*on_hover[])(object_t *, scene_t *, window_t *win, set_event_t *) = {
    set_exit_overlay, set_play_overlay, set_settings_overlay
};

const char *str_off_hover[] = {NULL};

void (*off_hover[])(object_t *, scene_t *, window_t *win, set_event_t *) = {
    NULL
};

const char *str_on_click[] = {
    "resume", "home", "exit", "settings", "restart","60", "120", "144",
    "165", "PLAY", "BACK", "SETTINGS menu", "QUIT", NULL
};

void (*on_click[])(object_t *, scene_t *, window_t *win, set_event_t *) = {
    pressed_button_on, pressed_button_on, pressed_button_on, pressed_button_on,
    pressed_button_on, set_60_fps, set_120_fps, set_144_fps, set_165_fps,
    click_play, go_back, click_settings, click_exit
};

const char *str_off_click[] = {
    "QUIT", "PLAY", "Retour", "First save", "resume", "home", "exit",
    "settings", "restart", "SETTINGS menu", NULL
};

void (*off_click[])(object_t *, scene_t *, window_t *, set_event_t *) = {
    exit_game, play_pop_up, go_back, click_save, resume_event_off,
    home_button_off, exit_button_off, settings_button_off, restart_button_off,
    settings_pop_up
};
