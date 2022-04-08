/*
** EPITECH PROJECT, 2022
** LIBBGS
** File description:
** destroy a framebuffer
*/

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
}
