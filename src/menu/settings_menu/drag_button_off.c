/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** drag button off
*/

#include "my_rpg.h"
#include "audio.h"

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

static void set_new_volume(object_t *obj, bool music, window_t *win)
{
    float delim_start = (int) dico_t_get_value(obj->components, DELIM_START);
    float delim_end = (int) dico_t_get_value(obj->components, DELIM_END);
    float width = delim_end - delim_start;
    object_t *bar = dico_t_get_value(obj->components, BAR);
    sfFloatRect rect = (bar != NULL) ? sfSprite_getGlobalBounds(
        bar->drawable.sprite) : (sfFloatRect) {0, 0, 0, 0};
    float obj_dif_to_start = obj->bigdata.sprite_bigdata.pos.x - rect.left;
    float res = (obj_dif_to_start * 100) / width;
    list_ptr_t *list = dico_t_get_value(win->components,
        (music == true) ? AUDIO_LIST : SOUND_LIST);

    if (delim_start <= 0 || delim_end <= 0 || delim_end < delim_start ||
        list == NULL || bar == NULL) {
        return; 
    }
    res = (res <= 4.0) ? 0.0 : res;
    res = (res >= 96.0) ? 100.0 : res;
    browse_list(res, list);
    save_new_data(win, res, music);
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
