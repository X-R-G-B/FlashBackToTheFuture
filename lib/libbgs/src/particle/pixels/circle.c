/*
** EPITECH PROJECT, 2022
** LIBBGS
** File description:
** draw circle pixels
*/

#include <stdbool.h>
#include <math.h>
#include <SFML/System/Vector2.h>
#include "my_bgs_framebuffer.h"
#include "framebuffer.h"

int draw_circle_pixel(sfVector2f pos, elem_circle_t *circle,
    framebuffer_t *buf)
{
    float dist = 0;
    float dist_rad = 0;
    bool is_draw = false;

    if (buf == NULL || is_out_of_range(pos, buf->width, buf->height) != 0) {
        return (1);
    }
    dist = pow(pos.x - circle->center.x, 2) + pow(pos.y - circle->center.y, 2);
    dist_rad = pow(circle->radius, 2);
    if (circle->is_plain == true) {
        is_draw = dist <= dist_rad;
    } else {
        is_draw = dist <= (dist_rad + circle->radius * 2) &&
            dist >= (dist_rad - circle->radius * 2);
    }
    if (is_draw != 0) {
        fb_put_pixel(buf, pos, circle->color);
    }
    return (0);
}
