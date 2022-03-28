/*
** EPITECH PROJECT, 2022
** my bgs
** File description:
** object_set_type.c
*/

#include "my_bgs.h"
#include "libbgs_private.h"

static int check_display_function(object_t *obj)
{
    scene_t *scene = dico_t_get_value(obj->components, "scene");
    list_t *elem = NULL;
    plan_t *plan = NULL;

    if (scene == NULL) {
        return BGS_ERR_INPUT;
    } else if (obj->display != NULL) {
        return BGS_OK;
    }
    obj->display = (obj->type == SPRITE) ? display_sprite : display_text;
    elem = scene->plan->start;
    for (int i = 0; i < scene->plan->len; i++, elem = elem->next) {
        plan = elem->var;
        if (plan->id == obj->plan &&
            list_add_to_end(plan->displayables, obj) == NULL) {
            return BGS_ERR_MALLOC;
        }
    }
    return BGS_OK;
}

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
    object_set_origin(object);
    return check_display_function(object);
}

int object_set_sprite(object_t *object, char const *path, sfIntRect rect,
    sfVector2f pos)
{
    if (object == NULL || path == NULL) {
        return BGS_ERR_INPUT;
    }
    object->is_visible = true;
    if (sprite_set_texture(object, pos, rect, path) != BGS_OK) {
        return BGS_ERR_MALLOC;
    }
    object->bigdata.sprite_bigdata.pos = pos;
    object->bigdata.sprite_bigdata.rect = rect;
    object->type = SPRITE;
    object_set_origin(object);
    return check_display_function(object);
}