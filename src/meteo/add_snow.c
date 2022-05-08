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

static void update_snow(struct element_s *elem,
    __attribute__((unused)) framebuffer_t *buf,
    float dtime)
{
    float y = 0;

    if (elem == NULL || buf == NULL) {
        return;
    }
    y = 1 + rand() % 5;
    elem->data.circle.center.y += (int) MAX(dtime * 150 * y, 1);
    elem->data.circle.center.x += y;
    y = elem->data.circle.center.y;
    if (y > buf->height) {
        list_add_to_start(buf->to_remove, elem);
    }
}

void create_xx(window_t *win)
{
    elem_circle_t circle = {
        .color = sfColor_fromRGBA(255, 255, 255, 150),
        .is_plain = true,
    };

    for (int i = 0; i < 3; i++) {
        circle.center.x = -WIN_SIZE_X + rand() % (WIN_SIZE_X * 2);
        circle.radius = 10 + rand() % 20;
        fb_add_circle(win->buf, circle, update_snow);
    }
}

int add_snow(window_t *win, __attribute__((unused)) int x)
{
    if (win == NULL) {
        return (RET_ERR_INPUT);
    }
    create_xx(win);
    return (RET_OK);
}
