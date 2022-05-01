/*
** EPITECH PROJECT, 2022
** my rpg
** File description:
** update player
*/

#include "main_menu.h"
#include "my_dico.h"
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
    update_roulade
};

static void update_stop(__attribute__((unused)) player_t *player,
    __attribute__((unused)) scene_t *scene,
    __attribute__((unused)) window_t *win, __attribute__((unused)) float time)
{

}

static void player_check_life(player_t *player, window_t *win)
{
    if (player->life > 0 || player->state == DIE) {
        return;
    }
    player->state = DYING;
    set_is_visible_false(dico_t_get_value(win->components, PAUSE_MENU));
    set_is_visible_false(dico_t_get_value(win->components, SETTINGS_MENU));
}

void update_player(__attribute__((unused)) object_t *obj, scene_t *scene,
    window_t *win, float dtime)
{
    player_t *player = NULL;

    if (win == NULL) {
        return;
    }
    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL || player->obj == NULL) {
        return;
    }
    sfRenderWindow_setView(win->win, player->view);
    if (player->state >= 0 && player->state <= 4) {
        update_ptr[player->state](player, scene, win, dtime);
    }
    if (dico_t_get_value(player->obj->components, "hurt") != NULL) {
        update_hurt(player, scene, win, dtime);
    } else if (player->state != DYING && player->state != DIE) {
        player_check_hurt(player, scene);
    }
    player_check_life(player, win);
}
