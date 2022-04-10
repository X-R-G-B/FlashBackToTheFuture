/*
** EPITECH PROJECT, 2022
** LIBBGS
** File description:
** call update of elements
*/

#include "my_bgs.h"
#include "my_bgs_framebuffer.h"

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
    return (BGS_OK);
}
