/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** attack event
*/

#include "my_rpg.h"

void attack(__attribute__((unused)) object_t *obj, __attribute__((unused))
    scene_t *scene, window_t *win,
    __attribute__((unused)) set_event_t *set_event)
{
    player_t *player = dico_t_get_value(win->components, "player");

    if (player == NULL || player->state != STOP) {
        return;
    }
    player->state = ATTACKING;
}
