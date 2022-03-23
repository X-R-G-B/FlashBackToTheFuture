/*
** EPITECH PROJECT, 2022
** bgs
** File description:
** create object
*/

#include <stdlib.h>
#include <stdbool.h>
#include "my_bgs.h"
#include "libbgs_private.h"

int object_set_audio(object_t *object, char const *path, bool play_now,
    bool loop_now)
{
    if (object == NULL || path == NULL) {
        return BGS_ERR_INPUT;
    }
    object->drawable.music = sfMusic_createFromFile(path);
    if (object->drawable.music == NULL) {
        return BGS_ERR_PATH;
    }
    if (play_now == true) {
        sfMusic_play(object->drawable.music);
    }
    if (loop_now == true) {
        sfMusic_setLoop(object->drawable.music, sfTrue);
    }
    object->type = AUDIO;
    return BGS_OK;
}

int object_set_custom(object_t *object)
{
    if (object == NULL) {
        return BGS_ERR_INPUT;
    }
    object->type = CUSTOM;
    return BGS_OK;
}

int object_set_text(object_t *object, char const *path, char const *text,
    sfVector2f pos)
{
    if (object == NULL || path == NULL || text == NULL) {
        return BGS_ERR_INPUT;
    }
    object->is_visible = true;
    object->bigdata.text_bigdata.pos = pos;
    object->bigdata.text_bigdata.font = sfFont_createFromFile(path);
    if (object->bigdata.text_bigdata.font == NULL) {
        return BGS_ERR_PATH;
    }
    object->drawable.text = sfText_create();
    if (object->drawable.text == NULL) {
        return BGS_ERR_MALLOC;
    }
    sfText_setFont(object->drawable.text, object->bigdata.text_bigdata.font);
    sfText_setString(object->drawable.text, text);
    object->type = TEXT;
    object->display = (object->display) ? object->display : &display_text;
    object_set_origin(object);
    return BGS_OK;
}

int object_set_sprite(object_t *object, char const *path, sfIntRect rect,
    sfVector2f pos)
{
    if (object == NULL || path == NULL) {
        return BGS_ERR_INPUT;
    }
    object->is_visible = true;
    object->bigdata.sprite_bigdata.image = sfImage_createFromFile(path);
    if (object->bigdata.sprite_bigdata.image == NULL) {
        return BGS_ERR_PATH;
    }
    if (sprite_set_texture(object, pos, rect) != BGS_OK) {
        return (BGS_ERR_MALLOC);
    }
    object->bigdata.sprite_bigdata.pos = pos;
    object->bigdata.sprite_bigdata.rect = rect;
    object->type = SPRITE;
    object->display = (object->display) ? object->display : &display_sprite;
    object_set_origin(object);
    return BGS_OK;
}

object_t *create_object(
    void (*update)(object_t *, scene_t *, window_t *win, float),
    void (*display)(object_t *, dico_t *, dico_t *, sfRenderWindow *),
    scene_t *scene)
{
    object_t *object = malloc(sizeof(object_t));

    if (object == NULL || scene == NULL) {
        return NULL;
    }
    object->bigdata.text_bigdata.font = NULL;
    object->drawable.music = NULL;
    object->components = NULL;
    object->update = update;
    object->display = display;
    object->is_visible = (display) ? true : false;
    object->type = UNSET;
    if (scene_add_object(scene, object) != BGS_OK) {
        return NULL;
    }
    return object;
}
