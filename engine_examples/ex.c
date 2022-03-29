/*
** EPITECH PROJECT, 2022
** tests
** File description:
** tests
*/

#include "my_bgs.h"

void hov(object_t *obj, scene_t *scene, window_t *win, set_event_t *evt)
{
    sfSprite_setScale(obj->drawable.sprite, (sfVector2f) {1.05, 1.05});
}

void hove(object_t *obj, scene_t *scene, window_t *win, set_event_t *evt)
{
    sfSprite_setScale(obj->drawable.sprite, (sfVector2f) {1.0, 1.0});
}

void offf(object_t *obj, scene_t *scene, window_t *win, set_event_t *evt)
{
    my_putstr(1, "fin a\n");
}

void scdoff(object_t *obj, scene_t *scene, window_t *win, set_event_t *evt)
{
    my_putstr(1, "fin b\n");
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

void (*on_hover[])(object_t *, scene_t *, window_t *, set_event_t *) =
    {hov, hov};

const char *str_off_hover[] = {"fst", "scd", NULL};

void (*off_hover[])(object_t *, scene_t *, window_t *, set_event_t *) =
    {hove, hove};

const char *str_on_click[] = {"fst", "scd", NULL};

void (*on_click[])(object_t *, scene_t *, window_t *, set_event_t *) =
    {click, scdclick};

const char *str_off_click[] = {"fst", "scd", NULL};

void (*off_click[])(object_t *, scene_t *, window_t *, set_event_t *) =
    {offf, scdoff};

int main(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    window_t *win = create_window(mode, "t", sfResize | sfClose);
    scene_t *scene = create_scene(win, sfBlack, "PD");

    create_button(scene, "./tests/f.json");
    window_change_scene(win, "PD");
    loop(win);
    remove_window(win);
    return 0;
}
