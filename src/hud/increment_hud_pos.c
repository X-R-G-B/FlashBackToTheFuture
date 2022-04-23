/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** increment hud pos
*/

#include "my_rpg.h"

static void increment_obj_list_pos_bigdata(list_ptr_t *hud_elements,
    list_t *elem, sfVector2f to_add)
{
    object_t *obj = NULL;

    for (int i = 0; i < hud_elements->len; i++, elem = elem->next) {
        obj = elem->var;
        if (obj->type == SPRITE) {
            obj->bigdata.sprite_bigdata.pos.x += to_add.x;
            obj->bigdata.sprite_bigdata.pos.y += to_add.y;
        } else if (obj->type == TEXT) {
            obj->bigdata.text_bigdata.pos.x += to_add.x;
            obj->bigdata.text_bigdata.pos.y += to_add.y;
        }
    }
}

void increment_hud_pos(window_t *win, sfVector2f to_add)
{
    list_ptr_t *hud_elements = NULL;
    list_t *elem = NULL;

    if (win == NULL) {
        return;
    }
    hud_elements = dico_t_get_value(win->components, HUD_ELEMENTS);
    if (hud_elements == NULL) {
        return;
    }
    elem = hud_elements->start;
    increment_obj_list_pos_bigdata(hud_elements, elem, to_add);
}
