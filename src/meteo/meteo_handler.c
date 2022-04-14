/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** create meteo with the currrent meteo
*/

#include "my_bgs.h"
#include "my_bgs_framebuffer.h"
#include "meteo.h"
#include "my_dico.h"
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/View.h>
#include <stdlib.h>

int (*add_elems_func[4])(window_t *win, int x) = {
    NULL,
    add_leaf,
    add_snow,
    add_sun
};

static void set_view_particle(window_t *win)
{
    const sfView *view = NULL;
    sfVector2f vec = {0};

    view = sfRenderWindow_getView(win->win);
    if (view == NULL) {
        return;
    }
    vec.x = sfView_getCenter(view).x - (sfView_getSize(view).x / 2);
    vec.y = sfView_getCenter(view).y - (sfView_getSize(view).y / 2);
    win->buf->pos_on_win = vec;
}

static void execute_function(window_t *win, struct meteo_rpg_s *meteo)
{
    int pos = 0;

    if (meteo->type_now < 0 || meteo->type_now > 3) {
        return;
    }
    if (add_elems_func[meteo->type_now] == NULL) {
        return;
    }
    pos = rand() % (int) win->buf->width;
    add_elems_func[meteo->type_now](win, pos);
}

void update_meteo_handler(__attribute__((unused)) object_t *obj,
    __attribute__((unused)) scene_t *scene, window_t *win,
    float dtime)
{
    static float time_spaw = 0;
    struct meteo_rpg_s *meteo = NULL;

    if (win == NULL) {
        return;
    }
    set_view_particle(win);
    time_spaw += dtime;
    if (time_spaw > 1 / 3.0) {
        meteo = dico_t_get_value(win->components, METEO_HANDLER_COMP);
        if (meteo == NULL) {
            return;
        }
        execute_function(win, meteo);
        time_spaw -= 1 / 3.0;
    }
    return;
}
