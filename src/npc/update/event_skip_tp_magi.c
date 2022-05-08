/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** event to skip tp
*/

#include "my_bgs.h"
#include "my_bgs_framebuffer.h"
#include "my_json.h"
#include "npc.h"

extern const char rotation_data_key[];

extern const char total_time_key[];

void skip_event_magician_tp(object_t *obj,
    __attribute__((unused)) scene_t *scene,
    __attribute__ ((unused)) window_t *win,
    __attribute__((unused)) set_event_t *evt)
{
    any_t *rotation_data = NULL;
    any_t *total_time = NULL;

    printf("ok\n");
    if (obj == NULL) {
        return;
    }
    printf("oki\n");
    rotation_data = dico_t_get_value(obj->components, rotation_data_key);
    total_time = get_from_any(rotation_data, "d", total_time_key);
    if (total_time == NULL) {
        return;
    }
    total_time->value.f = 0;
}
