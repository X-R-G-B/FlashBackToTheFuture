/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** set drags objects
*/

#include "audio.h"
#include "my_rpg.h"
#include "main_menu.h"

static float get_pos(float width, window_t *win, bool music)
{
    any_t *save = NULL;
    any_t *percentage = NULL;

    if (win == NULL) {
        return -1;
    }
    save = dico_t_get_any(win->components, SAVE);
    if (music == true) {
        percentage = get_from_any(save, "d", MUSIC_VOLUME);
        printf("%p %p\n", percentage, save);
    } else {
        percentage = get_from_any(save, "d", SOUND_VOLUME);
        printf("%p %p\n", percentage, save);
    }
    if (percentage == NULL) {
        return -1;
    }
    return ((width * 100) * percentage->value.f) / 100;
}

static void set_delimitation(object_t *button, object_t *bar)
{
    sfFloatRect rect = {0};
    float delimitation[2] = {-1, -1};

    rect = sfSprite_getGlobalBounds(bar->drawable.sprite);
    delimitation[0] = rect.left;
    delimitation[1] = rect.left + rect.width;
    button->components = dico_t_add_data(button->components, DELIMITATION,
        (void *) delimitation, NULL);
    bar->components = dico_t_add_data(bar->components, BUTTON, button, NULL);
}

void set_drag_objects(list_ptr_t *settings, window_t *win)
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
    music_button->bigdata.sprite_bigdata.pos.x =
        get_pos(sound_bar->bigdata.sprite_bigdata.rect.width, win, true);
    sound_button->bigdata.sprite_bigdata.pos.x =
        get_pos(music_bar->bigdata.sprite_bigdata.rect.width, win, false);
    printf("%f %f\n", music_button->bigdata.sprite_bigdata.pos.x, sound_button->bigdata.sprite_bigdata.pos.x);
}
