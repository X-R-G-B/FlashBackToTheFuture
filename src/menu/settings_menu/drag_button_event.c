/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** drag button event
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "audio.h"
#include "main_menu.h"

void drag_button_on_hover(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    if (obj == NULL || scene == NULL || win == NULL || evt == NULL) {
        return;
    }
    sfSprite_setScale(obj->drawable.sprite, (sfVector2f) {1.3, 1.3});
}

void drag_button_off_hover(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    if (obj == NULL || scene == NULL || win == NULL || evt == NULL) {
        return;
    }
    sfSprite_setScale(obj->drawable.sprite, (sfVector2f) {1.0, 1.0});
}

void drag_button_on(float delimitation[2], object_t *obj, window_t *win)
{
    sfVector2i mouse_pos_i = {0};
    sfVector2f mouse_pos = {0};

    if (obj == NULL || win == NULL || delimitation[0] < 0 ||
        delimitation[1] < 0) {
        return;
    }
    sfSprite_setScale(obj->drawable.sprite, (sfVector2f) {0.7, 0.7});
    mouse_pos_i = sfMouse_getPosition(win->win);
    mouse_pos = (sfVector2f) {mouse_pos_i.x, mouse_pos_i.y};
    if (mouse_pos.x < delimitation[0] || mouse_pos.x > delimitation[1]) {
        return;
    }
    obj->bigdata.sprite_bigdata.pos = mouse_pos;
}

float get_pos(float delimitation[2], window_t *win, bool music)
{
    any_t *save = NULL;
    any_t *percentage = NULL;
    float width = delimitation[1] - delimitation[0];
    float multiple = 0;

    if (win == NULL) {
        return;
    }
    save = dico_t_get_any(win->components, SAVE);
    if (music == true) {
        percentage = get_from_any(save, "d", MUSIC_VOLUME);
    } else {
        percentage = get_from_any(save, "d", SOUND_VOLUME);
    }
    if (percentage == NULL) {
        return -1;
    }
    multiple = percentage->value.f / 100;
    printf("multiple%f\n", multiple);
    return width * multiple;
}

void set_delimitation(bool *fst_time, float *delimitation[2],
    window_t *win, bool music)
{
    list_ptr_t *list = dico_t_get_value(win->components, SETTINGS_MENU);
    object_t *obj = NULL;
    sfFloatRect rect = {0};

    if (list == NULL) {
        return;
    }
    if (music == true) {
        obj = list->end->back->back->back->var;
    } else {
        obj = list->end->back->back->var;
    }
    rect = sfSprite_getGlobalBounds(obj->drawable.sprite);
    *delimitation[0] = rect.left;
    *delimitation[1] = rect.left + rect.width;
    *fst_time = true;
}

void music_drag_button_on_click(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    static bool fst_time = false;
    static float delimitation[2] = {-1, -1};

    if (fst_time == false) {
        set_delimitation(&fst_time, &delimitation, win, true);
        obj->bigdata.sprite_bigdata.pos.x = get_pos(delimitation, win, true);
    }
    drag_button_on(delimitation, obj, win);
}

void sound_drag_button_on_click(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    static bool fst_time = false;
    static float delimitation[2] = {-1, -1};

    if (fst_time == false) {
        set_delimitation(&fst_time, &delimitation, win, false);
        obj->bigdata.sprite_bigdata.pos.x = get_pos(delimitation, win, false);
    }
    drag_button_on(delimitation, obj, win);
}

void sound_drag_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    if (obj == NULL || scene == NULL || win == NULL || evt == NULL) {
        return;
    }
    sfSprite_setScale(obj->drawable.sprite, (sfVector2f) {1.0, 1.0});
}

void music_drag_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    if (obj == NULL || scene == NULL || win == NULL || evt == NULL) {
        return;
    }
    sfSprite_setScale(obj->drawable.sprite, (sfVector2f) {1.0, 1.0});
}
