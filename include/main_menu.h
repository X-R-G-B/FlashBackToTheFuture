/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** menu
*/

#ifndef MENU_H_
    #define MENU_H_
    #define PLAY "POP_UP_PLAY"
    #define SETTINGS_MENU "SETTINGS_POP_UP"
    #define MENU "MAIN_MENU_BUTTONS"

    #include "my_bgs_button_generator.h"
    #include "my_bgs.h"
    #include "my_bgs_components.h"

extern const char play_pop_up_menu_data_path[];
extern const char main_menu_data_path[];
extern const char settings_data_path[];

void set_is_visible_false(list_ptr_t *);

int init_menu(window_t *);

void close_window(object_t *, scene_t *, window_t *, set_event_t *);

void set_sandbox_overlay(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *event);

void free_pop_up(void *list);

void replace_button(object_t *obj, dico_t *dico);

int check_if_pop_up_true(dico_t *dico, const char *key);

void sandbox_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt);

void add_scene_pop_up_component(scene_t *scene, list_ptr_t *buttons,
    char *key);

void add_scene_component(scene_t *scene, list_ptr_t *component,
    char *key);

void close_window(object_t *obj, scene_t *scene,
    window_t *win, set_event_t *event);

void go_back(object_t *obj, scene_t *scene, window_t *win, set_event_t *event);

void play_pop_up(object_t *obj, scene_t *scene,
    window_t *win, set_event_t *event);

void settings_pop_up( object_t *obj, scene_t *scene,
    window_t *win, set_event_t *event);

void click_sandbox(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *event);

int create_scene_loading_basic(window_t *win);

void set_60_fps(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *event);

void set_144_fps(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *event);

void set_120_fps(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *event);

void set_165_fps(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *event);

void click_play(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *event);

void click_settings(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *event);

void click_exit(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *event);

void exit_game(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *event);

void set_exit_overlay(object_t *obj, scene_t *scene,
    window_t *win, set_event_t *event);

void set_settings_overlay(object_t *obj, scene_t *scene,
    window_t *win, set_event_t *event);

void set_play_overlay(object_t *obj, scene_t *scene,
    window_t *win, set_event_t *event);

void set_credits_overlay(object_t *obj, scene_t *scene,
    window_t *win, set_event_t *event);

int init_making_of(scene_t *scene, const char *path_root);

#endif /* !MENU_H_ */
