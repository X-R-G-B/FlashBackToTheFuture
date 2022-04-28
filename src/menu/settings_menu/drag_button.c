/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** drag button off
*/

#include "audio.h"
#include "my_rpg.h"

static void save_new_data(window_t *win, float res, bool music)
{
    any_t *save = dico_t_get_any(win->components, SAVE);
    any_t *volume = get_from_any(save, "d", (music == true) ? MUSIC_VOLUME :
        SOUND_VOLUME);

    if (volume == NULL || volume->type != FLOAT) {
        return;
    }
    volume->value.f = res;
    write_json(save, SAVE_PATH);
}

static void browse_list(float res, list_ptr_t *list)
{
    list_t *elem = NULL;
    object_t *obj = NULL;

    elem = list->start;
    for (int i = 0; i < list->len; i++, elem = elem->next) {
        obj = elem->var;
        if (obj->type == AUDIO) {
            sfMusic_setVolume(obj->drawable.music, res);
        } else if (obj->type == SOUND) {
            sfSound_setVolume(obj->drawable.sound, res);
        } else {
            continue;
        }
    }
}

void set_new_volume(object_t *obj, bool music, window_t *win)
{
    float delim_start = (int) dico_t_get_value(obj->components, DELIM_START);
    float delim_end = (int) dico_t_get_value(obj->components, DELIM_END);
    float end_dif_to_start = delim_end - delim_start;
    float obj_dif_to_start = obj->bigdata.sprite_bigdata.pos.x - delim_start;
    float res = (obj_dif_to_start * 100) / end_dif_to_start;
    list_ptr_t *list = dico_t_get_value(win->components,
        (music == true) ? AUDIO_LIST : SOUND_LIST);

    if (delim_start <= 0 || delim_end <= 0 || delim_end < delim_start ||
        list == NULL) {
        return;
    }
    browse_list(res, list);
    save_new_data(win, res, music);
}

void drag_button_on(object_t *obj, __attribute__((unused)) scene_t *scene,
    window_t *win, __attribute__((unused)) set_event_t *evt)
{
    int delim_start = -1;
    int delim_end = -1;
    sfVector2i mouse_pos_i = {0};
    sfVector2f mouse_pos = {0};

    if (obj == NULL || win == NULL) {
        return;
    }
    delim_start = (int) dico_t_get_value(obj->components, DELIM_START);
    delim_end = (int) dico_t_get_value(obj->components, DELIM_END);
    if (delim_start <= 0 || delim_end <= 0 || delim_end < delim_start) {
        return;
    }
    sfSprite_setScale(obj->drawable.sprite, (sfVector2f) {1.0, 1.0});
    mouse_pos_i = sfMouse_getPositionRenderWindow(win->win);
    mouse_pos = (sfVector2f) {mouse_pos_i.x, mouse_pos_i.y};
    if (mouse_pos.x < delim_start || mouse_pos.x > delim_end) {
        return;
    }
    obj->bigdata.sprite_bigdata.pos.x = mouse_pos.x;
}

void sound_drag_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    if (obj == NULL || scene == NULL || win == NULL || evt == NULL) {
        return;
    }
    set_new_volume(obj, false, win);
    sfSprite_setScale(obj->drawable.sprite, (sfVector2f) {1.0, 1.0});
}

void music_drag_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    if (obj == NULL || scene == NULL || win == NULL || evt == NULL) {
        return;
    }
    set_new_volume(obj, true, win);
    sfSprite_setScale(obj->drawable.sprite, (sfVector2f) {1.0, 1.0});
}
