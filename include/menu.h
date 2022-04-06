/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** menu
*/

#ifndef MENU_H_
    #define MENU_H_
    #define PLAY "POP_UP_PLAY"

    #include "my_bgs_button_generator.h"
    #include "my_bgs.h"
    #include "my_bgs_components.h"

void set_is_visible_false(list_ptr_t *);
int init_menu(window_t *);
void close_window(object_t *, scene_t *, window_t *, set_event_t *);
void free_pop_up(void *list);
int check_if_pop_up_true(dico_t *dico, char *key);
void close_window(object_t *obj, scene_t *scene,
    window_t *win, set_event_t *event);
void go_back(object_t *obj, scene_t *scene, window_t *win, set_event_t *event);
void play_pop_up(object_t *obj, scene_t *scene,
    window_t *win, set_event_t *event);

#endif /* !MENU_H_ */
