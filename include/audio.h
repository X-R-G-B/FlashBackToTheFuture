/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** sound header
*/

#ifndef AUDIO_H_
    #define AUDIO_H_

    #include "my_bgs.h"

static const char AUDIO_LIST[] = "audio list";
static const char SOUND_LIST[] = "sound list";
static const char MUSIC_VOLUME[] = "music volume";
static const char SOUND_VOLUME[] = "sound volume";

static const char DELIM_START[] = "delim_start";
static const char DELIM_END[] = "delim_end";
static const char BAR[] = "bar";
static const char BUTTON[] = "button";

int init_audio_list(window_t *win);

void sound_drag_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt);

void music_drag_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt);

void sound_bar_update(object_t *obj, scene_t *scene, window_t *win,
    float dtime);

int add_new_audio(object_t *object, window_t *win);

void set_drag_objects(list_ptr_t *settings, window_t *win, scene_t *scene);

void music_bar_update(object_t *obj, scene_t *scene, window_t *win,
    float dtime);

void drag_button_off_hover(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt);

void drag_button_on_hover(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt);

void drag_button_on(object_t *obj, __attribute__((unused)) scene_t *scene,
    window_t *win, __attribute__((unused)) set_event_t *evt);

#endif /* !SOUND_H_ */
