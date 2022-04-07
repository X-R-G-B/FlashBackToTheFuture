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

static int init_main_menu_buttons(scene_t *scene)
{
    list_ptr_t *main_menu = NULL;
    list_ptr_t *load_game = NULL;
    list_ptr_t *settings = NULL;

    settings = create_button(scene, "./assets/data/menu/settings_menu.json");
    main_menu = create_button(scene, "./assets/data/menu/menu_button.json");
    load_game = create_button(scene,"./assets/data/menu/play_pop_up.json");
    if (main_menu == NULL || load_game == NULL || settings == NULL) {
        return (RET_ERR_MALLOC);
    }
    scene->components = dico_t_add_data(scene->components,
        PLAY, load_game, free_pop_up);
    scene->components = dico_t_add_data(scene->components,
        SETTINGS_MENU, settings, free_pop_up);
    set_is_visible_false(settings);
    set_is_visible_false(load_game);
    free_list(main_menu);
    return (RET_OK);
}

int init_menu(window_t *win)
{
    scene_t *scene = NULL;
    object_t *obj = NULL;

    scene = create_scene(win, sfBlack, "MAIN MENU");
    if (scene == NULL) {
        return (RET_ERR_MALLOC);
    }
    obj = create_object(NULL, NULL, scene, 0);
    init_main_menu_buttons(scene);
    if (init_main_menu_buttons(scene) == RET_ERR_MALLOC || obj == NULL) {
        return (RET_ERR_MALLOC);
    }
    add_escape_event(obj);
    return RET_OK;
}
