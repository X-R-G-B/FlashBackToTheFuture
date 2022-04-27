/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** set drags objects
*/

#include "audio.h"
#include "my_rpg.h"
#include "main_menu.h"

static float get_pos(sfFloatRect rect, window_t *win, bool music)
{
    any_t *save = NULL;
    any_t *percentage = NULL;

    if (win == NULL) {
        return -1;
    }
    save = dico_t_get_any(win->components, SAVE);
    if (music == true) {
        percentage = get_from_any(save, "d", MUSIC_VOLUME);
    } else {
        percentage = get_from_any(save, "d", SOUND_VOLUME);
    }
    if (percentage == NULL || percentage->type != FLOAT) {
        return -1;
    }
    return rect.left + (rect.width * (percentage->value.f / 100));
}

static void set_delimitation(object_t *button, object_t *bar)
{
    sfFloatRect rect = {0};
    int delim_start = -1;
    int delim_end = -1;

    rect = sfSprite_getGlobalBounds(bar->drawable.sprite);
    delim_start = (int) rect.left;
    delim_end = (int) rect.left + rect.width;
    button->components = dico_t_add_data(button->components, DELIM_START,
        (void *) delim_start, NULL);
    button->components = dico_t_add_data(button->components, DELIM_END,
        (void *) delim_end, NULL);
    bar->components = dico_t_add_data(bar->components, BUTTON, button, NULL);
}

static void bar_set_update(object_t *music_bar, object_t *sound_bar,
    scene_t *scene)
{
    layer_t *layer = get_layer(scene, music_bar->layer);

    if (layer == NULL) {
        return;
    }
    music_bar->update = music_bar_update;
    sound_bar->update = sound_bar_update;
    list_add_to_end(layer->updates, music_bar);
    list_add_to_end(layer->updates, sound_bar);
}

void set_drag_objects(list_ptr_t *settings, window_t *win, scene_t *scene)
{
    object_t *music_button = NULL;
    object_t *music_bar = NULL;
    object_t *sound_button = NULL;
    object_t *sound_bar = NULL;

    if (settings == NULL) {
        return;
    }
    music_button = settings->end->back->var;
    sound_button = settings->end->var;
    music_bar = settings->end->back->back->back->var;
    sound_bar = settings->end->back->back->var;
    set_delimitation(music_button, music_bar);
    set_delimitation(sound_button, sound_bar);
    music_button->bigdata.sprite_bigdata.pos.x = get_pos(
        sfSprite_getGlobalBounds(music_bar->drawable.sprite), win, true);
    sound_button->bigdata.sprite_bigdata.pos.x = get_pos(
        sfSprite_getGlobalBounds(sound_bar->drawable.sprite), win, false);
    bar_set_update(music_bar, sound_bar, scene);
}
