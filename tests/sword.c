/*
** EPITECH PROJECT, 2022
** t
** File description:
** t
*/

#include <stdlib.h>
#include "my_bgs_components.h"
#include "my_rpg.h"
#include "my_json.h"

void att(object_t *obj, scene_t *scene, window_t *win, set_event_t *evt)
{
    player_t *player = dico_t_get_value(win->components, "player");

    update_attack(player, scene, win, 0);
}

int main(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    window_t *win = create_window(mode, "t", sfResize | sfClose);
    scene_t *scene = create_scene(win, sfBlack, "TEST");
    player_t *player = malloc(sizeof(player_t));
    any_t *attack = parse_json_file("./assets/data/player/event/attack.json");
    any_t *stop = parse_json_file("./assets/data/player/stop.json");

    win->components = dico_t_add_data(win->components, "player", player, free);
    player->dir = LEFT;
    player->state = STOP;
    player->obj = create_object(update_player, NULL, scene, 0);
    player->obj->components = dico_t_add_data(player->obj->components, "stop",
        stop, destroy_any);
    player->obj->components = dico_t_add_data(player->obj->components, "attack",
        attack, destroy_any);
    object_set_sprite(player->obj, "./assets/link_with_weapon.png",
        (sfIntRect) {12, 210, 57, 69}, (sfVector2f) {500, 500});
    event_add_node(create_event(NULL, false, player->obj, attack_event),
        (node_params_t) {sfMouseLeft, sfKeyL, KEY});
    set_stop(player);
    window_change_scene(win, "TEST");
    loop(win);
    remove_window(win);
    return 0;
}
