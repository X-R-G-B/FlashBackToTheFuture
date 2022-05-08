/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** replace objects in next stage
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "player.h"

static void replace_hud(window_t *win, player_t *player, int *spawn)
{
    list_ptr_t *hud_elements = dico_t_get_value(win->components, HUD_ELEMENTS);
    list_t *elem = NULL;
    sfVector2f player_pos = player->obj->bigdata.sprite_bigdata.pos;
    sfVector2f move = {spawn[0] - player_pos.x, spawn[1] - player_pos.y};
    object_t *obj = NULL;

    if (hud_elements == NULL) {
        return;
    }
    elem = hud_elements->start;
    for (int i = 0; i < hud_elements->len; i++, elem = elem->next) {
        obj = elem->var;
        obj->bigdata.sprite_bigdata.pos.x += move.x;
        obj->bigdata.sprite_bigdata.pos.y += move.y;
    }
}

static void replace_player(window_t *win, player_t *player, int *spawn)
{
    player->obj->bigdata.sprite_bigdata.pos = (sfVector2f) {spawn[0], spawn[1]};
    sfView_setCenter(player->view, (sfVector2f) {spawn[0], spawn[1]});
    sfRenderWindow_setView(win->win, player->view);
}

void replace_objects(window_t *win, scene_t *scene)
{
    player_t *player = NULL;
    int *spawn = NULL;

    if (win == NULL || scene == NULL) {
        return;
    }
    spawn = get_player_spawn(scene);
    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL || player->obj == NULL || player->view == NULL ||
        spawn == NULL) {
        return;
    }
    replace_hud(win, player, spawn);
    replace_player(win, player, spawn);
    free(spawn);
}
