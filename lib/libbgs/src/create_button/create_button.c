/*
** EPITECH PROJECT, 2022
** defender
** File description:
** create button
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my_strings.h"
#include "my_bgs_button_generator.h"

static int set_sprite(object_t *sprite, dico_t *dico)
{
    if (set_event(sprite, dico) != BGS_OK ||
        set_color(sprite, dico) != BGS_OK) {
        return BGS_ERR_MALLOC;
    }
    return BGS_OK;
}

static int init_sprite(float *pos, char *path, scene_t *scene, dico_t *dico)
{
    int layer = check_layer(dico);
    object_t *sprite = create_object(NULL, NULL, scene, layer);
    any_t *size = dico_t_get_any(dico, "size");

    if (sprite == NULL || object_set_sprite(sprite, path, (sfIntRect)
        {-1, -1, -1, -1}, (sfVector2f) {pos[1], pos[0]}) != BGS_OK) {
        return BGS_ERR_INPUT;
    }
    if (size != NULL && size->type == FLOAT) {
        sprite->components = dico_t_add_data(sprite->components, "size",
            any_dup(size), destroy_any);
        if (sprite->components == NULL) {
            return BGS_ERR_MALLOC;
        }
        sfSprite_setScale(sprite->drawable.sprite, (sfVector2f) {size->value.f,
            size->value.f});
    }
    return set_sprite(sprite, dico);
}

static int init_text(float *pos, scene_t *scene, char *arg[2], dico_t *dico)
{
    any_t *size = dico_t_get_any(dico, "text size");
    any_t *char_size = dico_t_get_any(dico, "char size");
    int layer = check_layer(dico);
    object_t *text = create_object(NULL, NULL, scene, layer);

    if (text == NULL || object_set_text(text, arg[0], arg[1],
        (sfVector2f) {pos[1], pos[0]}) != BGS_OK) {
        return BGS_OK;
    }
    if (size != NULL && size->type == FLOAT) {
        sfText_setScale(text->drawable.text, (sfVector2f) {size->value.f,
            size->value.f});
    }
    if (char_size != NULL && char_size->type == INT) {
        sfText_setCharacterSize(text->drawable.text, char_size->value.i);
    }
    set_color(text, dico);
    return BGS_OK;
}

static int get_button_data(scene_t *scene, any_t *dico)
{
    int ret = BGS_OK;
    float *txt_pos = get_any_float_array(dico_t_get_any(dico->value.dict,
        "text pos"));
    float *pos = get_any_float_array(dico_t_get_any(dico->value.dict, "pos"));
    any_t *text = dico_t_get_any(dico->value.dict, "text");
    any_t *sprite_path = dico_t_get_any(dico->value.dict, "sprite path");
    any_t *font_path = dico_t_get_any(dico->value.dict, "font path");
    char *arg[2] = {NULL, NULL};

    if (sprite_path != NULL && pos != NULL) {
        ret = init_sprite(pos, sprite_path->value.str, scene, dico->value.dict);
    }
    if (font_path != NULL && txt_pos != NULL && text != NULL && ret == BGS_OK) {
        arg[0] = font_path->value.str;
        arg[1] = text->value.str;
        ret = init_text(txt_pos, scene, arg, dico->value.dict);
    }
    destroy_pos_array(txt_pos, pos);
    return ret;
}

list_ptr_t *create_button(scene_t *scene, const char *path)
{
    list_t *list = NULL;
    any_t *any = parse_json_file(path);
    any_t *buttons_array = NULL;
    int ret = BGS_OK;

    if (any == NULL || scene == NULL) {
        return NULL;
    }
    list = scene->objects->end;
    buttons_array = dico_t_get_any(any->value.dict, "buttons");
    for (int i = 0; buttons_array != NULL && ret == BGS_OK &&
        i < buttons_array->value.array->len; i++) {
        ret = get_button_data(scene, get_from_any(any, "da", "buttons", i));
    }
    if (ret != BGS_OK) {
        destroy_any(any);
        return NULL;
    }
    destroy_any(any);
    return (buttons_array != NULL) ? fill_obj_list(list, scene) : NULL;
}
