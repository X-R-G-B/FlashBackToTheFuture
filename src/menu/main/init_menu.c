/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** init_menu
*/

#include "my_rpg.h"
#include "main_menu.h"

static void add_escape_event(object_t *obj)
{
    event_add_node(create_event(NULL, false, obj,
        &close_window), (node_params_t)
        {sfMouseLeft, sfKeyEscape, KEY});
}

static void init_main_menu_buttons(list_ptr_t **main_menu,
    list_ptr_t **load_game, scene_t *scene)
{
    *main_menu = create_button(scene, "./assets/data/menu/main.json");
    *load_game = create_button(scene,
        "./assets/data/menu/charge_button.json");
}

int init_menu(window_t *win)
{
    scene_t *scene = NULL;
    list_ptr_t *main_menu = NULL;
    list_ptr_t *load_game = NULL;
    object_t *obj = NULL;

    scene = create_scene(win, sfBlack, "MAIN MENU");
    if (scene == NULL) {
        return (RET_ERR_MALLOC);
    }
    obj = create_object(NULL, NULL, scene, 0);
    init_main_menu_buttons(&main_menu, &load_game, scene);
    if (main_menu == NULL || load_game == NULL || obj == NULL) {
        return (RET_ERR_MALLOC);
    }
    add_escape_event(obj);
    scene->components = dico_t_add_data(scene->components,
        PLAY, load_game, free_pop_up);
    set_is_visible_false(load_game);
    free_list(main_menu);
    return RET_OK;
}
