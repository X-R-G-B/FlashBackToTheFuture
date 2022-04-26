/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** drag event
*/

#include "my_bgs.h"
#include "audio.h"
#include "main_menu.h"

static void bar_update(object_t *button, object_t *fill_bar)
{
    sfFloatRect fill_bar_rect = {0};
    float bar_end_pos_x = -1;
    float dif = -1;

    if (button == NULL || fill_bar == NULL) {
        return;
    }
    fill_bar_rect = sfSprite_getGlobalBounds(fill_bar->drawable.sprite);
    bar_end_pos_x = fill_bar_rect.left + fill_bar_rect.width;
    dif = button->bigdata.sprite_bigdata.pos.x - bar_end_pos_x;
    if (dif == 0) {
        return;
    }
    fill_bar->bigdata.sprite_bigdata.rect.width += (int) dif;
    fill_bar->bigdata.sprite_bigdata.pos.x += (int) dif / 2;
}

void music_bar_update(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    list_ptr_t *setting_list = NULL;

    if (obj == NULL || scene == NULL || win == NULL || evt == NULL) {
        return;
    }
    setting_list = dico_t_get_value(win->components, SETTINGS_MENU);
    if (setting_list == NULL) {
        return;
    }
    bar_update(setting_list->end->back->var, obj);
}

void sound_bar_update(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    list_ptr_t *setting_list = NULL;

    if (obj == NULL || scene == NULL || win == NULL || evt == NULL) {
        return;
    }
    setting_list = dico_t_get_value(win->components, SETTINGS_MENU);
    if (setting_list == NULL) {
        return;
    }
    bar_update(setting_list->end->var, obj);
}
