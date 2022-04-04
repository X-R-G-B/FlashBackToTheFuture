/*
** EPITECH PROJECT, 2022
** button generator
** File description:
** tests
*/

#include "my_bgs_button_generator.h"
#include "my_bgs.h"
#include "my_bgs_components.h"

void set_is_visible_false(list_ptr_t *);

int init_menu(window_t *);

void load_save_scene(object_t *obj, scene_t *scene,
    window_t *win, set_event_t *event);

void close_window(object_t *obj, scene_t *scene,
    window_t *win, set_event_t *event)
{
    if (check_if_pop_up_true(scene, "POP_UP_PLAY"))
        return;
    sfRenderWindow_close(win->win);
}

void retour(object_t *obj, scene_t *scene, window_t *win, set_event_t *event)
{
    set_is_visible_false(dico_t_get_value(scene->components, "POP_UP_PLAY"));
}

const char *str_on_hover[] = {NULL};

void (*on_hover[])(object_t *, scene_t *, window_t *win, set_event_t *) = {
    NULL
};

const char *str_off_hover[] = {NULL};

void (*off_hover[])(object_t *, scene_t *, window_t *win, set_event_t *) = {
    NULL
};
const char *str_on_click[] = {NULL};

void (*on_click[])(object_t *, scene_t *, window_t *win, set_event_t *) = {
    NULL
};

const char *str_off_click[] = {"QUIT", "PLAY", "Retour", "Back", NULL};

void (*off_click[])(object_t *, scene_t *, window_t *win, set_event_t *) = {
    &close_window, &load_save_scene, &retour, &retour, NULL
};

int main(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    window_t *win = create_window(mode, "My_Rpg", sfResize | sfClose);

    init_menu(win);
    window_change_scene(win, "MAIN MENU");
    loop(win);
    remove_window(win);
    return 0;
}
