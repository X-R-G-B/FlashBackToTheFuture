/*
** EPITECH PROJECT, 2022
** tests
** File description:
** tests
*/

#include "my_bgs.h"
#include "my_bgs_components.h"

int main(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    window_t *win = create_window(mode, "t", sfResize | sfClose);
    scene_t *scene = create_scene(win, sfBlack, "SALUT");

    object_set_sprite(create_object(NULL, NULL, scene, 1), "./tests/path.png",
        (sfIntRect) {-1, -1, -1, -1}, (sfVector2f) {405, 405});
    object_set_sprite(create_object(NULL, NULL, scene, 0), "./tests/dirt.png",
        (sfIntRect) {-1, -1, -1, -1}, (sfVector2f) {400, 400});
    object_set_sprite(create_object(NULL, NULL, scene, 3), "./tests/dirt.png",
        (sfIntRect) {-1, -1, -1, -1}, (sfVector2f) {420, 420});
    object_set_sprite(create_object(NULL, NULL, scene, 4), "./tests/path.png",
        (sfIntRect) {-1, -1, -1, -1}, (sfVector2f) {430, 430});
    object_set_sprite(create_object(NULL, NULL, scene, 2), "./tests/dirt.png",
        (sfIntRect) {-1, -1, -1, -1}, (sfVector2f) {410, 410});
    window_change_scene(win, "SALUT");
    loop(win);
    remove_window(win);
    return (0);
}

