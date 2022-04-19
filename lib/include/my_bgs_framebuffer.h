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
    #include <SFML/Graphics/Sprite.h>
    #include <SFML/Graphics/Texture.h>
    #include <SFML/System/Vector2.h>
    #include <stdbool.h>
    #include "list.h"

typedef struct elem_circle_s elem_circle_t;
typedef struct elem_rect_s elem_rect_t;
typedef struct elem_line_s elem_line_t;
typedef struct window_s window_t;

struct elem_circle_s {
    sfVector2f center;
    unsigned int radius;
    sfColor color;
    bool is_plain;
};

struct elem_rect_s {
    sfFloatRect rect;
    bool is_plain;
    sfColor color;
};

struct elem_line_s {
    sfVector2f point_a;
    sfVector2f point_b;
    sfColor color;
};

typedef struct framebuffer_s framebuffer_t;

struct framebuffer_s {
    sfUint8 *pixels;
    unsigned int width;
    unsigned int height;
    sfVector2f pos_on_win;
    sfTexture *texture;
    sfSprite *sprite;
    list_ptr_t *to_remove;
    struct element_s {
        struct element_s *next;
        void (*update)(struct element_s *element, framebuffer_t *buf,
            float dtime);
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

/**
** @brief draw framebuffer to window
**
** @param win window in which to draw
** @param buf the framebuffer to draw
**
** @return {
** BGS_ERR_INPUT : win or buf is NULL,
** BGS_OK : framebuffer has been drawn
** }
**/
int draw_framebuffer(window_t *win, framebuffer_t *buf);

/**
** @brief update all elements on the framebuffer
**
** @param buf framebuffer to update
** @param dtime delta time between last update
**
** @return {
** BGS_ERR_INPUT : buf is NULL,
** BGS_OK : framebuffer has been updated
** }
**/
int update_framebuffer(framebuffer_t *buf, float dtime);

int fb_add_circle(
    framebuffer_t *buf,
    elem_circle_t circle_info,
    void (*update)(struct element_s *element, framebuffer_t *buf, float dtime)
);

int fb_add_line(
    framebuffer_t *buf,
    elem_line_t line_info,
    void (*update)(struct element_s *element, framebuffer_t *buf, float dtime)
);

int fb_add_rect(
    framebuffer_t *buf,
    elem_rect_t rect_info,
    void (*update)(struct element_s *element, framebuffer_t *buf, float dtime)
);

#endif
