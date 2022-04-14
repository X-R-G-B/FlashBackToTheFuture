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

static void update_snow(struct element_s *elem,
    __attribute__((unused)) framebuffer_t *buf,
    float dtime)
{
    float y = 0;

    if (elem->type == LINE) {
        elem->data.line.point_b.y += dtime;
        elem->data.line.point_a.y += dtime;
        y = elem->data.line.point_b.y;
    } else if (elem->type == RECT) {
        elem->data.rect.rect.top += dtime;
        y = elem->data.rect.rect.top;
    }
    if (y > buf->height) {
        list_add_to_start(buf->to_remove, elem);
    }
}

int add_snow(window_t *win, int x)
{
    int sizex = (rand() % 2 == 0) ? 2 : 10;
    int sizey = (rand() % 2 == 0) ? 2 : 10;
    elem_line_t line1 = {
        .color = sfWhite,
        .point_a = (sfVector2f) {x + 0, 0},
        .point_b = (sfVector2f) {x + sizex, sizey * 2} };
    elem_line_t line2 = {
        .color = sfWhite,
        .point_a = (sfVector2f) {x + sizex, 0},
        .point_b = (sfVector2f) {x + 0, sizey * 2} };

    if (win == NULL) {
        return (RET_ERR_INPUT);
    }
    fb_add_line(win->buf, line1, update_snow);
    fb_add_line(win->buf, line2, update_snow);
    return (RET_OK);
}
