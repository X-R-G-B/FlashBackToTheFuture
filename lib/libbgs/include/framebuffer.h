/*
** EPITECH PROJECT, 2022
** LIBBGS
** File description:
** framebuffer private header
*/

#ifndef LIBBGS_PRIVATE_FRAMEBUFFER_H_
    #define LIBBGS_PRIVATE_FRAMEBUFFER_H_

    #include "my_bgs_framebuffer.h"

struct element_s *add_element(
    framebuffer_t *buf,
    enum elem_data_type type,
    void (*update)(struct element_s *element, framebuffer_t *buf, float dtime)
);

int fb_put_pixel(framebuffer_t *buf, sfVector2f pos, sfColor color);

int draw_circle_pixel(
    sfVector2f pos,
    elem_circle_t *circle,
    framebuffer_t *buf
);

int draw_line_pixel(
    sfVector2f pos,
    int calc_values[2],
    framebuffer_t *buf,
    sfColor color
);

int draw_rect_pixel(sfVector2f pos, elem_rect_t rect, framebuffer_t *buf);

int is_out_of_range(sfVector2f pos, int width, int height);

#endif
