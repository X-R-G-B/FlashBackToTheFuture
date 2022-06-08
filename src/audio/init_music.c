/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-xavier.mitault
** File description:
** init_music
*/

#include "my_rpg.h"
#include "my_bgs_components.h"
#include "audio.h"
#include "macro.h"

extern const int layer;

static const char music_in_game[] =
    "./assets/music/game_music.ogg";
const char MUSIC_GAME[] = "musicgame";

static const char *keys_to_get[] = {
    MUSIC_GAME, NULL
};

static const char *paths_to_data_sound[] = {
    music_in_game, NULL
};

static int init_win_component_music(window_t *win, scene_t *scene,
    const char *key_to_get, const char *path_to_data)
{
    object_t *obj = NULL;

    if (scene == NULL || win == NULL) {
        return RET_ERR_INPUT;
    }
    obj = create_object(NULL, NULL, scene, layer);
    if (object_set_audio(obj, path_to_data, false, false) != BGS_OK) {
        return RET_ERR_MALLOC;
    }
    add_new_audio(obj, win);
    window_add_component(win, obj, key_to_get, NULL);
    return RET_OK;
}

int init_music_game(window_t *win, scene_t *scene)
{
    for (int i = 0; keys_to_get[i] != NULL ||
        paths_to_data_sound[i] != NULL; i++) {
        init_win_component_music(win, scene, keys_to_get[i],
            paths_to_data_sound[i]);
    }
    return RET_OK;
}
