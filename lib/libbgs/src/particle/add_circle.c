/*
** EPITECH PROJECT, 2022
** LIBBGS
** File description:
** add a circle to framebuffer
*/

#include <stdlib.h>
#include "my_bgs.h"
#include "my_bgs_framebuffer.h"
#include "framebuffer.h"

static int init_values(elem_circle_t *dest, elem_circle_t *src)
{
    if (dest == NULL || src == NULL) {
        return (1);
    }
    dest->radius = src->radius;
    dest->center = src->center;
    dest->color = src->color;
    dest->is_plain = src->is_plain;
    return (0);
}

int fb_add_circle(framebuffer_t *buf, elem_circle_t circle_info,
    void (*update)(struct element_s *element, framebuffer_t *buf, float dtime))
{
    struct element_s *new = NULL;

    if (buf == NULL) {
        return (BGS_ERR_INPUT);
    }
    new = add_element(buf, CIRCLE, update);
    if (new == NULL) {
        return (BGS_ERR_MALLOC);
    }
    if (init_values(&new->data.circle, &circle_info) == 1) {
        return (BGS_ERR_INPUT);
    }
    return (BGS_OK);
}
