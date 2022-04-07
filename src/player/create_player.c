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

static void (*event_on[])(object_t *, scene_t *, window_t *,
    set_event_t *) = {
    attack_event, move_on
};

static void (*event_off[])(object_t *, scene_t *, window_t *,
    set_event_t *) = {
    NULL, move_off
};

static const node_params_t node[] = {
    {sfMouseLeft, sfKeyL, KEY}, {sfMouseLeft, sfKeyZ, KEY},
    {sfMouseLeft, sfKeyQ, KEY}, {sfMouseLeft, sfKeyS, KEY},
    {sfMouseLeft, sfKeyD, KEY}
};

static const int event_nb = 5;

static const char player_path[] = "./assets/image/player/link_with_weapon.png";

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
    set_stop(player);
    return player;
}

static int add_event(player_t *player)
{
    int ret = RET_OK;
    object_t *obj = player->obj;

    if (object_set_sprite(player->obj, player_path,
        (sfIntRect) {12, 210, 57, 69}, (sfVector2f) {500, 500}) != BGS_OK) {
        return RET_ERR_INPUT;
    }
    for (int i = 0; i < event_nb && ret == RET_OK; i++) {
        if (i == 0) {
            ret = event_add_node(create_event(event_on[0], false, obj,
                event_off[0]), node[i]);
        } else {
            ret = event_add_node(create_event(event_on[1], false, obj,
                event_off[1]), node[i]);
        }
    }
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
    return (add_event(player) == RET_OK) ? add_components(player, stats) : NULL;
}
