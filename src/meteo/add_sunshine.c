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

static void update_sun(struct element_s *elem,
    __attribute__((unused)) framebuffer_t *buf,
    float dtime)
{
    float y = 0;

    if (elem->type == LINE) {
        elem->data.line.point_b.y += (dtime * 10);
        elem->data.line.point_b.x += (dtime * 10);
        y = elem->data.line.point_b.y;
    }
    if (y > (float) buf->height) {
        list_add_to_start(buf->to_remove, elem);
    }
}

int add_sun(window_t *win, __attribute__((unused)) int x)
{
    int sizex = rand() % 10;
    int sizey = rand() % 10;
    elem_line_t line = {
        .color = sfYellow,
        .point_a = (sfVector2f) {0, 0},
        .point_b = (sfVector2f) {sizex, sizey}
    };

    if (win == NULL) {
        return (RET_ERR_INPUT);
    }
    fb_add_circle(win->buf, (elem_circle_t) {.center = (sfVector2f) {500, 500}, .color = sfRed, .is_plain = true, .radius = 20}, NULL);
    fb_add_line(win->buf, line, update_sun);
    return (RET_OK);
}
