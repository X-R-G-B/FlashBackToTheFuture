/*
** EPITECH PROJECT, 2022
** Defender
** File description:
** add components
*/

#include "my_bgs.h"
#include "my_dico.h"

int window_add_components(window_t *win, void *data, const char key[],
    void (*destroy)(void *))
{
    if (win == NULL || data == NULL || key == NULL) {
        return BGS_ERR_INPUT;
    }
    win->components = dico_t_add_data(win->components, key, data,
        destroy);
    if (win->components == NULL || win->components->last == NULL) {
        return BGS_ERR_MALLOC;
    }
    return BGS_OK;
}

int scene_add_components(scene_t *scene, void *data, const char key[],
    void (*destroy)(void *))
{
    if (scene == NULL || data == NULL || key == NULL) {
        return BGS_ERR_INPUT;
    }
    scene->components = dico_t_add_data(scene->components, key, data,
        destroy);
    if (scene->components == NULL || scene->components->last == NULL) {
        return BGS_ERR_MALLOC;
    }
    return BGS_OK;
}

int object_add_components(object_t *object, void *data, const char key[],
    void (*destroy)(void *))
{
    if (object == NULL || data == NULL || key == NULL) {
        return BGS_ERR_INPUT;
    }
    object->components = dico_t_add_data(object->components, key, data,
        destroy);
    if (object->components == NULL || object->components->last == NULL) {
        return BGS_ERR_MALLOC;
    }
    return BGS_OK;
}

void *object_get_components(object_t *object, char key[])
{
    if (object == NULL || key == NULL) {
        return NULL;
    }
    return dico_t_get_value(object->components, key);
}
