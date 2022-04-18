/*
** EPITECH PROJECT, 2022
** LIBBGS
** File description:
** draw pixel for line
*/

#include "my_bgs_framebuffer.h"
#include "framebuffer.h"

int draw_line_pixel(sfVector2f pos, int calc_values[2], framebuffer_t *buf,
    sfColor color)
{
    float calc1 = 0;
    float calc2 = 0;
    float div = 0;

    if (buf == NULL || is_out_of_range(pos, buf->width, buf->height) != 0) {
        return (1);
    }
    if (calc_values == NULL || pos.x >= buf->width ||
            pos.x < 0 || pos.y >= buf->height || pos.y <= 0) {
        return (1);
    }
    div = calc_values[0];
    calc1 = (div * pos.x) + calc_values[1];
    div = (div == 0) ? 1 : div;
    calc2 = (pos.y - calc_values[1]) / div;
    if ((pos.y == calc1 - 5 && calc1 + 5 >= pos.x) ||
        (pos.x >= calc2 - 2 && calc2 + 2 >= pos.x)) {
        fb_put_pixel(buf, pos, color);
    }
    return (0);
}
