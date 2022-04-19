/*
** EPITECH PROJECT, 2022
** LIBBGS
** File description:
** create a framebuffer
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/System/Vector2.h>
#include <stdlib.h>
#include <SFML/Config.h>
#include "list.h"
#include "my_bgs_framebuffer.h"

static int create_pixels(framebuffer_t *buf, unsigned int width,
    unsigned int height)
{
    if (buf == NULL) {
        return (1);
    }
    buf->pixels = malloc(sizeof(sfUint8) * (width * height * 4));
    if (buf->pixels == NULL) {
        free(buf);
        return (1);
    }
    clear_framebuffer(buf, sfTransparent);
    return (0);
}

static int init_default_values(framebuffer_t *buf, unsigned int width,
    unsigned int height, sfVector2f pos_on_win)
{
    if (buf == NULL) {
        return (1);
    }
    buf->elements = NULL;
    buf->height = height;
    buf->width = width;
    buf->pos_on_win = pos_on_win;
    buf->to_remove = list_create();
    if (buf->to_remove == NULL) {
        free(buf);
        return (1);
    }
    return (0);
}

static int create_texture_sprite(framebuffer_t *buf)
{
    buf->texture = sfTexture_create(buf->width, buf->height);
    if (buf->texture == NULL) {
        free(buf->pixels);
        free(buf);
        return (1);
    }
    sfTexture_updateFromPixels(buf->texture, buf->pixels, buf->width,
        buf->height, 0, 0);
    buf->sprite = sfSprite_create();
    if (buf->sprite == NULL) {
        sfTexture_destroy(buf->texture);
        free(buf->pixels);
        free(buf);
        return (1);
    }
    sfSprite_setTexture(buf->sprite, buf->texture, sfTrue);
    return (0);
}

framebuffer_t *create_framebuffer(unsigned int width, unsigned int height,
        sfVector2f pos_on_win)
{
    framebuffer_t *buf = NULL;

    if (width == 0 || height == 0) {
        return (NULL);
    }
    buf = malloc(sizeof(framebuffer_t));
    if (buf == NULL) {
        return (NULL);
    }
    if (init_default_values(buf, width, height, pos_on_win) == 1) {
        return (NULL);
    }
    if (create_pixels(buf, width, height) == 1) {
        return (NULL);
    }
    if (create_texture_sprite(buf) == 1) {
        return (NULL);
    }
    return (buf);
}
