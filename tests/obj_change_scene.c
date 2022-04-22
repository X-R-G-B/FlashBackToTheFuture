/*
** EPITECH PROJECT, 2022
** t
** File description:
** t
*/

#include "my_rpg.h"
#include "my_bgs_components.h"

static void click_scd(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    scene_t *fst = dico_t_get_value(win->scenes, "fst");
    object_t *object = dico_t_get_value(win->components, "obj");

    window_change_scene(win, "fst");
    object_change_scene(object, scene, fst);
}

static void click_fst(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    scene_t *scd = dico_t_get_value(win->scenes, "scd");
    object_t *object = dico_t_get_value(win->components, "obj");

    window_change_scene(win, "scd");
    object_change_scene(object, scene, scd);
}

int main(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    window_t *win = create_window(mode, "r", sfResize | sfClose);
    scene_t *fst = create_scene(win, sfBlack, "fst");
    scene_t *scd = create_scene(win, sfBlack, "scd");
    object_t *object = create_object(NULL, NULL, fst, 0);
    object_t *fst_bt = create_object(NULL, NULL, fst, 0);
    object_t *scd_bt = create_object(NULL, NULL, scd, 0);

    object_set_sprite(object, "./assets/image/menu/pause/resume.png",
        (sfIntRect) {-1, -1, -1, -1}, (sfVector2f) {800, 200});
    win->components = dico_t_add_data(win->components, "obj", object, NULL);
    object_set_sprite(fst_bt, "./assets/image/menu/pause/exit.png",
        (sfIntRect) {-1, -1, -1, -1}, (sfVector2f) {400, 200});
    event_add_node(create_event(NULL, true, fst_bt, click_fst),
        (node_params_t) {sfMouseLeft, sfKeyA, MOUSE});
    object_set_sprite(scd_bt, "./assets/image/menu/pause/home.png",
        (sfIntRect) {-1, -1, -1, -1}, (sfVector2f) {400, 200});
    event_add_node(create_event(NULL, true, scd_bt, click_scd),
        (node_params_t) {sfMouseLeft, sfKeyA, MOUSE});
    window_change_scene(win, "fst");
    loop(win);
    remove_window(win);
}