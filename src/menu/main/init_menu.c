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

static void set_buttons(list_ptr_t **settings,
    list_ptr_t **main_menu, list_ptr_t **load_game, scene_t *scene)
{
    *settings = create_button(scene, settings_data_path);
    *main_menu = create_button(scene, main_menu_data_path);
    *load_game = create_button(scene, play_pop_up_menu_data_path);
}

static int init_main_menu_buttons(scene_t *scene)
{
    list_ptr_t *main_menu = NULL;
    list_ptr_t *load_game = NULL;
    list_ptr_t *settings = NULL;

    set_buttons(&settings, &main_menu, &load_game, scene);
    if (main_menu == NULL || load_game == NULL || settings == NULL) {
        return (RET_ERR_MALLOC);
    }
    scene->components = dico_t_add_data(scene->components,
        PLAY, load_game, free_pop_up);
    scene->components = dico_t_add_data(scene->components,
        SETTINGS_MENU, settings, free_pop_up);
    if (scene->components == NULL) {
        return (RET_ERR_MALLOC);
    }
    set_is_visible_false(settings);
    set_is_visible_false(load_game);
    free_list(main_menu);
    return (RET_OK);
}

int init_menu(window_t *win)
{
    scene_t *scene = NULL;
    object_t *obj = NULL;

    create_scene_loading_basic(win);
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
