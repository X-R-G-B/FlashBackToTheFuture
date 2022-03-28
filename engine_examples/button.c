/*
** EPITECH PROJECT, 2022
** button generator
** File description:
** tests
*/

#include "my_bgs_button_generator.h"
#include "my_puts.h"

void hov(object_t *obj, scene_t *scene, window_t *win, set_event_t *evt)
{
    sfSprite_setScale(obj->drawable.sprite, (sfVector2f) {1.05, 1.05});
}

void hove(object_t *obj, scene_t *scene, window_t *win, set_event_t *evt)
{
    sfSprite_setScale(obj->drawable.sprite, (sfVector2f) {1.0, 1.0});
}

void click(object_t *obj, scene_t *scene, window_t *win, set_event_t *evt)
{
    my_putstr(1, "aaaaaaaa\n");
}

void scdclick(object_t *obj, scene_t *scene, window_t *win, set_event_t *evt)
{
    my_putstr(1, "bbbbbbbbb\n");
}

const char *str_on_hover[] = {"fst", "scd", NULL};

void (*on_hover[])(object_t *, scene_t *, window_t *win, set_event_t *) =
    {hov, hov};

const char *str_off_hover[] = {"fst", "scd", NULL};

void (*off_hover[])(object_t *, scene_t *, window_t *win, set_event_t *) =
    {hove, hove};

const char *str_on_click[] = {"fst", "scd", NULL};

void (*on_click[])(object_t *, scene_t *, window_t *win, set_event_t *) =
    {click, scdclick};

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
