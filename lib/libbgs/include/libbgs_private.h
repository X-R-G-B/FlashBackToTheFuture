/*
** EPITECH PROJECT, 2022
** libgs
** File description:
** private header file for the lib
*/

#ifndef BGS_PREIVATE_H_
    #define BGS_PREIVATE_H_

    #include <SFML/Graphics.h>
    #include "list.h"
    #include "my_bgs.h"
    #include "my_bgs_components.h"

typedef struct square_s square_t;

struct square_s {
    int y;
    int x;
    int size;
};

int event_handling(sfRenderWindow *win, window_t *window);

scene_t *get_scene_i(list_ptr_t *list, int i);

void object_update(object_t *object, scene_t *scene,
    window_t *win, float seconds);

void display_sprite(object_t *object, dico_t *scene_components,
    dico_t *win_compoent, sfRenderWindow *win);

void object_set_origin(object_t *object);

void display_text(object_t *object, dico_t *scene_components,
    dico_t *win_components, sfRenderWindow *win);

int add_to_update_display_list(scene_t *scene, object_t *object);

unsigned char *get_id_generator(char dest[255]);

char *get_id_generator_cat(char dest[255]);

int check_hover(object_t *object, window_t *win);

void window_setup_scene(window_t *win);

int object_set_event(object_t *object, set_event_t *usr_event);

void object_check_event(object_t *object, scene_t *scene,
        window_t *win);

void window_remove(scene_t *scene, window_t *win);

sfFloatRect find_higher_pixels_group(char **arr);

char **check_image_pixel(sfImage *image);

int squares_handling(char **arr, list_ptr_t *solid_squares);

sfFloatRect get_right_checkbox(object_t *obj, sfFloatRect *rect);

bool check_collision(sfFloatRect *this_rect, sfFloatRect *other_rect,
    object_t *this, object_t *other);

int sprite_set_texture(object_t *object, sfVector2f pos, sfIntRect rect);

sfFloatRect *get_rect_arr(list_ptr_t *list, object_t *object,
    sfFloatRect object_bounce);

int window_update_event(window_t *win, scene_t *scene);

int scene_update_event(window_t *win, scene_t *scene);

bool check_click_prev_call(bool check, window_t *win, set_event_t *set_event);

#endif
