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
#include "my_bgs.h"
#include "my_bgs_framebuffer.h"
#include "my_rpg.h"

static void update_leaf(struct element_s *elem,
    __attribute__((unused)) framebuffer_t *buf,
    float dtime)
{
    float y = 0;

    if (elem->type == LINE) {
        elem->data.line.point_b.y += dtime * 30;
        elem->data.line.point_a.y += dtime * 30;
        y = elem->data.line.point_b.y;
    } else if (elem->type == RECT) {
        elem->data.rect.rect.top += dtime * 30;
        y = elem->data.rect.rect.top;
    }
    if (y > (float) buf->height) {
        printf("this is here\n");
        list_add_to_start(buf->to_remove, elem);
    }
}

int add_leaf(window_t *win, int x)
{
    int sizex = (rand() % 2 == 0) ? 10 : 20;
    int sizey = (rand() % 2 == 0) ? 10 : 20;
    elem_rect_t rect = {
        .rect = (sfFloatRect) {x, 0, sizex, sizey},
        .color = sfColor_fromRGBA(199, 69, 53, 255),
        .is_plain = true
    };
    elem_line_t line = {
        .color = sfColor_fromRGBA(140, 42, 39, 255),
        .point_a = (sfVector2f) {x + sizex / 2.0, sizey / 2.0},
        .point_b = (sfVector2f) {x + sizex / 2.0, sizey * 2}
    };

    if (win == NULL) {
        return (RET_ERR_INPUT);
    }
    fb_add_line(win->buf, line, update_leaf);
    fb_add_rect(win->buf, rect, update_leaf);
    return (RET_OK);
}
