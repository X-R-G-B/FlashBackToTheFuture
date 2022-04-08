/*
** EPITECH PROJECT, 2022
** button generator
** File description:
** tests
*/

#include <SFML/Graphics/Color.h>
#include "my_bgs_button_generator.h"
#include "my_bgs.h"
#include "my_bgs_components.h"
#include "ennemies.h"

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
    window_t *win = create_window((sfVideoMode) {800, 600, 32}, "coucou",
            sfClose);
    scene_t *scene = create_scene(win, sfBlack, "FILS");

    window_change_scene(win, "FILS");
    create_amongus(scene, 100, 100);
    loop(win);
    remove_window(win);
    return 0;
}
