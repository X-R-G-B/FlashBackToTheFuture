/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** init the meteo
*/

#include <stdlib.h>
#include "list.h"
#include "meteo.h"
#include "my_bgs.h"
#include "my_bgs_components.h"
#include "my_bgs_framebuffer.h"
#include "my_dico.h"
#include "macro.h"

static struct meteo_rpg_s *create_meteo(void)
{
    struct meteo_rpg_s *meteo = NULL;

    meteo = malloc(sizeof(struct meteo_rpg_s));
    if (meteo == NULL) {
        return (NULL);
    }
    meteo->type_now = DEFAULT_METEO;
    return (meteo);
}

static int create_meteo_obj(scene_t *scene, window_t *win)
{
    object_t *obj = NULL;
    list_ptr_t *list_hud = NULL;

    if (win == NULL) {
        return (RET_ERR_INPUT);
    }
    list_hud = dico_t_get_value(win->components, HUD_ELEMENTS);
    if (list_hud == NULL) {
        return (RET_ERR_MALLOC);
    }
    obj = create_object(update_meteo_handler, NULL, scene, 50);
    if (object_set_custom(obj)) {
        return (RET_ERR_MALLOC);
    }
    list_add_to_end(list_hud, obj);
    return (RET_OK);
}

static void destroy_meteo(void *meteo_void)
{
    struct meteo_rpg_s *meteo = meteo_void;

    if (meteo_void == NULL) {
        return;
    }
    free(meteo);
}

int create_meteo_handler(window_t *win, scene_t *scene)
{
    struct meteo_rpg_s *meteo = NULL;

    if (win == NULL || scene == NULL) {
        return (RET_ERR_INPUT);
    }
    if (dico_t_get_value(win->components, METEO_HANDLER_COMP) != NULL) {
        return RET_OK;
    }
    meteo = create_meteo();
    if (meteo == NULL) {
        return (RET_ERR_MALLOC);
    }
    if (window_add_component(win, meteo, METEO_HANDLER_COMP,
            destroy_meteo) != BGS_OK) {
        destroy_meteo(meteo);
        return (RET_ERR_MALLOC);
    }
    create_meteo_obj(scene, win);
    return (RET_OK);
}
