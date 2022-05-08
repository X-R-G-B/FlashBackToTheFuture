/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** init_player_sound
*/

#include "my_rpg.h"
#include "my_bgs_components.h"
#include "audio.h"

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
const char MUSIC_GAME[] = "musicgame";
static const char music_in_game[] =
    "./assets/music/game_music.ogg";
static const int layer = 0;

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

    init_win_component_sound(win, scene, HURTED_SOUND, sound_hited_path);
    init_win_component_sound(win, scene, HURT_SOUNG, sound_hit_path);
    init_win_component_sound(win, scene, OPEN_INV_SOUND, sound_open_fridge);
    init_win_component_sound(win, scene, CLOSE_INV_SOUND, sound_close_fridge);
    init_win_component_sound(win, scene, CONSUM_CAN_SOUND, sound_consum_86);
    init_win_component_sound(win, scene, INFINITY_86_SOUND, sound_infinity_86);
    init_win_component_sound(win, scene, PARCHEMIN_SOUND, sound_open_parchemin);
    init_win_component_sound(win, scene, LEVEL_UP_SOUND, sound_level_up);
    init_win_component_music(win, scene, MUSIC_GAME, music_in_game);
    return RET_OK;
}
