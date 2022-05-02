/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** button event array
*/

#include "main_menu.h"
#include "my_rpg.h"
#include "audio.h"

const char *str_on_hover[] = {
    "QUIT", "PLAY", "SETTINGS menu", "SANDBOX", "music button", "sound button"
};

void (*on_hover[])(object_t *, scene_t *, window_t *win, set_event_t *) = {
    set_exit_overlay, set_play_overlay, set_settings_overlay,
        set_sandbox_overlay, drag_button_on_hover, drag_button_on_hover
};

const char *str_off_hover[] = {"music button", "sound button", NULL};

void (*off_hover[])(object_t *, scene_t *, window_t *win, set_event_t *) = {
    drag_button_off_hover, drag_button_off_hover
};

const char *str_on_click[] = {
    "resume", "home", "exit", "settings", "restart","60", "120", "144",
    "165", "PLAY", "BACK", "SETTINGS menu", "QUIT", "music button",
    "sound button", NULL
};

void (*on_click[])(object_t *, scene_t *, window_t *win, set_event_t *) = {
    pressed_button_on, pressed_button_on, pressed_button_on, pressed_button_on,
    pressed_button_on, set_60_fps, set_120_fps, set_144_fps, set_165_fps,
    click_play, go_back, click_settings, click_exit, drag_button_on,
    drag_button_on
};

const char *str_off_click[] = {
    "QUIT", "PLAY", "Retour", "First save", "resume", "home", "exit",
    "settings", "restart", "SETTINGS menu", "Up energy", "Up health", "potion",
    "music button", "sound button", "SANDBOX", NULL
};

void (*off_click[])(object_t *, scene_t *, window_t *, set_event_t *) = {
    exit_game, play_pop_up, go_back, click_save, resume_event_off,
    home_button_off, exit_button_off, settings_button_off, restart_button_off,
    settings_pop_up, upgrade_energy, upgrade_health, use_heal_potion,
    music_drag_button_off, sound_drag_button_off, sandbox_button_off
};
