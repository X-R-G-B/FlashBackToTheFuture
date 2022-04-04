/*
** EPITECH PROJECT, 2022
** button generator
** File description:
** tests
*/

#include "my_bgs_button_generator.h"
#include "my_bgs.h"
#include "my_bgs_components.h"


void close_window(object_t *obj, scene_t *scene, window_t *win, set_event_t *event)
{
    sfRenderWindow_close(win->win);
}

void retour(object_t *obj, scene_t *scene, window_t *win, set_event_t *event)
{
    window_change_scene(win, "MENU");
}

void load_save_scene(object_t *obj, scene_t *scene, window_t *win, set_event_t *event)
{
    list_ptr_t *buttons = NULL;

    scene = create_scene(win, sfBlack, "CHARGE GAME");
    buttons = create_button(scene, "./assets/json_menu/charge_button.json");
    // obj = create_object(NULL, NULL, scene, 0);
    window_change_scene(win, "CHARGE GAME");
    // event = create_event(NULL, false, obj, &close_window);
    // event_add_node(event, (node_params_t) {sfMouseLeft, sfKeyEscape, KEY});
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

const char *str_off_click[] = {"QUIT", "PLAY","Retour", NULL};

void (*off_click[])(object_t *, scene_t *, window_t *win, set_event_t *) = {
    &close_window, &load_save_scene, &retour, NULL
};

int main(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    window_t *win = create_window(mode, "My_Rpg", sfResize | sfClose);
    scene_t *scene = create_scene(win, sfBlack, "MENU");
    list_ptr_t *list = create_button(scene, "./assets/json_menu//button.json");
    object_t *obj = create_object(NULL, NULL, scene, 0);

    object_set_custom(obj);
    window_change_scene(win, "MENU");
    set_event_t *salut_event = create_event(NULL, false, obj, &close_window);
    event_add_node(salut_event, (node_params_t)
                    {sfMouseLeft, sfKeyEscape, KEY});
    loop(win);
    remove_window(win);
    return 0;
}
