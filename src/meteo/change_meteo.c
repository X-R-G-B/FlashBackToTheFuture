/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** change the meteo
*/

#include "my_bgs.h"
#include "my_bgs_components.h"
#include "meteo.h"
#include "my_bgs_framebuffer.h"
#include "my_dico.h"
#include "my_rpg.h"

int change_meteo(window_t *win, enum meteo_type_e type)
{
    struct meteo_rpg_s *meteo = NULL;

    if (win == NULL) {
        return (RET_ERR_INPUT);
    }
    meteo = dico_t_get_value(win->components, METEO_HANDLER_COMP);
    if (meteo == NULL) {
        return (RET_ERR_INPUT);
    }
    meteo->type_now = type;
    return (RET_OK);
}
