/*
** EPITECH PROJECT, 2022
** LIBBGS
** File description:
** header for framebuffer
*/

#ifndef MY_BGS_FRAMEBUFFER_H_
    #define MY_BGS_FRAMEBUFFER_H_

    #include <SFML/Config.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/System/Vector2.h>
    #include <stdbool.h>
    #include "list.h"

typedef struct elem_circle_s elem_circle_t;
typedef struct elem_rect_s elem_rect_t;
typedef struct elem_line_s elem_line_t;

struct elem_circle_s {
    sfVector2f center;
    unsigned int radius;
    sfColor color;
    bool is_plain;
};

struct elem_rect_s {
    sfFloatRect rect;
    bool is_plain;
};

struct elem_line_s {
    sfVector2f point_a;
    sfVector2f point_b;
};

typedef struct framebuffer_s framebuffer_t;

struct framebuffer_s {
    sfUint8 *pixels;
    unsigned int width;
    unsigned int height;
    sfVector2f pos_on_win;
    struct element_s {
        struct element_s *next;
        enum elem_data_type {
            CIRCLE,
            RECT,
            LINE
        } type;
        union elem_data_s {
            elem_circle_t circle;
            elem_rect_t rect;
            elem_line_t line;
        } data;
    } *elements;
};

/**
** @brief create a framebuffer
**
** @param width width of the frame buffer
** @param height height of the frame buffer
**
** @return {
** NULL : width or height is 0,
** NULL : malloc failed,
** framebuffer_t *: framebuffer has been created
** }
**/
framebuffer_t *create_framebuffer(
    unsigned int width,
    unsigned int height,
    sfVector2f pos_on_win
);

/**
** @brief put a color everywhere on the framebuffer
**
** @param buf framebuffer to clear
** @param color color to put
**
** @return {
** BGS_ERR_INPUT : buf is NULL,
** BGS_OK : buf has been cleared
** }
**/
int clear_framebuffer(framebuffer_t *buf, sfColor color);


/**
** @brief destroy a framebuffer
**
** @param buf framebuffer to destroy
**/
void destroy_framebuffer(framebuffer_t *buf);

#endif
