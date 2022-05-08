/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** sound header
*/

#ifndef AUDIO_H_
    #define AUDIO_H_

    #include "my_bgs.h"

extern const char AUDIO_LIST[];
extern const char SOUND_LIST[];
extern const char MUSIC_VOLUME[];
extern const char SOUND_VOLUME[];

extern const char DELIM_START[];
extern const char DELIM_END[];

extern const char BAR[];
extern const char BUTTON[];

int init_audio_list(window_t *win);

int toggle_music_in_scene(scene_t *scene);

int init_music(window_t *win, scene_t *scene);

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

void play_sound(window_t *win, const char *comp_key);

void play_music(window_t *win, const char *comp_key);

#endif /* !SOUND_H_ */
