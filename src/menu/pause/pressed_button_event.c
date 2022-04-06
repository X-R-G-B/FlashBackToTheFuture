/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** pressed button event
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_json.h"

static void set_sprite_new_rect(object_t *obj, int *rect, int *origin)
{
    obj->bigdata.sprite_bigdata.rect = (sfIntRect) {rect[0], rect[1], rect[2],
        rect[3]};
    sfSprite_setOrigin(obj->drawable.sprite, (sfVector2f) {origin[0],
        origin[1]});
    free(rect);
    free(origin);
}

void pressed_button_on(object_t *obj, scene_t *scene,
    __attribute__((unused)) window_t *win,
    __attribute__((unused)) set_event_t *evt)
{
    any_t *data = dico_t_get_any(obj->components, "data");
    int *rect = NULL;
    int *origin = NULL;

    if (data == NULL || scene->pause == false) {
        return;
    }
    data = dico_t_get_any(data->value.dict, "on");
    if (data == NULL || data->type != ARRAY) {
        return;
    }
    rect = get_any_int_array(data->value.array->start->var);
    origin = get_any_int_array(data->value.array->end->var);
    if (rect == NULL || origin == NULL) {
        return;
    }
    set_sprite_new_rect(obj, rect, origin);
}

void pressed_button_off(object_t *obj, __attribute__((unused)) scene_t *scene,
    __attribute__((unused)) window_t *win,
    __attribute__((unused)) set_event_t *evt)
{
    any_t *data = dico_t_get_any(obj->components, "data");
    int *rect = NULL;
    int *origin = NULL;

    if (data == NULL) {
        return;
    }
    data = dico_t_get_any(data->value.dict, "off");
    if (data == NULL || data->type != ARRAY) {
        return;
    }
    rect = get_any_int_array(data->value.array->start->var);
    origin = get_any_int_array(data->value.array->end->var);
    if (rect == NULL || origin == NULL) {
        return;
    }
    set_sprite_new_rect(obj, rect, origin);
}
