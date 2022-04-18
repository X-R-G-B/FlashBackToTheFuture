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

void destroy_framebuffer(framebuffer_t *buf)
{
    struct element_s *tmp_tmp = NULL;

    if (buf == NULL) {
        return;
    }
    free(buf->pixels);
    for (struct element_s *tmp = buf->elements; tmp != NULL; tmp = tmp_tmp) {
        tmp_tmp = tmp->next;
        free(tmp);
    }
    free_list(buf->to_remove);
    sfSprite_destroy(buf->sprite);
    sfTexture_destroy(buf->texture);
    free(buf);
}
