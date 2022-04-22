/*
** EPITECH PROJECT, 2022
** LIBBGS
** File description:
** destroy a framebuffer
*/

#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <stdlib.h>
#include "my_bgs_framebuffer.h"

static void free_rest_of_buf(framebuffer_t *buf)
{
    if (buf->to_remove != NULL) {
        free_list(buf->to_remove);
    }
    if (buf->sprite != NULL) {
        sfSprite_destroy(buf->sprite);
    }
    if (buf->texture != NULL) {
        sfTexture_destroy(buf->texture);
    }
}

void destroy_framebuffer(framebuffer_t *buf)
{
    struct element_s *tmp_tmp = NULL;

    if (buf == NULL) {
        return;
    }
    if (buf->pixels != NULL) {
        free(buf->pixels);
    }
    for (struct element_s *tmp = buf->elements; tmp != NULL; tmp = tmp_tmp) {
        tmp_tmp = tmp->next;
        free(tmp);
    }
    free_rest_of_buf(buf);
    free(buf);
}
