/*
** EPITECH PROJECT, 2022
** LIBBGS
** File description:
** create a framebuffer
*/

#include <stdlib.h>
#include <SFML/Config.h>
#include "my_bgs_framebuffer.h"

framebuffer_t *create_framebuffer(unsigned int width, unsigned int height)
{
    framebuffer_t *buf = NULL;

    if (width == 0 || height == 0) {
        return (NULL);
    }
    buf = malloc(sizeof(framebuffer_t));
    if (buf == NULL) {
        return (NULL);
    }
    buf->pixels = malloc(sizeof(sfUint8) * (width * height * 4));
    if (buf->pixels == NULL) {
        free(buf);
        return (NULL);
    }
    clear_framebuffer(buf, sfTransparent);
    buf->elements = NULL;
    buf->height = height;
    buf->width = width;
    return (buf);
}
