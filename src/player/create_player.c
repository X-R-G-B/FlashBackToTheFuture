/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** create player
*/

#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/View.h>
#include <stdlib.h>
#include "my_bgs.h"
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

static int *get_player_spawn(scene_t *scene)
{
    any_t *data = dico_t_get_value(scene->components, SAVE);
    int *spawn = NULL;

    if (data == NULL) {
        return NULL;
    }
    spawn = get_any_int_array(dico_t_get_any(data->value.dict, "spawn"));
    if (spawn == NULL) {
        return NULL;
    }
    spawn[0] = (spawn[0] * SQUARE_SIZE) + (SQUARE_SIZE / 2);
    spawn[1] = (spawn[1] * SQUARE_SIZE) + (SQUARE_SIZE / 2);
    return spawn;
}

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

static int add_event(player_t *player, int *spawn)
{
    int ret = RET_OK;
    object_t *obj = player->obj;

    if (object_set_sprite(player->obj, player_path, (sfIntRect)
        {12, 210, 57, 69}, (sfVector2f) {spawn[0], spawn[1]}) != BGS_OK) {
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

sfView *create_view(window_t *win, player_t *player, int *spawn)
{
    sfView *view = sfView_create();

    if (view == NULL) {
        return (NULL);
    }
    sfView_setCenter(view, (sfVector2f) {spawn[0], spawn[1]});
    sfView_setSize(view, (sfVector2f) {WIN_SIZE_X, WIN_SIZE_Y});
    sfRenderWindow_setView(win->win, view);
    player->view = view;
    return (view);
}

player_t *create_player(window_t *win, scene_t *scene, const char *stats)
{
    player_t *player = malloc(sizeof(player_t));
    int *spawn = NULL;

    if (player == NULL) {
        return NULL;
    }
    if (window_add_component(win, player, "player", destroy_player) != BGS_OK) {
        return NULL;
    }
    player->dir = DOWN;
    player->obj = create_object(update_player, NULL, scene, 0);
    if (player->obj == NULL) {
        return NULL;
    }
    spawn = get_player_spawn(scene);
    if (spawn == NULL || create_view(win, player, spawn) == NULL) {
        return (NULL);
    }
    return (add_event(player, spawn) == RET_OK) ?
        add_components(player, stats) : NULL;
}
