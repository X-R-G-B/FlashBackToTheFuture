/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** update_dead_message
*/

#include "my_bgs.h"
#include "my_rpg.h"

extern const char can_play_dead_screen[];

static void change_opacity(float *time_elapsed, bool *can_play,
    sfColor *opacity, object_t *object)
{
    while (*time_elapsed >= 0.05) {
        *time_elapsed -= 0.05;
        if (opacity->a + 5 >= 255) {
            opacity->a = 255;
            *can_play = true;
        } else {
            opacity->a += 5;
        }
        sfSprite_setColor(object->drawable.sprite, *opacity);
    }
}

void update_dead_message(object_t *object, scene_t *scene,
    __attribute__((unused)) window_t *win, float delta_time)
{
    static float time_elapsed = 0;
    bool *can_play = NULL;
    sfColor opacity = sfSprite_getColor(object->drawable.sprite);

    if (object == NULL || scene == NULL ||
            object->is_visible == false || opacity.a == 255) {
        return;
    }
    can_play = (bool *) dico_t_get_value(win->components,
        can_play_dead_screen);
    if (can_play == NULL || *can_play == true) {
        return;
    }
    time_elapsed += delta_time;
    change_opacity(&time_elapsed, can_play, &opacity, object);
}
