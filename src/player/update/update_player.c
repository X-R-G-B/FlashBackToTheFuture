/*
** EPITECH PROJECT, 2022
** my rpg
** File description:
** update player
*/

#include "my_rpg.h"
#include "ennemies.h"
#include "my_json.h"

static void update_stop(__attribute__((unused)) player_t *player,
    __attribute__((unused)) scene_t *scene,
    __attribute__((unused)) window_t *win, __attribute__((unused)) float time);

static void (*update_ptr[])(player_t *, scene_t *, window_t *, float) = {
    update_attack,
    update_movements,
    update_stop,
    update_hurt,
    update_dead
};

static void update_stop(__attribute__((unused)) player_t *player,
    __attribute__((unused)) scene_t *scene,
    __attribute__((unused)) window_t *win, __attribute__((unused)) float time)
{

}

void update_player(__attribute__((unused)) object_t *obj, scene_t *scene,
    window_t *win, float dtime)
{
    player_t *player = dico_t_get_value(win->components, "player");

    if (player == NULL) {
        return;
    } else if (player->state >= 0 && player->state <= 4) {
        update_ptr[player->state](player, scene, win, dtime);
    }
    printf("state%d\n", player->state);
    if (player->state != HURT) {
        player_check_hurt(player, scene);
    }
}
