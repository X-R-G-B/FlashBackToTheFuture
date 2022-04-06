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

object_t *create_object(
    void (*update)(object_t *, scene_t *, window_t *win, float),
    void (*display)(object_t *, dico_t *, dico_t *, sfRenderWindow *),
    scene_t *scene, int layer)
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
    object->layer = layer;
    object->is_visible = (display) ? true : false;
    object->type = UNSET;
    object->components = dico_t_add_data(object->components, "scene",
        scene, NULL);
    if (object->components == NULL ||
        scene_add_object(scene, object, layer) != BGS_OK) {
        return NULL;
    }
    return object;
}
