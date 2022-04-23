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
    update_dead,
};

static void update_stop(__attribute__((unused)) player_t *player,
    __attribute__((unused)) scene_t *scene,
    __attribute__((unused)) window_t *win, __attribute__((unused)) float time)
{

}

void update_player(__attribute__((unused)) object_t *obj, scene_t *scene,
    window_t *win, float dtime)
{
    player_t *player = dico_t_get_value(win->components, PLAYER);
    bool hurt = false;

    if (player == NULL || player->obj == NULL) {
        return;
    } else if (player->state >= 0 && player->state <= 3) {
        update_ptr[player->state](player, scene, win, dtime);
    }
    hurt = (bool) dico_t_get_value(player->obj->components, "hurt");
    if (hurt == true) {
        update_hurt(player, scene, win, dtime);
    } else if (player->state != DYING && player->state != DIE) {
        player_check_hurt(player, scene);
    }
    if (player->life <= 0 && player->state != DIE) {
        player->state = DYING;
    }
}
