/*
** EPITECH PROJECT, 2022
** LIBBGS
** File description:
** draw rect pixel
*/

#include <SFML/Graphics/Rect.h>
#include <stdbool.h>
#include "my_macro.h"
#include "my_bgs_framebuffer.h"
#include "framebuffer.h"

int draw_rect_pixel(sfVector2f pos, elem_rect_t rect, framebuffer_t *buf)
{
    sfFloatRect re = {0};

    if (buf == NULL || is_out_of_range(pos, buf->width, buf->height) != 0) {
        return (1);
    }
    re = rect.rect;
    if (rect.is_plain == true) {
        if (sfFloatRect_contains(&rect.rect, pos.x, pos.y)) {
            fb_put_pixel(buf, pos, rect.color);
        }
        return (0);
    }
    if (ABSOL(pos.x - re.left) < 2 || ABSOL(pos.y - re.top) < 2) {
        fb_put_pixel(buf, pos, rect.color);
    }
    if (ABSOL((re.left + re.width) - pos.x) < 2 ||
            ABSOL((re.top + re.height) - pos.y) < 2) {
        fb_put_pixel(buf, pos, rect.color);
    }
    return (0);
}
