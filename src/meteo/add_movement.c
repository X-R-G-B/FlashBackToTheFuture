/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** add movement dirt
*/

#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System/Vector2.h>
#include <stdbool.h>
#include <stdlib.h>
#include "list.h"
#include "my_bgs.h"
#include "my_bgs_framebuffer.h"
#include "my_rpg.h"
#include "macro.h"

static void update_circle_t(struct element_s *elem, framebuffer_t *buf,
    __attribute__((unused)) float dtime)
{
    int new_a = 0;

    if (elem == NULL || buf == NULL) {
        return;
    }
    new_a = elem->data.circle.color.a - rand() % 20;
    elem->data.circle.center.x += rand() % 3;
    if (new_a < 0) {
        list_add_to_start(buf->to_remove, elem);
    }
    elem->data.circle.color.a = new_a;
}

static void update_rect_t(struct element_s *elem, framebuffer_t *buf,
    __attribute__((unused)) float dtime)
{
    int new_a = 0;

    if (elem == NULL || buf == NULL) {
        return;
    }
    new_a = elem->data.rect.color.a - rand() % 20;
    if (new_a < 0) {
        list_add_to_start(buf->to_remove, elem);
    }
    elem->data.rect.rect.left += rand() % 3;
    elem->data.rect.color.a = new_a;
}

static void update_line_t(struct element_s *elem, framebuffer_t *buf,
    __attribute__((unused)) float dtime)
{
    int new_a = 0;

    if (elem == NULL || buf == NULL) {
        return;
    }
    new_a = elem->data.line.color.a - rand() % 20;
    if (new_a < 0) {
        list_add_to_start(buf->to_remove, elem);
    }
    elem->data.line.point_b.x += rand() % 3;
    elem->data.line.point_a.x += rand() % 3;
    elem->data.line.color.a = new_a;
}

static void add_random_elem(framebuffer_t *buf, sfVector2f pos)
{
    sfColor color = sfColor_fromRGBA(90, 51, 1, 100 + rand() % 150);
    elem_circle_t circle = {.center = pos, .radius = rand() % 10,
        .color = color, .is_plain = true};
    elem_rect_t rect = {.is_plain = true, .color = color,
        .rect = (sfFloatRect) {pos.x, pos.y, rand() % 10, rand() % 10}};
    elem_line_t line = {.point_a = pos, .color = color,
        .point_b = (sfVector2f) {.x = pos.x + rand() % 10,
        .y = pos.y + rand() % 10}};
    int rand_num = rand() % 3;

    if (rand_num == 0) {
        fb_add_circle(buf, circle, update_circle_t);
    } else if (rand_num == 1) {
        fb_add_line(buf, line, update_line_t);
    } else {
        fb_add_rect(buf, rect, update_rect_t);
    }
}

int add_dirt_player(window_t *win, player_t *player)
{
    sfVector2f pos = {(int) (WIN_SIZE_X / 2),
        (int) ((WIN_SIZE_Y / 2) + 30)};
    framebuffer_t *buf = NULL;

    if (win == NULL || player == NULL || player->obj == NULL) {
        return (RET_ERR_INPUT);
    }
    if (player->dir == UP) {
        buf = win->buf;
    } else {
        buf = player->buf;
    }
    for (int i = 0; i < 5; i++) {
        add_random_elem(buf, (sfVector2f) {pos.x - 10 + rand() % 20,
            pos.y - 10 + rand() % 20});
    }
    return (RET_OK);
}
