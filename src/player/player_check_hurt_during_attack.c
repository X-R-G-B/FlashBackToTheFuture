/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** player check hurt during attack
*/

#include <stdlib.h>
#include "my_json.h"
#include "ennemies.h"

static int browse_rect_list(list_t *elem, list_ptr_t *rect_list,
    player_t *player)
{
    int *list_rect = NULL;
    sfIntRect rect = player->obj->bigdata.sprite_bigdata.rect;

    for (int i = 0; i < rect_list->len; i++, elem = elem->next) {
        list_rect = get_any_int_array(get_from_any(elem->var, "a", 0));
        if (list_rect == NULL) {
            return -1;
        } else if (list_rect[0] == rect.left && list_rect[1] == rect.top) {
            free(list_rect);
            return i;
        }
        free(list_rect);
    }
    return -1;
}

static int get_rect_id(any_t *data, player_t *player)
{
    any_t *rect_list = get_from_any(data, "ddda", "attack", "sword",
        "rect", player->dir);
    list_t *elem = NULL;

    if (rect_list == NULL || rect_list->type != ARRAY) {
        return -1;
    }
    elem = rect_list->value.array->start;
    return browse_rect_list(elem, rect_list->value.array, player);
}

static sfFloatRect calculate_righ_rect(sfFloatRect player_rect, any_t *hitbox)
{
    int *rect = NULL;

    rect = get_any_int_array(hitbox);
    if (rect == NULL) {
        return player_rect;
    }
    player_rect.left += ((float) rect[0]);
    player_rect.top += ((float) rect[1]);
    player_rect.width = ((float) rect[2]);
    player_rect.height = ((float) rect[3]);
    free(rect);
    return player_rect;
}

sfFloatRect get_attack_hitbox_rect(sfFloatRect player_rect, player_t *player)
{
    int rect_id = 0;
    any_t *data = dico_t_get_value(player->obj->components, "data");
    any_t *hitbox_rect = NULL;

    if (data == NULL) {
        return player_rect;
    }
    hitbox_rect = get_from_any(data, "ddda", "attack", "sword", "hurt hitbox",
        player->dir);
    rect_id = get_rect_id(data, player);
    if (rect_id < 0 || hitbox_rect == NULL || hitbox_rect->type != ARRAY) {
        return player_rect;
    }
    return calculate_righ_rect(player_rect,
        get_element_i_var(hitbox_rect->value.array, rect_id));
}
