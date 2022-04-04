/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** init_menu
*/

#include "my_bgs_button_generator.h"

void close_window(object_t *, scene_t *, window_t *, set_event_t *);

void free_pop_up(void *list);

static void init_components(object_t *obj)
{
    event_add_node(create_event(NULL, false, obj,
        &close_window), (node_params_t)
        {sfMouseLeft, sfKeyEscape, KEY});
}
void init_main_menu_buttons(list_ptr_t **main_menu,
    list_ptr_t **load_game, scene_t *scene)
{
    *main_menu = create_button(scene, "./assets/json_menu/button.json");
    *load_game = create_button(scene,
        "./assets/json_menu/charge_button.json");
}

int init_menu(window_t *win)
{
    scene_t *scene = NULL;
    list_ptr_t *main_menu = NULL;
    list_ptr_t *load_game = NULL;
    object_t *obj = NULL;

    scene = create_scene(win, sfBlack, "MAIN MENU");
    if (!scene) {
        return (BGS_ERR_MALLOC);
    }
    obj = create_object(NULL, NULL, scene, 0);
    init_main_menu_buttons(&main_menu, &load_game, scene);
    if (!main_menu || !load_game || !obj) {
        return (BGS_ERR_MALLOC);
    }
    scene->components = dico_t_add_data(scene->components,
        "POP_UP_PLAY", load_game, free_pop_up);
    set_is_visible_false(load_game);
    return (0);
}
