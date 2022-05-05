/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** init_menu
*/

#include "my_rpg.h"
#include "audio.h"
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

static void set_button_rectangle(list_ptr_t *buttons)
{
    object_t *obj = get_element_i_var(buttons, 1);

    if (obj == NULL) {
        return;
    }
    obj->bigdata.sprite_bigdata.rect = (sfIntRect) {273, 9, 231, 76};
    obj = get_element_i_var(buttons, 3);
    if (obj == NULL) {
        return;
    }
    obj->bigdata.sprite_bigdata.rect = (sfIntRect) {17, 8, 454, 80};
    obj = get_element_i_var(buttons, 0);
    if (obj == NULL) {
        return;
    }
    obj->bigdata.sprite_bigdata.rect = (sfIntRect) {13, 5, 217, 75};
    obj = get_element_i_var(buttons, 2);
    if (obj != NULL) {
        obj->bigdata.sprite_bigdata.rect = (sfIntRect) {0, 0, 425, 59};
    }
}

static int init_main_menu_buttons(scene_t *scene, window_t *win)
{
    list_ptr_t *main_menu = NULL;
    list_ptr_t *load_game = NULL;
    list_ptr_t *settings = NULL;

    set_buttons(&settings, &main_menu, &load_game, scene);
    if (main_menu == NULL || load_game == NULL || settings == NULL) {
        return (RET_ERR_MALLOC);
    }
    set_button_rectangle(main_menu);
    window_add_component(win, settings, SETTINGS_MENU, free_pop_up);
    set_drag_objects(settings, win, scene);
    scene_add_components(scene, load_game, PLAY, free_pop_up);
    scene_add_components(scene, main_menu, MENU, free_pop_up);
    if (scene->components == NULL) {
        return (RET_ERR_MALLOC);
    }
    set_is_visible_false(settings);
    set_is_visible_false(load_game);
    return (RET_OK);
}

int init_menu(window_t *win)
{
    scene_t *scene = NULL;
    object_t *obj = NULL;

    create_scene_loading_basic(win);
    scene = create_scene(win, sfBlack, "MAIN MENU");
    if (scene == NULL || init_music(win, scene) != RET_OK) {
        return (RET_ERR_MALLOC);
    }
    obj = create_object(NULL, NULL, scene, 0);
    if (init_main_menu_buttons(scene, win) == RET_ERR_MALLOC || obj == NULL) {
        return (RET_ERR_MALLOC);
    }
    init_making_of(scene);
    add_escape_event(obj);
    return RET_OK;
}
