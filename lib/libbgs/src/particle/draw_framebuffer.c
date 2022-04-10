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
    sfVector2f pa = {elem->rect.rect.left, elem->rect.rect.top};
    sfVector2f pb = {
        elem->rect.rect.left + elem->rect.rect.width,
        elem->rect.rect.top + elem->rect.rect.height
    };
    sfVector2f pos = {0};

    for (pos.y = pa.y; pos.y < pb.y; pos.y++) {
        for (pos.x = pa.x; pos.x < pb.x; pos.x++) {
            draw_rect_pixel(pos, elem->rect, buf);
        }
    }
}

static void draw_elem_line(framebuffer_t *buf, union elem_data_s *elem)
{
    sfVector2f pa = elem->line.point_a;
    sfVector2f pb = elem->line.point_b;
    sfVector2f max = {MAX(pa.x, pb.x), MAX(pa.y, pb.y)};
    sfVector2f min = {MIN(pa.x, pb.x), MIN(pa.y, pb.y)};
    int calc_values[2] = {(pa.y - pb.y) / (pa.x - pb.x), 0};
    sfVector2f pos = {0};

    calc_values[1] = pa.y - (calc_values[0] * pa.x);
    for (pos.y = min.y; pos.y < max.y; pos.y++) {
        for (pos.x = min.x; pos.x < max.x; pos.x++) {
            draw_line_pixel(pos, calc_values, buf, elem->line.color);
        }
    }
}

static void draw_elem_circle(framebuffer_t *buf, union elem_data_s *elem)
{
    sfVector2f center = elem->circle.center;
    unsigned int radius = elem->circle.radius;
    sfVector2f pos = {0};

    for (pos.y = center.y - radius; pos.y < center.y + radius; pos.y++) {
        for (pos.x = center.x - radius; pos.x < center.x + radius; pos.x++) {
            draw_circle_pixel(pos, &elem->circle, buf);
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
    if (win == NULL || buf == NULL) {
        return (BGS_ERR_INPUT);
    }
    for (struct element_s *tmp = buf->elements; tmp != NULL; tmp = tmp->next) {
        draw_element_s(buf, tmp);
    }
    sfTexture_updateFromPixels(buf->texture, buf->pixels, buf->width,
        buf->height, 0, 0);
    sfRenderWindow_drawSprite(win->win, buf->sprite, NULL);
    return (BGS_OK);
}
