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

int handle_changings_movments(player_t *player, int dir)
{
    player_dir_t player_dir[] = {PLAYER_RIGHT, PLAYER_DOWN,
        PLAYER_LEFT, PLAYER_UP};
    player_dir_t prev_dir = player->player_dir;

    player->player_dir = player_dir[dir];
    if (player->player_dir == PLAYER_RIGHT && prev_dir != PLAYER_RIGHT) {
        sfSprite_setScale(player->obj->drawable.sprite,
            (sfVector2f) {-1, 0});
    }
    return RET_OK;
}

void event_movements(object_t *object, scene_t *scene, window_t *win,
    set_event_t *set_event)
{
    player_t *player = NULL;
    sfKeyCode key[] = {sfKeyRight, sfKeyDown, sfKeyLeft, sfKeyUp, 0};

    if (object == NULL || scene == NULL || win == NULL || set_event == NULL)
        return;
    player = dico_t_get_value(win->components, "player");
    for (int dir = 0; key[dir] != 0; dir++) {
        printf("%p\n", set_event);
        printf("%p\n", set_event->list_event);
        printf("%d\n", set_event->list_event->len);
        printf("%p\n", set_event->list_event->end);
        printf("%p\n", set_event->list_event->end->var);
        printf("%p\n", ((event_node_t *) set_event->list_event->end->var)->event_code);
        printf("%p\n", ((event_node_t *) set_event->list_event->end->var)->event_code.key);
        if (((event_node_t *) set_event->list_event->end->var)->event_code.key ==
            key[dir]) {
            handle_changings_movments(player, dir);
        }
    }
}

int main(int ac, char **av)
{
    window_t* win = create_window((sfVideoMode) {1920, 1080, 32},
        "Test player", sfClose | sfFullscreen);
    scene_t* scene = create_scene(win, sfNigger, "player_movements");
    object_t *player_object = create_object(update_movements, null, scene, 0);
    any_t *movements_rect = parse_json_file(
        "./assets/data/player/movements/player_movements.json");
    player_t player = {
        .state = STOP,
        .obj = player_object,
        .player_dir = PLAYER_RIGHT
    };

    object_set_sprite(player_object,
        "./assets/link.png", (sfIntRect) {19, 340, 52, 76},
        (sfVector2f) {200, 200});
    object_add_components(player_object, movements_rect, "movements_rect",
        destroy_any);
    set_event_t *event = create_event(event_movements, false,
                                        player_object, NULL);
    event_add_node(create_event(event_movements, false,
        player_object, NULL), (node_params_t) {sfMouseLeft, sfKeyUp, KEY});
    event_add_node(create_event(event_movements, false,
        player_object, NULL), (node_params_t) {sfMouseLeft, sfKeyRight, KEY});
    event_add_node(create_event(event_movements, false,
        player_object, NULL), (node_params_t) {sfMouseLeft, sfKeyDown, KEY});
    event_add_node(create_event(event_movements, false,
        player_object, NULL), (node_params_t) {sfMouseLeft, sfKeyLeft, KEY});
    window_add_component(win, &player, "player", NULL);
    window_change_scene(win, "player_movements");
    loop(win);
    remove_window(win);
    return 0;
}
