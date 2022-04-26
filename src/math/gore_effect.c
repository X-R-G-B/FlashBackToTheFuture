/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** add particle to position
*/

#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/View.h>
#include <SFML/System/Vector2.h>
#include <stdbool.h>
#include <stdlib.h>
#include "my_macro.h"
#include "my_bgs.h"
#include "my_bgs_framebuffer.h"
#include "my_json.h"
#include "my_rpg.h"

sfVector2i vectors[][2] = {
    {{.x = 0, .y = 0}, {.x = 0, .y = 8}},
    {{.x = 0, .y = 0}, {.x = -8, .y = 0}},
    {{.x = 0, .y = 0}, {.x = 0, .y = -8}},
    {{.x = 0, .y = 0}, {.x = 8, .y = 0}},
    {{.x = 0, .y = 0}, {.x = -4, .y = 4}},
    {{.x = 0, .y = 0}, {.x = -4, .y = -4}},
    {{.x = 0, .y = 0}, {.x = 4, .y = -4}},
    {{.x = 0, .y = 0}, {.x = 4, .y = 4}},
    {{.x = 0, .y = 0}, {.x = -4, .y = 8}},
    {{.x = 0, .y = 0}, {.x = -8, .y = 4}},
    {{.x = 0, .y = 0}, {.x = -4, .y = -4}},
    {{.x = 0, .y = 0}, {.x = -4, .y = -8}},
    {{.x = 0, .y = 0}, {.x = 4, .y = -8}},
    {{.x = 0, .y = 0}, {.x = 8, .y = -4}},
    {{.x = 0, .y = 0}, {.x = 8, .y = 4}},
    {{.x = 0, .y = 0}, {.x = 4, .y = 8}},
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

    if (elem == NULL || buf == NULL) {
        return;
    }
    vect = (sfVector2f) {
        .x = elem->data.line.point_b.x - elem->data.line.point_a.x,
        .y = elem->data.line.point_b.y - elem->data.line.point_a.y
    };
    elem->data.line.point_b.y += (int) (((vect.y) * (dtime * 100)) / 3.0);
    elem->data.line.point_b.x += (int) (((vect.x) * (dtime * 100)) / 3.0);
    elem->data.line.point_a.y += (int) (((vect.y) * (dtime * 100)) / 3.0);
    elem->data.line.point_a.x += (int) (((vect.x) * (dtime * 100)) / 3.0);
    if (elem->data.line.point_b.x - 100 > WIN_SIZE_X / 2.0 ||
        elem->data.line.point_b.y - 100 > WIN_SIZE_Y / 2.0 ||
        elem->data.line.point_b.x + 100 < WIN_SIZE_X / 2.0 ||
        elem->data.line.point_b.y + 100 < WIN_SIZE_Y / 2.0) {
        list_add_to_start(buf->to_remove, elem);
    }
}

static sfVector2i calcul_right_pos(const sfView *view, sfVector2f pos)
{
    sfVector2f center = {0};
    sfVector2f size = {0};
    sfVector2i calc = {0};

    if (view == NULL) {
        return (calc);
    }
    center = sfView_getCenter(view);
    size = sfView_getSize(view);
    calc.x = (int) pos.x - (int) center.x + (int) (size.x / 2);
    calc.y = (int) pos.y - (int) center.y + (int) (size.y / 2);
    return (calc);
}

int add_gore_sword(window_t *win, sfVector2f pos)
{
    elem_line_t line = {0};
    const sfView *view = NULL;
    sfVector2i offset = {0};

    if (win == NULL) {
        return (RET_ERR_INPUT);
    }
    view = sfRenderWindow_getView(win->win);
    offset = calcul_right_pos(view, pos);
    for (int i = 0; check_end_vectors(i) == false; i++) {
        line.point_a.x = offset.x + vectors[i][0].x;
        line.point_a.y = offset.y + vectors[i][0].y;
        line.point_b.x = offset.x + vectors[i][1].x;
        line.point_b.y = offset.y + vectors[i][1].y;
        line.color = sfColor_fromRGBA(230 + rand() % 25, 0, 0, 255);
        fb_add_line(win->buf, line, &update_line_gore);
    }
    return (RET_OK);
}
