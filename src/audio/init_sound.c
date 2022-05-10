/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** init_player_sound
*/

#include "my_rpg.h"
#include "my_bgs_components.h"
#include "audio.h"
#include "macro.h"

static const char sound_hited_path[] = "./assets/music/sound/roblox.ogg";
static const char sound_hit_path[] = "./assets/music/sound/hit-marker.ogg";
static const char sound_open_fridge[] = "./assets/music/sound/open_fridge.ogg";
static const char sound_close_fridge[] =
    "./assets/music/sound/close_fridge.ogg";
static const char sound_consum_86[] = "./assets/music/sound/cannette_use.ogg";
static const char sound_infinity_86[] =
    "./assets/music/sound/infinity_86_sound.ogg";
static const char sound_open_parchemin[] =
    "./assets/music/sound/paper.ogg";
static const char sound_level_up[] =
    "./assets/music/sound/level_up_sound.ogg";
static const char sound_ninho[] =
    "./assets/music/sound/ninho_sound.mp3";

const int layer = 0;

static const char *keys_to_get[] = {
    HURTED_SOUND,
    HURT_SOUNG,
    OPEN_INV_SOUND,
    CLOSE_INV_SOUND,
    CONSUM_CAN_SOUND,
    INFINITY_86_SOUND,
    PARCHEMIN_SOUND,
    LEVEL_UP_SOUND,
    NINHO,
    NULL
};

static const char *paths_to_data_sound[] = {
    sound_hited_path,
    sound_hit_path,
    sound_open_fridge,
    sound_close_fridge,
    sound_consum_86,
    sound_infinity_86,
    sound_open_parchemin,
    sound_level_up,
    sound_ninho,
    NULL
};

static int init_win_component_sound(window_t *win, scene_t *scene,
    const char *key_to_get, const char *path_to_data)
{
    object_t *obj = NULL;

    if (scene == NULL || win == NULL) {
        return RET_ERR_INPUT;
    }
    obj = create_object(NULL, NULL, scene, layer);
    if (object_set_sound(obj, path_to_data, false, false) != BGS_OK) {
        return RET_ERR_MALLOC;
    }
    add_new_audio(obj, win);
    window_add_component(win, obj, key_to_get, NULL);
    return RET_OK;
}

int init_sounds(scene_t *scene, window_t *win)
{
    for (int i = 0; keys_to_get[i] != NULL ||
        paths_to_data_sound[i] != NULL; i++) {
        init_win_component_sound(win, scene, keys_to_get[i], paths_to_data_sound[i]);
    }
    return RET_OK;
}
