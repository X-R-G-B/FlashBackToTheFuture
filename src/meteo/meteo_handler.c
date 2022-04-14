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
#include <SFML/Graphics/View.h>
#include <stdlib.h>

int (*add_elems_func[4])(window_t *win, int x) = {
    NULL,
    add_leaf,
    add_snow,
    add_sun
};

void update_meteo_handler(__attribute__((unused)) object_t *obj,
   __attribute__((unused))  scene_t *scene, window_t *win,
    float dtime)
{
    static float time_spaw = 0;
    struct meteo_rpg_s *meteo = NULL;
    float pos = 0;

    time_spaw += dtime;
    if (time_spaw > 1 / 3.0) {
        meteo = dico_t_get_value(win->components, METEO_HANDLER_COMP);
        if (meteo == NULL) {
            return;
        }
        if (add_elems_func[meteo->type_now] != NULL) {
            pos = rand() % (int) win->buf->width;
            printf("%f\n", pos);
            add_elems_func[meteo->type_now](win, pos);
        }
        time_spaw -= 1 / 3.0;
    }
    return;
}
