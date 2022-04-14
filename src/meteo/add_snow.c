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
#include "my_rpg.h"

static void update_snow(struct element_s *elem,
    __attribute__((unused)) framebuffer_t *buf,
    float dtime)
{
    float y = 0;

    elem->data.line.point_b.y += (int) MAX(dtime * 100, 1);
    elem->data.line.point_a.y += (int) MAX(dtime * 100, 1);
    y = elem->data.line.point_b.y;
    if (y > buf->height) {
        list_add_to_start(buf->to_remove, elem);
    }
}

int add_snow(window_t *win, int x)
{
    int sizex = (rand() % 2 == 0) ? 2 : 10;
    int sizey = (rand() % 2 == 0) ? 2 : 10;
    elem_line_t line1 = {
        .color = sfColor_fromRGBA(255, 255, 255, 200),
        .point_a = (sfVector2f) {x, 0},
        .point_b = (sfVector2f) {(int) (x + sizex), (int) (sizey * 2)} };
    elem_line_t line2 = {
        .color = sfColor_fromRGBA(255, 255, 255, 200),
        .point_a = (sfVector2f) {(int) (x + sizex), 0},
        .point_b = (sfVector2f) {x, (int) (sizey * 2)} };

    if (win == NULL) {
        return (RET_ERR_INPUT);
    }
    fb_add_line(win->buf, line1, update_snow);
    fb_add_line(win->buf, line2, update_snow);
    return (RET_OK);
}
