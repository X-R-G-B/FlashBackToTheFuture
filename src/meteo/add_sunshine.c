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
#include "list.h"
#include "my_macro.h"
#include "my_bgs.h"
#include "my_bgs_framebuffer.h"
#include "meteo.h"
#include "macro.h"

static const sfVector2f vectors[NB_VECTORS_SUN] = {
    {.x = 12, .y = 6},
    {.x = 6, .y = 12},
    {.x = 10, .y = 8},
    {.x = 8, .y = 10},
    {.x = 6, .y = 10},
    {.x = 6, .y = 8},
    {.x = 10, .y = 6},
    {.x = 8, .y = 6},
    {.x = 4, .y = 12},
    {.x = 12, .y = 5},
    {.x = 3, .y = 18},
    {.x = 5, .y = 18},
    {.x = 6, .y = 18},
    {.x = 7, .y = 18},
    {.x = 3, .y = 14},
    {.x = 5, .y = 14},
    {.x = 6, .y = 14},
    {.x = 7, .y = 14},
    {.x = 18, .y = 4},
    {.x = 18, .y = 5},
    {.x = 18, .y = 6},
    {.x = 18, .y = 7},
    {.x = 9, .y = 4},
    {.x = 9, .y = 5},
    {.x = 9, .y = 6},
    {.x = 9, .y = 7}
};

static float time_disappear = 2;

static void update_sun(struct element_s *elem,
    framebuffer_t *buf,
    float dtime)
{
    float y = 0;
    sfVector2f vect = {0};
    int add_rand = rand() % 3;

    if (elem == NULL || buf == NULL) {
        return;
    }
    vect = (sfVector2f) {
        .x = elem->data.line.point_b.x - elem->data.line.point_a.x + add_rand,
        .y = elem->data.line.point_b.y - elem->data.line.point_a.y + add_rand
    };
    elem->data.line.point_b.y += (int) (((vect.y) * (dtime * 100)) / 3.0);
    elem->data.line.point_b.x += (int) (((vect.x) * (dtime * 100)) / 3.0);
    elem->data.line.point_a.y += (int) (((vect.y) * (dtime * 100)) / 3.0);
    elem->data.line.point_a.x += (int) (((vect.x) * (dtime * 100)) / 3.0);
    y = elem->data.line.point_b.y;
    if (y > (float) buf->height || y < 0) {
        list_add_to_start(buf->to_remove, elem);
    }
}

static void update_circle_sun(struct element_s *elem, framebuffer_t *buf,
    float dtime)
{
    static float time = 0;

    if (elem == NULL || buf == NULL) {
        return;
    }
    elem->data.circle.radius += rand() % 2;
    time += dtime;
    if (time > time_disappear) {
        list_add_to_end(buf->to_remove, elem);
        time -= time_disappear;
    }
}

static void update_circle_sun_rand(struct element_s *elem, framebuffer_t *buf,
    __attribute__((unused)) float dtime)
{
    int new_a = 0;

    if (elem == NULL || buf == NULL) {
        return;
    }
    elem->data.circle.radius += (50 - rand() % 100);
    new_a = elem->data.circle.color.a - rand() % 20;
    if (new_a <= 0) {
        list_add_to_end(buf->to_remove, elem);
        return;
    }
    elem->data.circle.color.a = new_a;
    elem->data.circle.center.x += rand() % 5;
    elem->data.circle.center.y += rand() % 2;
    if (elem->data.circle.radius <= 0 || elem->data.circle.color.a <= 0) {
        list_add_to_start(buf->to_remove, elem);
    }
}

static void add_circle_suns(window_t *win)
{
    elem_circle_t circle = {
        .color = sfColor_fromRGBA(255, 255, 0, 150),
        .center = (sfVector2f) {40, 40},
        .is_plain = true,
        .radius = 30
    };

    fb_add_circle(win->buf, circle, &update_circle_sun);
    if (rand() % 3 == 0) {
        circle.radius = 5 + rand() % 20;
        circle.center.x = rand() % WIN_SIZE_X;
        circle.center.y = rand() % WIN_SIZE_Y;
        circle.color = sfColor_fromRGBA(255, 255, 10, 100);
        fb_add_circle(win->buf, circle, update_circle_sun_rand);
    }
}

int add_sun(window_t *win, __attribute__((unused)) int x)
{
    elem_line_t line = {
        .color = sfColor_fromRGBA(255, 255, 0, 200),
        .point_a = (sfVector2f) {3, 3},
    };

    if (win == NULL) {
        return (RET_ERR_INPUT);
    }
    for (int i = 0; i < 7; i++) {
        line.point_b = vectors[rand() % NB_VECTORS_SUN];
        fb_add_line(win->buf, line, update_sun);
    }
    add_circle_suns(win);
    return (RET_OK);
}
