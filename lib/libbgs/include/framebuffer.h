/*
** EPITECH PROJECT, 2022
** LIBBGS
** File description:
** framebuffer private header
*/

#ifndef LIBBGS_PRIVATE_FRAMEBUFFER_H_
    #define LIBBGS_PRIVATE_FRAMEBUFFER_H_

    #include "my_bgs_framebuffer.h"

struct element_s *add_element(framebuffer_t *buf, enum elem_data_type type,
    void (*update)(void *element, framebuffer_t *buf));

#endif
