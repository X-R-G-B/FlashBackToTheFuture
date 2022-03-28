/*
** EPITECH PROJECT, 2022
** button generator
** File description:
** tests
*/

#include "my_bgs_button_generator.h"
#include "my_bgs.h"

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

const char *str_off_click[] = {NULL};

void (*off_click[])(object_t *, scene_t *, window_t *win, set_event_t *) = {
    NULL
};

int main(void)
{
    return 0;
}
