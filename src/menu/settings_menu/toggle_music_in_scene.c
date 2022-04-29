/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** toggle music in scene
*/

#include "my_rpg.h"
#include "audio.h"

static int toggle_audio(object_t *obj)
{
    sfSoundStatus status = {0};

    if (obj->type != AUDIO) {
        return RET_ERR_INPUT;
    }
    status = sfMusic_getStatus(obj->drawable.music);
    if (status != sfPlaying) {
        printf("play\n");
        sfMusic_play(obj->drawable.music);
    } else {
        printf("stop\n");
        sfMusic_stop(obj->drawable.music);
    }
    return RET_OK;
}

static int toggle_audio_list(scene_t *scene, list_ptr_t *audio_list)
{
    list_t *elem = audio_list->start;
    object_t *obj_ptr = NULL;
    scene_t *scene_ptr = NULL;

    for (int i = 0; i < audio_list->len && elem->var != NULL; i++,
        elem = elem->var) {
        obj_ptr = elem->var;
        scene_ptr = dico_t_get_value(obj_ptr->components, SCENE);
        if (scene_ptr != NULL && scene_ptr == scene &&
                toggle_audio(obj_ptr) != RET_OK) {
            return RET_ERR_INPUT;
        }
    }
    return (elem->var == NULL) ? RET_ERR_INPUT : RET_OK;
}

int toggle_music_in_scene(scene_t *scene)
{
    list_ptr_t *audio_list = NULL;
    window_t *win = NULL;

    if (scene == NULL) {
        return RET_ERR_INPUT;
    }
    win = dico_t_get_value(scene->components, WINDOW);
    if (win == NULL) {
        return RET_ERR_INPUT;
    }
    audio_list = dico_t_get_value(win->components, AUDIO_LIST);
    if (audio_list == NULL || audio_list == 0) {
        return RET_ERR_INPUT;
    }
    return toggle_audio_list(scene, audio_list);
}
