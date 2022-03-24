/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** main entry point
*/

#include "my_bgs_components.h"

void click_scene_2(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    printf("oe\n");
    sfSprite_setColor(obj->drawable.sprite, sfRed);
}

void off_click_scene_2(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    printf("deuxieme\n");
    sfSprite_setColor(obj->drawable.sprite, sfWhite);
}

int main(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfUint32 style = sfClose | sfResize;
    window_t *win = create_window(mode, "TEST", style);
    scene_t *scene = NULL;
    list_ptr_t *button_list = NULL;

    if (win == NULL) {
        return 84;
    }
    scene = create_scene(win, sfBlack);
    if (scene == NULL) {
        return 84;
    }
    button_list = create_button(scene, "./tests/menu.json");
    if (button_list == NULL) {
        printf("NULL\n");
    }
    loop(win);
    remove_window(win);
    return (0);
}
