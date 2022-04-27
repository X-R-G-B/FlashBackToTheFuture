/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** add new audio
*/

#include "my_rpg.h"
#include "audio.h"

static list_ptr_t *get_list(window_t *win, object_t *obj)
{
    if (obj == NULL || (obj->type != AUDIO && obj->type != SOUND)) {
        return NULL;
    }
    if (obj->type == AUDIO) {
        return dico_t_get_value(win->components, AUDIO_LIST);
    } else if (obj->type == SOUND) {
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

static void set_volume(object_t *obj, window_t *win)
{
    any_t *save = dico_t_get_any(win->components, SAVE);
    any_t *percentage = NULL;

    if (obj->type == AUDIO) {
        percentage = get_from_any(save, "d", MUSIC_VOLUME);
    } else if (obj->type == SOUND) {
        percentage = get_from_any(save, "d", SOUND_VOLUME);
    }
    if (percentage == NULL || percentage->type != FLOAT) {
        return;
    }
    if (obj->type == AUDIO) {
        sfMusic_setVolume(obj->drawable.music, percentage->value.f);
    } else if (obj->type == SOUND) {
        sfSound_setVolume(obj->drawable.sound, percentage->value.f);
    }
}

int add_new_audio(object_t *object, window_t *win)
{
    list_ptr_t *list = get_list(win, object);

    if (list == NULL) {
        return RET_ERR_INPUT;
    }
    list_add_to_end(list, object);
    set_volume(object, win);
    object->components = dico_t_add_data(object->components, "remove_from_list",
        object, remove_object_from_audio_list);
    return RET_OK;
}
