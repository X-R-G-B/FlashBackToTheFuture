/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** update text
*/

#include "my_rpg.h"

static const char time_key[] = "time";

static const char move_actualisation_key[] = "actualisation time";

static const char move_key[] = "move";

static const char char_size_key[] = "char size add";

extern const char text_data_key[];

static bool check_end(any_t *text_data, float *since_start, float *time)
{
    any_t *total_time = dico_t_get_any(text_data->value.dict, time_key);

    if (total_time == NULL || total_time->type != FLOAT ||
        *since_start >= total_time->value.f) {
        *since_start = 0;
        *time = 0;
        return true;
    }
    return false;
}

static void check_move(any_t *text_data, float *time, object_t *obj)
{
    any_t *move = dico_t_get_any(text_data->value.dict, move_key);
    any_t *char_size_add = dico_t_get_any(text_data->value.dict, char_size_key);
    any_t *actualisation_time = dico_t_get_any(text_data->value.dict,
        move_actualisation_key);
    int char_size = sfText_getCharacterSize(obj->drawable.text);

    if (actualisation_time == NULL || actualisation_time->type != FLOAT ||
            move == NULL || move->type != FLOAT || char_size_add == NULL ||
            char_size_add->type != INT) {
        return;
    }
    while (*time >= actualisation_time->value.f) {
        *time -= actualisation_time->value.f;
        obj->bigdata.text_bigdata.pos.y -= move->value.f;
        obj->bigdata.text_bigdata.pos.x -= char_size_add->value.i;
        sfText_setCharacterSize(obj->drawable.text,
            char_size + char_size_add->value.i);
    }
}

void update_text(object_t *obj, scene_t *scene, window_t *win,
    float dtime)
{
    any_t *text_data = NULL;
    static float since_start = 0;
    static float time = 0;

    if (obj == NULL || scene == NULL || win == NULL) {
        return;
    }
    text_data = dico_t_get_value(obj->components, text_data_key);
    if (text_data == NULL || text_data->type != DICT) {
        return;
    }
    since_start += dtime;
    time += dtime;
    if (check_end(text_data, &since_start, &time) == true) {
        list_add_to_end(scene->to_remove, obj);
        return;
    }
    check_move(text_data, &time, obj);
}
