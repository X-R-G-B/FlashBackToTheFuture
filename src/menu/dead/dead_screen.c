/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** dead_screen
*/

#include "my_bgs.h"
#include "my_rpg.h"

void update_dead(__attribute__((unused)) player_t *player,
    __attribute__((unused)) scene_t *screen,
    window_t *win, __attribute__((unused)) float delta_time)
{
    object_t *dead_message = dico_t_get_value(win->components, "dead_message");
    object_t *dead_screen = dico_t_get_value(win->components, "dead_screen");
    if (dead_message == NULL || dead_message->is_visible == true) {
        return;
    }
    dead_message->is_visible = true;
    dead_screen->is_visible = true;
}

static bool can_wait_for_draw(object_t *object, float *time_elapsed,
    float delta_time, bool *can_draw)
{
    if (object == NULL || object->is_visible == false ||
            time_elapsed == NULL || can_draw == NULL) {
        return false;
    }
    *time_elapsed += delta_time;
    if (*can_draw == false && *time_elapsed < 2.55) {
        return false;
    } else if (*can_draw == false && *time_elapsed >= 2.55) {
        *time_elapsed -= 2.55;
    }
    *can_draw = true;
    return true;
}

static void change_opacity(float *time_elapsed, sfColor *opacity,
    player_t *player, object_t *object)
{
    *time_elapsed -= 0.05;
    if (opacity->a + 5 >= 255) {
        opacity->a = 255;
        player->state = DIE;
    } else {
        opacity->a += 5;
    }
    sfSprite_setColor(object->drawable.sprite, *opacity);
}

void update_dead_screen(object_t *object,
    __attribute__((unused)) scene_t *scene, window_t *window, float delta_time)
{
    static float time_elapsed = 0;
    sfColor opacity = sfBlue;
    player_t *player = NULL;
    static bool can_draw = false;

    if (can_wait_for_draw(object, &time_elapsed, delta_time,
            &can_draw) != true) {
        return;
    }
    opacity = sfSprite_getColor(object->drawable.sprite);
    player = (player_t *) dico_t_get_value(window->components, "player");
    if (player == NULL || opacity.a == 255) {
        return;
    }
    while (time_elapsed >= 0.05) {
        change_opacity(&time_elapsed, &opacity, player, object);
    }
}

void update_dead_message(object_t *object,
    __attribute__((unused)) scene_t *scene,
    __attribute__((unused)) window_t *win, float delta_time)
{
    static float time_elapsed = 0;
    sfColor opacity = sfSprite_getColor(object->drawable.sprite);

    if (object->is_visible == false)
        return;
    time_elapsed += delta_time;
    while (time_elapsed >= 0.05) {
        time_elapsed -= 0.05;
        if (opacity.a + 5 >= 255)
            opacity.a = 255;
        else
            opacity.a += 5;
        sfSprite_setColor(object->drawable.sprite, opacity);
    }
}
