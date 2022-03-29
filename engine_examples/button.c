/*
** EPITECH PROJECT, 2022
** button generator
** File description:
** tests
*/

#include "my_bgs_button_generator.h"

static void onn_hover(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *event)
{
    sfSprite_setScale(obj->drawable.sprite, (sfVector2f) {1.5, 1.5});
}

static void offf_hover(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *event)
{
    sfSprite_setScale(obj->drawable.sprite, (sfVector2f) {1.0, 1.0});
}

const char *str_on_hover[] = {"test", NULL};

void (*on_hover[])(object_t *, scene_t *, window_t *win, set_event_t *) =
    {onn_hover};

const char *str_off_hover[] = {"test", NULL};

void (*off_hover[])(object_t *, scene_t *, window_t *win, set_event_t *) =
    {offf_hover};

const char *str_on_click[] = {NULL};

void (*on_click[])(object_t *, scene_t *, window_t *win, set_event_t *);

const char *str_off_click[] = {NULL};

void (*off_click[])(object_t *, scene_t *, window_t *win, set_event_t *);

int main(int ac, char **av)
{
    sfVideoMode mode = {1920, 1080, 32};
    window_t *win = create_window(mode, "t", sfResize | sfClose);
    scene_t *scene = create_scene(win, sfBlack, "SALUT");
    list_ptr_t *list = create_button(scene, "./tests/t.json");

    window_change_scene(win, "SALUT");
    loop(win);
    remove_window(win);
    return 0;
}
