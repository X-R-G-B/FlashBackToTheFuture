/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** create player
*/

#include <stdlib.h>
#include "my_bgs_components.h"
#include "my_rpg.h"
#include "my_json.h"

static player_t *add_components(player_t *player, const char *stats)
{
    any_t *data = parse_json_file("./assets/data/player/data.json");
    any_t *stat = parse_json_file(stats);

    if (data == NULL || stat == NULL) {
        return NULL;
    }
    player->obj->components = dico_t_add_data(player->obj->components, "data",
        data, destroy_any);
    player->obj->components = dico_t_add_data(player->obj->components, "stats",
        stat, destroy_any);
    if (player->obj->components == NULL) {
        return NULL;
    }
    return player;
}

static int add_event(player_t *player)
{
    int ret = RET_OK;

    ret = object_set_sprite(player->obj, "./assets/link_with_weapon.png",
        (sfIntRect) {12, 210, 57, 69}, (sfVector2f) {500, 500});
    if (ret != RET_OK) {
        return ret;
    }
    ret = event_add_node(create_event(NULL, false, player->obj, attack),
        (node_params_t) {sfMouseLeft, sfKeyL, KEY});
    return ret;
}

player_t *create_player(window_t *win, scene_t *scene, const char *stats)
{
    player_t *player = malloc(sizeof(player_t));

    if (player == NULL) {
        return NULL;
    }
    win->components = dico_t_add_data(win->components, "player", player, free);
    if (win->components == NULL) {
        return NULL;
    }
    player->dir = DOWN;
    player->state = STOP;
    player->obj = create_object(update_player, NULL, scene, 0);
    if (player->obj == NULL) {
        return NULL;
    }
    set_stop(player);
    return (add_event(player) == RET_OK) ? add_components(player, stats) : NULL;
}
