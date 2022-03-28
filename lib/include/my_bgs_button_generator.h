/*
** EPITECH PROJECT, 2022
** my bgs
** File description:
** button generator
*/

#ifndef BUTTON_H_
    #define BUTTON_H_

    #include "my_bgs_components.h"
    #include "my_json.h"

extern void (*on_click[])(object_t *, scene_t *, window_t *, set_event_t *);

extern const char *str_on_click[];

extern void (*off_click[])(object_t *, scene_t *, window_t *, set_event_t *);

extern const char *str_off_click[];

extern void (*on_hover[])(object_t *, scene_t *, window_t *, set_event_t *);

extern const char *str_on_hover[];

extern void (*off_hover[])(object_t *, scene_t *, window_t *, set_event_t *);

extern const char *str_off_hover[];

int set_event(object_t *object, dico_t *dico);

list_ptr_t *fill_obj_list(list_t *elem, scene_t *scene);

int set_clr(object_t *object, dico_t *dico);

#endif /* !BUTTON_H_ */
