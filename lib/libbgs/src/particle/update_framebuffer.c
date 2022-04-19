/*
** EPITECH PROJECT, 2022
** LIBBGS
** File description:
** call update of elements
*/

#include <stdlib.h>
#include "list.h"
#include "my_bgs.h"
#include "my_bgs_framebuffer.h"

static void free_node_elem(list_t *to_remove, framebuffer_t *buf)
{
    struct element_s *elem = NULL;

    if (buf->elements == NULL) {
        return;
    }
    if (buf->elements == to_remove->var) {
        buf->elements = buf->elements->next;
        free(to_remove->var);
    }
    for (struct element_s *tmp = buf->elements; tmp != NULL; tmp = tmp->next) {
        if (tmp->next == to_remove->var) {
            elem = tmp->next;
            tmp->next = tmp->next->next;
            free(elem);
            break;
        }
    }
}

int update_framebuffer(framebuffer_t *buf, float dtime)
{
    if (buf == NULL) {
        return (BGS_ERR_INPUT);
    }
    for (struct element_s *tmp = buf->elements; tmp != NULL; tmp = tmp->next) {
        if (tmp->update == NULL) {
            continue;
        }
        tmp->update(tmp, buf, dtime);
    }
    while (buf->to_remove->len > 0) {
        free_node_elem(buf->to_remove->start, buf);
        rm_fst_elem(buf->to_remove);
    }
    return (BGS_OK);
}
