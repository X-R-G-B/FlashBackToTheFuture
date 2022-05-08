/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** update attack
*/

#include <stdlib.h>
#include "my_json.h"
#include "player.h"

static void increment_index(int *index, player_t *player, float *time)
{
    any_t *data = dico_t_get_any(player->obj->components, PLAYER_DATA);
    any_t *weapon = get_from_any(data, "ddd", "attack", "sword", "rect");
    any_t *time_actualisation = NULL;

    if (weapon == NULL || weapon->type != ARRAY) {
        return;
    }
    time_actualisation = get_element_i_var(weapon->value.array, 4);
    while (time_actualisation != NULL && *time >= time_actualisation->value.f) {
        *time -= time_actualisation->value.f;
        if (index[0] >= index[1] - 1) {
            index[0] = 0;
            set_stop(player);
        } else {
            index[0] = index[0] + 1;
        }
    }
}

static void increment_rect(list_ptr_t *data, int index[2], player_t *player,
    float *time)
{
    int *rect = get_any_int_array(data->start->var);
    int *origin = get_any_int_array(data->end->var);

    if (rect == NULL || origin == NULL) {
        return;
    }
    player->obj->bigdata.sprite_bigdata.rect = (sfIntRect) {rect[0], rect[1],
        rect[2], rect[3]};
    sfSprite_setOrigin(player->obj->drawable.sprite,
        (sfVector2f) {origin[0], origin[1]});
    increment_index(index, player, time);
    free(rect);
    free(origin);
}

void update_attack(player_t *player, __attribute__((unused)) scene_t *scene,
    __attribute__((unused)) window_t *win, __attribute__((unused)) float dtime)
{
    static int index[2] = {0, 0};
    static float time = 0;
    any_t *attack = NULL;
    any_t *data = NULL;
    any_t *current_data = NULL;

    if (player == NULL || player->obj == NULL) {
        return;
    }
    time += dtime;
    attack = dico_t_get_any(player->obj->components, PLAYER_DATA);
    data = get_from_any(attack, "ddda", "attack", "sword", "rect", player->dir);
    current_data = get_from_any(data, "a", index[0]);
    if (current_data == NULL || current_data->type != ARRAY) {
        return;
    }
    index[1] = data->value.array->len;
    increment_rect(current_data->value.array, index, player, &time);
}
