/*
** EPITECH PROJECT, 2022
** bgs
** File description:
** create scene
*/

#include <stdlib.h>
#include "my_bgs.h"

int sprite_set_texture(object_t *object, sfVector2f pos, sfIntRect rect)
{
    object->drawable.sprite = sfSprite_create();
    object->bigdata.sprite_bigdata.texture = sfTexture_createFromImage(
        object->bigdata.sprite_bigdata.image, NULL);
    if (object->drawable.sprite == NULL ||
        object->bigdata.sprite_bigdata.texture == NULL) {
        return BGS_ERR_MALLOC;
    }
    sfSprite_setTexture(object->drawable.sprite,
        object->bigdata.sprite_bigdata.texture, sfTrue);
    if (pos.x > -1) {
        sfSprite_setPosition(object->drawable.sprite, pos);
    }
    if (rect.height > -1) {
        sfSprite_setTextureRect(object->drawable.sprite, rect);
    }
    return BGS_OK;
}

static int init_list(scene_t *scene)
{
    scene->displayables = list_create();
    if (scene->displayables == NULL) {
        return BGS_ERR_MALLOC;
    }
    scene->objects = list_create();
    if (scene->objects == NULL) {
        return BGS_ERR_MALLOC;
    }
    scene->updates = list_create();
    if (scene->updates == NULL) {
        return BGS_ERR_MALLOC;
    }
    scene->to_remove = list_create();
    if (scene->to_remove == NULL) {
        return BGS_ERR_MALLOC;
    }
    return BGS_OK;
}

scene_t *create_scene(window_t *win, sfColor bg_color)
{
    scene_t *scene = malloc(sizeof(scene_t));

    if (scene == NULL || win == NULL) {
        return NULL;
    }
    scene->components = NULL;
    scene->bg_color = bg_color;
    scene->pause = false;
    if (init_list(scene) != BGS_OK || window_add_scene(win, scene) != BGS_OK) {
        return NULL;
    }
    return scene;
}
