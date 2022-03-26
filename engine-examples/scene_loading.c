/*
** EPITECH PROJECT, 2022
** tests
** File description:
** tests
*/

#include <SFML/Graphics/Color.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/VideoMode.h>
#include "my_bgs.h"
#include "my_bgs_components.h"
#include "my_puts.h"

void change_scene(object_t *obj, scene_t *scene, window_t *window,
        set_event_t *evt)
{
    launch_scene_loading(window, 2);
    window->scene_index = 1;
    my_putstr(1, "coucou\n");
    //sleep_(5);
}

int main(int ac, char **av)
{
    window_t *win = create_window((sfVideoMode) {800, 600, 32}, "coucou",
            sfClose);
    scene_t *scene_1 = create_scene(win, sfBlack);
    scene_t *scene_2 = create_scene(win, sfWhite);
    scene_t *scene_3 = create_scene(win, sfMagenta);
    object_t *obj = create_object(NULL, NULL, scene_1);

    object_set_sprite(obj,
        "/home/saverio/.src/test-csfml-webassembly/assets/neovim-logo.png",
        (sfIntRect) {-1, -1, -1, -1}, (sfVector2f) {0, 0});
    create_event(NULL, 1, obj, change_scene);
    loop(win);
    remove_window(win);
}
