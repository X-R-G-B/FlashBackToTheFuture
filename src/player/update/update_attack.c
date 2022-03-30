/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** update attack
*/

#include "my_rpg.h"
#include "my_json.h"

static void increment_index(int index[2], int len, player_t *player)
{
    if (index[1] > 13) {
        index[1] = 0;
        if (index[0] >= len - 1) {
            index[0] = 0;
            set_stop(player);
        } else {
            index[0] = index[0] + 1;
        }
    } else {
        index[1] = index[1] + 1;
    }
}

static void increment_rect(list_ptr_t *data, int index[2], int len,
    player_t *player)
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
    increment_index(index, len, player);
}

void update_attack(player_t *player, __attribute__((unused)) scene_t *scene,
    __attribute__((unused)) window_t *win, __attribute__((unused)) float dtime)
{
    static int index[2] = {0, 0};
    any_t *attack = dico_t_get_any(player->obj->components, "attack");
    any_t *data = NULL;
    any_t *current_data = NULL;

    if (attack == NULL) {
        return;
    }
    data = get_from_any(attack, "da", "sword", player->dir);
    if (data == NULL) {
        return;
    }
    current_data = get_element_i_var(data->value.array, index[0]);
    if (current_data == NULL || current_data->type != ARRAY) {
        return;
    }
    increment_rect(current_data->value.array, index,
        data->value.array->len, player);
}
