/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** dead_screen
*/

#include "my_bgs.h"
#include "my_rpg.h"
#include "player.h"

extern const char can_play_dead_screen[];

void update_dead(__attribute__((unused)) player_t *player,
    __attribute__((unused)) scene_t *screen,
    window_t *win, __attribute__((unused)) float delta_time)
{
    object_t *dead_message = dico_t_get_value(win->components, DEAD_MESSAGE);
    object_t *dead_screen = dico_t_get_value(win->components, DEAD_SCREEN);

    if (dead_message == NULL || dead_message->is_visible == true ||
        dead_screen == NULL || dead_screen->is_visible == true) {
        return;
    }
    dead_message->is_visible = true;
    dead_screen->is_visible = true;
}

static bool can_wait_for_draw(window_t *window, float *time_elapsed)
{
    bool *can_play = NULL;

    if (window == NULL || time_elapsed == NULL) {
        return false;
    }
    can_play = dico_t_get_value(window->components, can_play_dead_screen);
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

void update_dead_screen(object_t *object,
    __attribute__((unused)) scene_t *scene,
    window_t *window, float delta_time)
{
    static float time_elapsed = 0;
    sfColor opacity = sfRed;
    player_t *player = NULL;

    if (object == NULL || object->is_visible == false || window == NULL ||
            can_wait_for_draw(window, &time_elapsed) == false) {
        return;
    }
    player = (player_t *) dico_t_get_value(window->components, PLAYER);
    opacity = sfSprite_getColor(object->drawable.sprite);
    if (player == NULL || player->state == DIE || opacity.a == 255) {
        return;
    }
    time_elapsed += delta_time;
    while (time_elapsed >= 0.05) {
        change_opacity(&time_elapsed, &opacity, player, object);
    }
}
