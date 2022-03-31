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

#define sfNigger sfBlack
#define null NULL

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

void update_movements(object_t *object, scene_t *scene, window_t *win,
    float delta_time);

char **my_str_to_word_array(char *str);

int main(int ac, char **av)
{
    window_t* win = create_window((sfVideoMode) {1920, 1080, 32},
        "Test player", sfClose | sfFullscreen);
    scene_t* scene = create_scene(win, sfNigger, "player_movements");
    object_t *player_object = create_object(update_movements, null, scene, 0);
    object_set_sprite(player_object,
        "./assets/link.png", (sfIntRect) {7, 114, 16, 24},
        (sfVector2f) {200, 200});
    any_t *movements_rect = parse_json_file(
        "./assets/data/player/movements/player_movements.json");
    player_t player = {
        .state = STOP,
        .obj = player_object,
        .player_dir = PLAYER_RIGHT
    };
    object_add_components(player_object, movements_rect, "movements_rect",
        destroy_any);
    window_change_scene(win, "player_movements");
    loop(win);
    remove_window(win);
    return 0;
}
