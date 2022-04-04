/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** player_movements
*/

#include "my_bgs.h"
#include "my_json.h"
#include "my_rpg.h"

int move_up(object_t *obj, player_t *player, float delta_time,
    any_t *movements_rect);
int move_left(object_t *obj, player_t *player, float delta_time,
    any_t *movements_rect);
int move_down(object_t *obj, player_t *player, float delta_time,
    any_t *movements_rect);
int move_right(object_t *obj, player_t *player, float delta_time,
    any_t *movements_rect);

int move_player(object_t *obj, player_t *player, float delta_time,
    any_t *movements_rect)
{
    char *rects_keys[] = {"right", "down", "left", "up", NULL};
    static int state = 0;
    any_t *rects = NULL;

    rects = get_from_any(movements_rect, "da",
    rects_keys[player->player_dir], state);
    state += 1;
    printf("code = %d\n", player->player_dir);
    if (dico_t_get_any(movements_rect->value.dict,
        rects_keys[player->player_dir])->value.array->len <= state)
        state = 0;
    return 0;
}

void handle_move_player(object_t *obj, scene_t *scene,
    window_t *win, float delta_time)
{
    any_t *movements_rect = NULL;
    player_t *player = dico_t_get_value(win->components, "player");

    movements_rect = dico_t_get_any(obj->components,
        "movements_rect");
    if (player == NULL || movements_rect == NULL || player->state != MOVING)
        return;
    move_player(obj, player, delta_time, movements_rect);
}

void update_movements(object_t *object, scene_t *scene, window_t *win,
    float delta_time)
{
    if (object == NULL || scene == NULL || win == NULL)
        return;
    handle_move_player(object, scene, win, delta_time);
}
