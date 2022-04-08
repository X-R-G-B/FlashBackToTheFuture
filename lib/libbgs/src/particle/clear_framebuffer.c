/*
** EPITECH PROJECT, 2022
** LIBBGS
** File description:
** clear a framebuffer
*/

#include "my_bgs.h"
#include "my_bgs_framebuffer.h"

int clear_framebuffer(framebuffer_t *buf, sfColor color)
{
    if (buf == NULL) {
        return (BGS_ERR_INPUT);
    }
    for (int index = 0; index < buf->width * buf->height * 4; index += 4) {
        buf->pixels[index + 0] = color.r;
        buf->pixels[index + 1] = color.g;
        buf->pixels[index + 2] = color.b;
        buf->pixels[index + 3] = color.a;
    }
    return (BGS_OK);
}
