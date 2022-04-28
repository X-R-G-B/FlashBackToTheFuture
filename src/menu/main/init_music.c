/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** init_music
*/

#include "my_rpg.h"
#include "audio.h"

static const char music_path[] = "./assets/music/music.ogg";

int init_music(window_t *win, scene_t *scene)
{
    object_t *obj = NULL;

    if (win == NULL || scene == NULL) {
        return RET_ERR_INPUT;
    }
    obj = create_object(NULL, NULL, scene, 0);
    if (object_set_audio(obj, music_path, true, true) != BGS_OK) {
        return RET_ERR_INPUT;
    }
    add_new_audio(obj, win);
    return RET_OK;
}