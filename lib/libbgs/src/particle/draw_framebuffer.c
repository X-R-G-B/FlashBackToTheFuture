/*
** EPITECH PROJECT, 2022
** LIBBGS
** File description:
** draw framebuffer to window
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include "my_bgs.h"
#include "my_bgs_framebuffer.h"

int draw_framebuffer(window_t *win, framebuffer_t *buf)
{
    if (win == NULL || buf == NULL) {
        return (BGS_ERR_INPUT);
    }
    sfTexture_updateFromPixels(buf->texture, buf->pixels, buf->width,
        buf->height, 0, 0);
    sfRenderWindow_drawSprite(win->win, buf->sprite, NULL);
    return (BGS_OK);
}
