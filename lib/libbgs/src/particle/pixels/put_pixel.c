/*
** EPITECH PROJECT, 2022
** LIBBGS
** File description:
** put a pixel in framebuffer
*/

#include <SFML/Graphics/Color.h>
#include <SFML/System/Vector2.h>
#include "my_bgs_framebuffer.h"
#include "framebuffer.h"

int fb_put_pixel(framebuffer_t *buf, sfVector2f pos, sfColor color)
{
    int index = 0;

    if (pos.x >= buf->width || pos.x < 0) {
        return (0);
    }
    if (pos.y >= buf->height || pos.y < 0) {
        return (0);
    }
    index = ((pos.y * buf->width) + pos.x) * 4;
    buf->pixels[index + 0] = color.r;
    buf->pixels[index + 1] = color.g;
    buf->pixels[index + 2] = color.b;
    buf->pixels[index + 3] = color.a;
    return (0);
}
