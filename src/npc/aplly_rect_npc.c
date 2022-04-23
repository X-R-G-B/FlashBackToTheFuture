/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** apply json rect with current rect
*/

#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Vector2.h>
#include "my_bgs.h"
#include "my_json.h"
#include "my_puts.h"
#include "my_rpg.h"

static int aplly_intrect_npc(any_t *true_rect, object_t *npc)
{
    int *arr = NULL;

    arr = get_any_int_array(true_rect);
    if (arr == NULL || npc == NULL) {
        my_putstr(1, "need array of int inside 'rect' array\n");
        return (RET_ERR_INPUT);
    }
    npc->bigdata.sprite_bigdata.rect = (sfIntRect) {
        arr[0], arr[1], arr[2], arr[3]
    };
    sfSprite_setOrigin(npc->drawable.sprite, (sfVector2f) {
        arr[2] / 2.0, arr[3] / 2.0});
    return (RET_OK);
}

int aplly_rect_npc(any_t *jsonrect, any_t *current, object_t *npc)
{
    any_t *true_rect = NULL;

    if (jsonrect == NULL || jsonrect->type != ARRAY || current == NULL ||
        current->type != INT || jsonrect->value.array == NULL) {
        my_putstr(1, "need 'rect' array of [left,top,width,height]\n");
        my_putstr(1, "need 'current' int set to 0");
        return (RET_ERR_INPUT);
    }
    current->value.i = (current->value.i + 1) % jsonrect->value.array->len;
    true_rect = get_from_any(jsonrect, "a", current->value.i);
    if (true_rect == NULL || true_rect->type != ARRAY ||
        true_rect->value.array == NULL || true_rect->value.array->len != 4) {
        my_putstr(1, "need array of size 4 in 'rect' array\n");
        return (RET_ERR_INPUT);
    }
    return (aplly_intrect_npc(true_rect, npc));
}
