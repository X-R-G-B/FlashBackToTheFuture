/*
** EPITECH PROJECT, 2022
** button generator
** File description:
** tests
*/

#include "my_bgs_button_generator.h"
#include "my_bgs.h"
#include "my_bgs_components.h"
#include "my_rpg.h"

const char *str_on_hover[] = {NULL};

void (*on_hover[])(object_t *, scene_t *, window_t *win, set_event_t *) = {
    NULL
};

const char *str_off_hover[] = {NULL};

void (*off_hover[])(object_t *, scene_t *, window_t *win, set_event_t *) = {
    NULL
};

const char *str_on_click[] = {NULL};

void (*on_click[])(object_t *, scene_t *, window_t *win, set_event_t *) = {
    NULL
};

const char *str_off_click[] = {NULL};

void (*off_click[])(object_t *, scene_t *, window_t *win, set_event_t *) = {
    NULL
};

int main(int ac, char **av)
{
    window_t* win = create_window((sfVideoMode) {1920, 1080, 32},
        "Test player", sfClose | sfFullscreen);
    scene_t* scene = create_scene(win, sfBlack, "player_movements");
    object_t *player_object = create_object(update_movements, NULL, scene, 0);
    any_t *movements_rect = parse_json_file(
        "./assets/data/player/movements/player_movement.json");
    any_t *stop = parse_json_file("./assets/data/player/stop.json");
    player_t player = {
        .state = STOP,
        .obj = player_object,
        .dir = UP
    };

    object_set_sprite(player_object,
        "./assets/link.png", (sfIntRect) {19, 340, 52, 76},
        (sfVector2f) {200, 200});
    event_add_node(create_event(event_movements, false,
        player_object, stop_player_after_movements), (node_params_t) {sfMouseLeft, sfKeyUp, KEY});
    event_add_node(create_event(event_movements, false,
        player_object, stop_player_after_movements), (node_params_t) {sfMouseLeft, sfKeyRight, KEY});
    event_add_node(create_event(event_movements, false,
        player_object, stop_player_after_movements), (node_params_t) {sfMouseLeft, sfKeyDown, KEY});
    event_add_node(create_event(event_movements, false,
        player_object, stop_player_after_movements), (node_params_t) {sfMouseLeft, sfKeyLeft, KEY});
    object_add_components(player_object, movements_rect, "movements_rect",
        destroy_any);
    object_add_components(player_object, stop, "stop", destroy_any);
    window_add_component(win, &player, "player", NULL);
    window_change_scene(win, "player_movements");
    loop(win);
    remove_window(win);
    return 0;
}
