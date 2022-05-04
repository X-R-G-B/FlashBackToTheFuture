/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** create pop text
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "macro.h"

const char text_data_key[] = "text data";

static const char color_key[] = "color";

static const char font_key[] = "font";

static const char char_size_key[] = "char size";

static any_t *get_text_data(scene_t *scene, const char *path, char *text)
{
    if (scene == NULL || path == NULL || text == NULL) {
        return NULL;
    }
    return parse_json_file(path);
}

static void object_check_change(object_t *obj, any_t *text_data)
{
    any_t *color_array = dico_t_get_any(text_data->value.dict, color_key);
    int *color = get_any_int_array(color_array);
    any_t *char_size = dico_t_get_any(text_data->value.dict, char_size_key);

    if (color != NULL && color_array->value.array->len > 3) {
        sfText_setColor(obj->drawable.text,
            sfColor_fromRGBA(color[0], color[1], color[2], color[3]));
    }
    if (color != NULL) {
        free(color);
    }
    if (char_size != NULL && char_size->type == INT) {
        sfText_setCharacterSize(obj->drawable.text, char_size->value.i);
    }
}

static object_t *create_text(scene_t *scene, any_t *text_data, sfVector2f pos,
    char *text)
{
    object_t *obj = NULL;
    any_t *font = get_from_any(text_data, "d", font_key);

    if (text == NULL || font == NULL || font->type != STR) {
        return NULL;
    }
    obj = create_object(update_text, NULL, scene, LAYER_PLAYER);
    if (object_set_text(obj, font->value.str, text, pos) != BGS_OK) {
        return NULL;
    }
    obj->components = dico_t_add_data(obj->components, text_data_key, text_data,
        destroy_any);
    if (obj->components == NULL) {
        list_add_to_end(scene->to_remove, obj);
        return NULL;
    }
    object_check_change(obj, text_data);
    return obj;
}

int create_pop_text(scene_t *scene, const char *path, sfVector2f pos,
    char *text)
{
    any_t *text_data = get_text_data(scene, path, text);
    object_t *text_obj = create_text(scene, text_data, pos, text);

    return (text_obj == NULL) ? RET_ERR_INPUT : RET_OK;
}
