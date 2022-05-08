/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** add leaf on sreen
*/

#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System/Vector2.h>
#include <stdbool.h>
#include <stdlib.h>
#include "my_macro.h"
#include "my_bgs.h"
#include "my_bgs_framebuffer.h"
#include "macro.h"

static void update_leaf(struct element_s *elem,
    framebuffer_t *buf,
    float dtime)
{
    float y = 0;

    if (elem == NULL || buf == NULL) {
        return;
    }
    elem->data.rect.rect.top += (int) MAX(dtime * 200, 1);
    y = elem->data.rect.rect.top;
    if (y > (float) buf->height) {
        list_add_to_start(buf->to_remove, elem);
    }
}

int add_leaf(window_t *win, int x)
{
    int sizex = (rand() % 2 == 0) ? 10 : 20;
    int sizey = (rand() % 2 == 0) ? 10 : 20;
    elem_rect_t rect = {
        .rect = (sfFloatRect) {x, 0, sizex, sizey},
        .color = sfColor_fromRGBA(255, 0, 0, 150 + rand() % 100),
        .is_plain = true
    };
    elem_rect_t rect2 = {
        .rect = (sfFloatRect) {x + (int) (sizex / 2) - 2, sizey / 2.0,
            2, sizey},
        .color = sfColor_fromRGBA(0, 0, 0, 200 + rand() % 50),
        .is_plain = true
    };

    if (win == NULL) {
        return (RET_ERR_INPUT);
    }
    fb_add_rect(win->buf, rect2, update_leaf);
    fb_add_rect(win->buf, rect, update_leaf);
    return (RET_OK);
}
