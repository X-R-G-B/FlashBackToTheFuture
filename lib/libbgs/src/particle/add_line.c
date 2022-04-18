/*
** EPITECH PROJECT, 2022
** LIBBGS
** File description:
** add a line to framebuffer
*/

#include <stdlib.h>
#include "my_bgs.h"
#include "my_bgs_framebuffer.h"
#include "framebuffer.h"

static int init_values(elem_line_t *dest, elem_line_t *src)
{
    if (dest == NULL || src == NULL) {
        return (1);
    }
    dest->point_a = src->point_a;
    dest->point_b = src->point_b;
    dest->color = src->color;
    return (0);
}

int fb_add_line(framebuffer_t *buf, elem_line_t line_info,
    void (*update)(struct element_s *element, framebuffer_t *buf, float dtime))
{
    struct element_s *new = NULL;

    if (buf == NULL) {
        return (BGS_ERR_INPUT);
    }
    new = add_element(buf, LINE, update);
    if (new == NULL) {
        return (BGS_ERR_MALLOC);
    }
    if (init_values(&new->data.line, &line_info) == 1) {
        return (BGS_ERR_INPUT);
    }
    return (BGS_OK);
}
