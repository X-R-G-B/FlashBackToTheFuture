/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** update attack
*/

#include "my_rpg.h"
#include "my_json.h"

static void increment_rect(int *rect, int *rect_index, int len,
    player_t *player)
{
    player->obj->bigdata.sprite_bigdata.rect = (sfIntRect) {rect[0], rect[1],
        rect[2], rect[3]};
    if (*rect_index >= len - 1) {
        *rect_index = 0;
        player->state = STOP;
    } else {
        *rect_index = *rect_index + 1;
    }
}

void update_attack(player_t *player, __attribute__((unused)) scene_t *scene,
    __attribute__((unused)) window_t *win, __attribute__((unused)) float dtime)
{
    static int rect_index = 0;
    any_t *attack = dico_t_get_any(player->obj->components, "attack");
    any_t *rect_arr = NULL;
    int *rect = NULL;

    if (attack == NULL) {
        return;
    }
    rect_arr = get_from_any(attack, "ddi", "sword rect",
        "down");
    if (rect_arr == NULL) {
        return;
    }
    rect = get_any_int_array(
            get_element_i_var(rect_arr->value.array, rect_index));
    if (rect == NULL) {
        return;
    }
    increment_rect(rect, &rect_index, rect_arr->value.array->len, player);
}
