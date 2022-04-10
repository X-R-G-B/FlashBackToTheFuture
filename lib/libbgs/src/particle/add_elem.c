/*
** EPITECH PROJECT, 2022
** LIBBGS
** File description:
** add an element with no specific type
*/

#include <stdlib.h>
#include "my_bgs_framebuffer.h"
#include "framebuffer.h"

struct element_s *add_element(framebuffer_t *buf, enum elem_data_type type,
    void (*update)(struct element_s *element, framebuffer_t *buf, float dtime))
{
    struct element_s *elem = NULL;

    if (buf == NULL) {
        return (NULL);
    }
    elem = malloc(sizeof(struct element_s));
    if (elem == NULL) {
        return (NULL);
    }
    elem->type = type;
    elem->next = buf->elements;
    elem->update = update;
    buf->elements = elem;
    return (elem);
}
