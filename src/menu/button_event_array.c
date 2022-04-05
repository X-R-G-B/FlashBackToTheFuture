/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** button event array
*/

#include "main_menu.h"

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

const char *str_off_click[] = {"QUIT", "PLAY", "Retour", "BACK", NULL};

void (*off_click[])(object_t *, scene_t *, window_t *win, set_event_t *) = {
    &close_window, &play_pop_up, &go_back, &go_back, NULL
};
