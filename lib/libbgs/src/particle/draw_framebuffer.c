/*
** EPITECH PROJECT, 2022
** LIBBGS
** File description:
** draw framebuffer to window
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/System/Vector2.h>
#include "my_bgs.h"
#include "my_macro.h"
#include "my_bgs_framebuffer.h"
#include "framebuffer.h"

static void draw_elem_rect(framebuffer_t *buf, union elem_data_s *elem)
{
    sfVector2f pa = {.x = elem->rect.rect.left, .y = elem->rect.rect.top};
    sfVector2f pb = {
        .x = elem->rect.rect.left + elem->rect.rect.width,
        .y = elem->rect.rect.top + elem->rect.rect.height
    };
    sfVector2f pos = {0};
    int need_break = 0;
    int status = 0;

    for (pos.y = (int) pa.y; pos.y <= pb.y && need_break == 0; pos.y++) {
        for (pos.x = (int) pa.x; pos.x <= pb.x && need_break == 0; pos.x++) {
            status = draw_rect_pixel(pos, elem->rect, buf);
            need_break = (need_break == 1) ? 1 : status;
        }
    }
}

static void draw_elem_line(framebuffer_t *buf, union elem_data_s *elem)
{
    sfVector2f pa = elem->line.point_a;
    sfVector2f pb = elem->line.point_b;
    sfVector2f max = {(int) MAX(pa.x, pb.x), (int) MAX(pa.y, pb.y)};
    sfVector2f min = {(int) MIN(pa.x, pb.x), (int) MIN(pa.y, pb.y)};
    int calc_values[2] = {(pa.y - pb.y) / (pa.x - pb.x), 0};
    sfVector2f pos = {0};
    int need_break = 0;
    int status = 0;

    calc_values[1] = pa.y - (calc_values[0] * pa.x);
    for (pos.y = min.y; pos.y < max.y && need_break == 0; pos.y++) {
        for (pos.x = min.x; pos.x < max.x && need_break == 0; pos.x++) {
            status = draw_line_pixel(pos, calc_values, buf, elem->line.color);
            need_break = (need_break == 1) ? 1 : status;
        }
    }
}

static void draw_elem_circle(framebuffer_t *buf, union elem_data_s *elem)
{
    sfVector2f center = elem->circle.center;
    unsigned int radius = elem->circle.radius;
    sfVector2f pos = {0};
    int need_break = 0;
    int status = 0;

    if (elem->circle.radius <= 0) {
        return;
    }
    for (pos.y = (int) (center.y - radius); pos.y < center.y + radius &&
            need_break == 0; pos.y++) {
        for (pos.x = (int) (center.x - radius); pos.x < center.x + radius &&
                need_break == 0; pos.x++) {
            status = draw_circle_pixel(pos, &elem->circle, buf);
            need_break = (need_break == 1) ? 1 : status;
        }
    }
}

static int draw_element_s(framebuffer_t *buf, struct element_s *elem)
{
    switch (elem->type) {
        case LINE:
            draw_elem_line(buf, &elem->data);
            break;
        case RECT:
            draw_elem_rect(buf, &elem->data);
            break;
        case CIRCLE:
            draw_elem_circle(buf, &elem->data);
            break;
        default:
            break;
    }
    return (0);
}

int draw_framebuffer(window_t *win, framebuffer_t *buf)
{
    if (win == NULL || buf == NULL || buf->texture == NULL) {
        return (BGS_ERR_INPUT);
    }
    clear_framebuffer(buf, sfTransparent);
    for (struct element_s *tmp = buf->elements; tmp != NULL; tmp = tmp->next) {
        draw_element_s(buf, tmp);
    }
    sfTexture_updateFromPixels(buf->texture, buf->pixels, buf->width,
        buf->height, 0, 0);
    sfSprite_setPosition(buf->sprite, buf->pos_on_win);
    sfRenderWindow_drawSprite(win->win, buf->sprite, NULL);
    return (BGS_OK);
}
