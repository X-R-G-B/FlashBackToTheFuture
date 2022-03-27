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
#include "unistd.h"

// call launch_scene_loading first, after the function can take a infinte time
// at the end, it will just restart normaly
void change_scene_1(object_t *obj, scene_t *scene, window_t *window,
        set_event_t *evt)
{
    launch_scene_loading(window, "SCENE_3");
    window_change_scene(window, "SCENE_2");
    sleep(5);
    my_putstr(1, "coucou\n");
}

void change_scene_2(object_t *obj, scene_t *scene, window_t *window,
        set_event_t *evt)
{
    launch_scene_loading(window, "SCENE_3");
    window_change_scene(window, "SCENE_1");
    sleep(5);
    my_putstr(1, "salut\n");
}

int main(int ac, char **av)
{
    window_t *win = create_window((sfVideoMode) {800, 600, 32}, "coucou",
            sfClose);
    scene_t *scene_1 = create_scene(win, sfBlack, "SCENE_1");
    scene_t *scene_2 = create_scene(win, sfWhite, "SCENE_2");
    scene_t *scene_3 = create_scene(win, sfMagenta, "SCENE_3");
    object_t *obj = create_object(NULL, NULL, scene_1);

    object_set_sprite(obj,
        "/home/saverio/.src/test-csfml-webassembly/assets/neovim-logo.png",
        (sfIntRect) {-1, -1, -1, -1}, (sfVector2f) {0, 0});
    create_event(NULL, 1, obj, change_scene_1);
    obj = create_object(NULL, NULL, scene_2);
    object_set_sprite(obj,
        "/home/saverio/.src/test-csfml-webassembly/assets/neovim-logo.png",
        (sfIntRect) {-1, -1, -1, -1}, (sfVector2f) {0, 0});
    create_event(NULL, 1, obj, change_scene_2);
    window_change_scene(win, "SCENE_1");
    loop(win);
    remove_window(win);
}
