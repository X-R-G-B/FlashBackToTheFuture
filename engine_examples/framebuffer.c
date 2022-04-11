/*
** EPITECH PROJECT, 2022
** frame buffer example
** File description:
** frame buffer example
*/

#include <SFML/Graphics/Rect.h>
#include <SFML/System/Vector2.h>
#include <stdbool.h>
#include "my_bgs.h"
#include "my_bgs_framebuffer.h"

void update_circle(struct element_s *elem,
    __attribute((unused)) framebuffer_t *buf, float dtime)
{
    static int is_expense = 1;
    static float time_change_expanse = 0;
    static float time_update = 0;

    time_change_expanse += dtime;
    time_update += dtime;
    if (time_change_expanse > 2.0) {
        is_expense *= -1;
        time_change_expanse -= 2;
    }
    if (time_update > 1 / 5.0) {
        elem->data.circle.radius += 10 * is_expense;
        time_update -= 1 / 5.0;
    }
}

void create_circle(window_t *win)
{
    elem_circle_t circle = {
        .center = (sfVector2f) {500, 500},
        .color = sfRed,
        .is_plain = true,
        .radius = 20
    };

    fb_add_circle(win->buf, circle, &update_circle);
    circle.is_plain = false;
    circle.center.x = 100;
    fb_add_circle(win->buf, circle, NULL);
}

void update_rect(struct element_s *elem,
    __attribute((unused)) framebuffer_t *buf, float dtime)
{
    static int is_expense = 1;
    static float time_change_expanse = 0;
    static float time_update = 0;

    time_change_expanse += dtime;
    time_update += dtime;
    if (time_change_expanse > 2.0) {
        is_expense *= -1;
        time_change_expanse -= 2;
    }
    if (time_update > 1 / 5.0) {
        elem->data.rect.rect.height += 10 * is_expense;
        time_update -= 1 / 5.0;
    }
}

void create_rect(window_t *win)
{
    elem_rect_t rect = {
        .color = sfRed,
        .is_plain = true,
        .rect = (sfFloatRect) {10, 10, 20, 40},
    };

    fb_add_rect(win->buf, rect, NULL);
    rect.is_plain = false;
    rect.rect.left = 100;
    fb_add_rect(win->buf, rect, update_rect);
}

int main(void)
{
    window_t *win = create_window((sfVideoMode) {800, 600, 32},
        "test", sfClose);
    elem_line_t line = {
        .color = sfMagenta,
        .point_a = (sfVector2f) {50, 50},
        .point_b = (sfVector2f) {100, 500}
    };

    create_scene(win, sfBlack, "TEST");
    window_change_scene(win, "TEST");
    create_circle(win);
    create_rect(win);
    fb_add_line(win->buf, line, NULL);
    loop(win);
    remove_window(win);
    return (0);
}
