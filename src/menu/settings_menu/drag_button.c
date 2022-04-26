/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** drag button off
*/

#include "audio.h"

void drag_button_on(object_t *obj, __attribute__((unused)) scene_t *scene,
    window_t *win, __attribute__((unused)) set_event_t *evt)
{
    float *delimitation = NULL;
    sfVector2i mouse_pos_i = {0};
    sfVector2f mouse_pos = {0};

    if (obj == NULL || win == NULL) {
        return;
    }
    delimitation = (float *) dico_t_get_value(obj->components, DELIMITATION);
    if (delimitation == NULL) {
        return;
    }
    sfSprite_setScale(obj->drawable.sprite, (sfVector2f) {1.0, 1.0});
    mouse_pos_i = sfMouse_getPositionRenderWindow(win->win);
    mouse_pos = (sfVector2f) {mouse_pos_i.x, mouse_pos_i.y};
    if (mouse_pos.x < delimitation[0] || mouse_pos.x > delimitation[1]) {
        return;
    }
    obj->bigdata.sprite_bigdata.pos.x = mouse_pos.x;
}

void sound_drag_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    if (obj == NULL || scene == NULL || win == NULL || evt == NULL) {
        return;
    }
    sfSprite_setScale(obj->drawable.sprite, (sfVector2f) {1.0, 1.0});
}

void music_drag_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    if (obj == NULL || scene == NULL || win == NULL || evt == NULL) {
        return;
    }
    sfSprite_setScale(obj->drawable.sprite, (sfVector2f) {1.0, 1.0});
}
