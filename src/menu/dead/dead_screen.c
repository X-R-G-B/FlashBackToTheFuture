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

static bool can_wait_for_draw(scene_t *scene, float *time_elapsed)
{
    bool *can_play = NULL;

    if (scene == NULL || time_elapsed == NULL) {
        return false;
    }
    can_play = dico_t_get_value(scene->components, "can_play");
    if (can_play == NULL || *can_play == false) {
        return false;
    }
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

void update_dead_screen(object_t *object, scene_t *scene,
    window_t *window, float delta_time)
{
    static float time_elapsed = 0;
    sfColor opacity = sfRed;
    player_t *player = NULL;

    if (object == NULL || object->is_visible == false || window == NULL ||
            can_wait_for_draw(scene, &time_elapsed) == false) {
        return;
    }
    player = (player_t *) dico_t_get_value(window->components, "player");
    opacity = sfSprite_getColor(object->drawable.sprite);
    if (player == NULL || player->state == DIE || opacity.a == 255) {
        return;
    }
    time_elapsed += delta_time;
    while (time_elapsed >= 0.05) {
        change_opacity(&time_elapsed, &opacity, player, object);
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
    can_play = (bool *) dico_t_get_value(scene->components, "can_play");
    if (can_play == NULL || *can_play == true) {
        return;
    }
    time_elapsed += delta_time;
    while (time_elapsed >= 0.05) {
        time_elapsed -= 0.05;
        if (opacity.a + 5 >= 255) {
            opacity.a = 255;
            *can_play = true;
        } else {
            opacity.a += 5;
        }
        sfSprite_setColor(object->drawable.sprite, opacity);
    }
}
