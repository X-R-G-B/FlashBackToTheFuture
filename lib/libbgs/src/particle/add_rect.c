/*
** EPITECH PROJECT, 2022
** LIBBGS
** File description:
** add a rect to framebuffer
*/

#include <stdlib.h>
#include "my_bgs.h"
#include "my_bgs_framebuffer.h"
#include "framebuffer.h"

static int init_values(elem_rect_t *dest, elem_rect_t *src)
{
    if (dest == NULL || src == NULL) {
        return (1);
    }
    dest->is_plain = src->is_plain;
    dest->rect = src->rect;
    return (0);
}

int fb_add_rect(framebuffer_t *buf, elem_rect_t rect_info,
    void (*update)(struct element_s *element, framebuffer_t *buf, float dtime))
{
    struct element_s *new = NULL;

    if (buf == NULL) {
        return (BGS_ERR_INPUT);
    }
    new = add_element(buf, RECT, update);
    if (new == NULL) {
        return (BGS_ERR_MALLOC);
    }
    if (init_values(&new->data.rect, &rect_info) == 1) {
        return (BGS_ERR_INPUT);
    }
    return (BGS_OK);
}
