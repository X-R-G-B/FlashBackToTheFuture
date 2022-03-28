/*
** EPITECH PROJECT, 2022
** tests
** File description:
** tests
*/

#include "my_bgs.h"
#include "my_strings.h"
#include "my_bgs_components.h"

void click(object_t *obj, scene_t *scene, window_t *win, set_event_t *evt)
{
    my_putstr("fst\n");
}

void scdclick(object_t *obj, scene_t *scene, window_t *win, set_event_t *evt)
{
    my_putstr("scd\n");
}

int main(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    window_t *win = create_window(mode, "t", sfResize | sfClose);
    scene_t *scene = create_scene(win, sfBlack, "SALUT");
    object_t *obj = NULL;
    object_t *scd = NULL;

    obj = create_object(NULL, NULL, scene, 2);
    scd = create_object(NULL, NULL, scene, 3);
    object_set_sprite(obj, "./tests/dirt.png",
        (sfIntRect) {-1, -1, -1, -1}, (sfVector2f) {510, 510});
    object_set_sprite(scd, "./tests/path.png",
        (sfIntRect) {-1, -1, -1, -1}, (sfVector2f) {510, 510});
    event_add_node(create_event(NULL, true, obj, click),
        (node_params_t) {sfMouseLeft, sfKeyA, MOUSE});
    event_add_node(create_event(NULL, true, scd, scdclick),
        (node_params_t) {sfMouseLeft, sfKeyA, MOUSE});
    window_change_scene(win, "SALUT");
    loop(win);
    remove_window(win);
    return (0);
}

