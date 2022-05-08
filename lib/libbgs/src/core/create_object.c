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

static int fill_object_def_value(
    object_t *object,
    void (*update)(object_t *, scene_t *, window_t *win, float),
    void (*display)(object_t *, dico_t *, dico_t *, sfRenderWindow *),
    int layer)
{
    object->bigdata.text_bigdata.font = NULL;
    object->drawable.music = NULL;
    object->components = NULL;
    object->update = update;
    object->display = display;
    object->layer = layer;
    object->is_visible = (display) ? true : false;
    object->type = UNSET;
    return (BGS_OK);
}

object_t *create_object(
    void (*update)(object_t *, scene_t *, window_t *win, float),
    void (*display)(object_t *, dico_t *, dico_t *, sfRenderWindow *),
    scene_t *scene, int layer)
{
    object_t *object = NULL;

    if (scene == NULL) {
        return (NULL);
    }
    object = malloc(sizeof(object_t));
    if (object == NULL) {
        return NULL;
    }
    if (fill_object_def_value(object, update, display, layer) != BGS_OK) {
        free(object);
        return (NULL);
    }
    if (object_add_components(object, scene, SCENE, NULL) != BGS_OK ||
            scene_add_object(scene, object, layer) != BGS_OK) {
        free(object);
        return (NULL);
    }
    return object;
}
