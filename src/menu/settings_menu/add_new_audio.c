/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** add new audio
*/

#include "my_rpg.h"
#include "audio.h"

static list_ptr_t *get_list(enum object_type type, window_t *win, object_t *obj)
{
    if (obj == NULL || (type != AUDIO && type != SOUND)) {
        return NULL;
    }
    if (type == AUDIO) {
        return dico_t_get_value(win->components, AUDIO_LIST);
    } else if (type == SOUND) {
        return dico_t_get_value(win->components, SOUND_LIST);
    }
    return NULL;
}

static void remove_object_from_audio_list(void *data)
{
    object_t *obj = data;
    scene_t *scene = NULL;
    window_t *win = NULL;

    if (data == NULL) {
        return;
    }
    scene = dico_t_get_value(obj->components, SCENE);
    if (scene == NULL) {
        return;
    }
    win = dico_t_get_value(scene->components, WINDOW);
    if (win == NULL) {
        return;
    }
    if (obj->type == AUDIO) {
        check_list(dico_t_get_value(win->components, AUDIO_LIST), obj);
    } else if (obj->type == SOUND) {
        check_list(dico_t_get_value(win->components, SOUND_LIST), obj);
    }
}

int add_new_audio(object_t *object, enum object_type type, window_t *win)
{
    list_ptr_t *list = get_list(type, win, object);

    if (list == NULL) {
        return RET_ERR_INPUT;
    }
    list_add_to_end(list, object);
    object->components = dico_t_add_data(object->components, "remove_from_list",
        object, remove_object_from_audio_list);
    return RET_OK;
}
