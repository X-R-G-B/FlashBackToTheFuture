/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** add particle to position
*/

#include <SFML/Graphics/Color.h>
#include <SFML/System/Vector2.h>
#include <stdbool.h>
#include <stdlib.h>
#include "my_macro.h"
#include "my_bgs.h"
#include "my_bgs_framebuffer.h"
#include "my_json.h"
#include "my_rpg.h"

sfVector2i vectors[][2] = {
    {{.x = 0, .y = 0}, {.x = 0, .y = 2}},
    {{.x = 0, .y = 0}, {.x = -2, .y = 0}},
    {{.x = 0, .y = 0}, {.x = 0, .y = -2}},
    {{.x = 0, .y = 0}, {.x = 2, .y = 0}},
    {{.x = 0, .y = 0}, {.x = -1, .y = 1}},
    {{.x = 0, .y = 0}, {.x = -1, .y = -1}},
    {{.x = 0, .y = 0}, {.x = 1, .y = -1}},
    {{.x = 0, .y = 0}, {.x = 1, .y = 1}},
    {{.x = 0, .y = 0}, {.x = -1, .y = 2}},
    {{.x = 0, .y = 0}, {.x = -2, .y = 1}},
    {{.x = 0, .y = 0}, {.x = -2, .y = -1}},
    {{.x = 0, .y = 0}, {.x = -1, .y = -2}},
    {{.x = 0, .y = 0}, {.x = 1, .y = -2}},
    {{.x = 0, .y = 0}, {.x = 2, .y = -1}},
    {{.x = 0, .y = 0}, {.x = 2, .y = 1}},
    {{.x = 0, .y = 0}, {.x = 1, .y = 2}},
    {{.x = 0, .y = 0}, {.x = 0, .y = 0}}
};

static bool check_end_vectors(int i)
{
    if (vectors[i][0].x == vectors[i][1].x &&
        vectors[i][0].y == vectors[i][1].y) {
        return (true);
    }
    return (false);
}

static void update_line_gore(struct element_s *elem, framebuffer_t *buf,
    float dtime)
{
    sfVector2f vect = {0};
    static float time_f = 0.0;

    if (elem == NULL || buf == NULL) {
        return;
    }
    time_f += dtime;
    vect = (sfVector2f) {
        .x = elem->data.line.point_b.x - elem->data.line.point_a.x,
        .y = elem->data.line.point_b.y - elem->data.line.point_a.y
    };
    elem->data.line.point_b.y += (int) MAX(((vect.y) * (dtime * 100)) / 3, 1);
    elem->data.line.point_b.x += (int) MAX(((vect.x) * (dtime * 100)) / 3, 1);
    elem->data.line.point_a.y += (int) MAX(((vect.y) * (dtime * 100)) / 3, 1);
    elem->data.line.point_a.x += (int) MAX(((vect.x) * (dtime * 100)) / 3, 1);
    if (time_f > 1.0) {
        list_add_to_start(buf->to_remove, elem);
        time_f -= 1.0;
    }
}

int add_gore_sword(window_t *win, sfVector2f pos)
{
    elem_line_t line = {0};

    if (win == NULL) {
        return (RET_ERR_INPUT);
    }
    for (int i = 0; check_end_vectors(i) == false; i++) {
        line.point_b.x = pos.x + vectors[i][1].x;
        line.point_b.y = pos.y + vectors[i][1].y;
        line.point_a.x = pos.x + vectors[i][0].x;
        line.point_a.y = pos.y + vectors[i][0].y;
        line.color = sfColor_fromRGBA(230 + rand() % 25, 0, 0, 255);
        fb_add_line(win->buf, line, &update_line_gore);
    }
    return (RET_OK);
}
