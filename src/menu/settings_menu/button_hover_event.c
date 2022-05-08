/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** button hover event
*/

#include "my_bgs.h"

void drag_button_on_hover(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    if (obj == NULL || scene == NULL || win == NULL || evt == NULL ||
        sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        return;
    }
    sfSprite_setScale(obj->drawable.sprite, (sfVector2f) {1.3, 1.3});
}

void drag_button_off_hover(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    if (obj == NULL || scene == NULL || win == NULL || evt == NULL) {
        return;
    }
    sfSprite_setScale(obj->drawable.sprite, (sfVector2f) {1.0, 1.0});
}
