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

static void update_sun(struct element_s *elem,
    __attribute__((unused)) framebuffer_t *buf,
    float dtime)
{
    float y = 0;
    sfVector2f vect = {
        .x = elem->data.line.point_b.x - elem->data.line.point_a.x,
        .y = elem->data.line.point_b.y - elem->data.line.point_a.y
    };

    elem->data.line.point_b.y += (int) MAX(((vect.y) * (dtime * 100)) / 3, 1);
    elem->data.line.point_b.x += (int) MAX(((vect.x) * (dtime * 100)) / 3, 1);
    elem->data.line.point_a.y += (int) MAX(((vect.y) * (dtime * 100)) / 3, 1);
    elem->data.line.point_a.x += (int) MAX(((vect.x) * (dtime * 100)) / 3, 1);
    y = elem->data.line.point_b.y;
    if (y > (float) buf->height) {
        list_add_to_start(buf->to_remove, elem);
    }
}

int add_sun(window_t *win, __attribute__((unused)) int x)
{
    int sizex = 0;
    int sizey = 0;
    elem_line_t line = {
        .color = sfColor_fromRGBA(255, 255, 0, 200),
        .point_a = (sfVector2f) {3, 3},
    };

    if (win == NULL) {
        return (RET_ERR_INPUT);
    }
    for (int i = 0; i < 5; i++) {
        sizey = 3 + rand() % (int) (WIN_SIZE_Y / 100);
        sizex = 3 + rand() % (int) (WIN_SIZE_X / 100);
        line.point_b = (sfVector2f) {(int) (sizex * 2), (int) (sizey * 2)};
        fb_add_line(win->buf, line, update_sun);
    }
    return (RET_OK);
}
