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
    if (buf == NULL) {
        return (0);
    }
    if (rect.is_plain == true) {
        if (sfFloatRect_contains(&rect.rect, pos.x, pos.y)) {
            fb_put_pixel(buf, pos, rect.color);
        }
    } else if (ABSOL(pos.x - rect.rect.left) < 2 ||
            ABSOL(pos.x - rect.rect.left + rect.rect.width) < 2 ||
            ABSOL(pos.y - rect.rect.top) < 2 ||
            ABSOL(pos.y - rect.rect.top + rect.rect.height) < 2) {
        fb_put_pixel(buf, pos, rect.color);
    }
    return (0);
}
