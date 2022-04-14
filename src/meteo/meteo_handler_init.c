/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** init the meteo
*/

#include "meteo.h"
#include "my_bgs.h"
#include "my_bgs_components.h"
#include "my_bgs_framebuffer.h"
#include "my_rpg.h"
#include <stdlib.h>

static struct meteo_rpg_s *create_meteo(void)
{
    struct meteo_rpg_s *meteo = NULL;

    meteo = malloc(sizeof(struct meteo_rpg_s));
    if (meteo == NULL) {
        return (NULL);
    }
    meteo->type_now = LEAF;
    return (meteo);
}

static int create_meteo_obj(scene_t *scene)
{
    object_t *obj = NULL;

    obj = create_object(update_meteo_handler, NULL, scene, 50);
    if (obj == NULL) {
        return (RET_ERR_MALLOC);
    }
    object_set_custom(obj);
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
//    struct meteo_rpg_s *meteo = NULL;
//
//    if (win == NULL) {
//        return (RET_OK);
//    }
//    meteo = create_meteo();
//    if (meteo == NULL) {
//        return (RET_ERR_MALLOC);
//    }
//    printf("oki\n");
//    if (window_add_component(win, meteo, METEO_HANDLER_COMP,
//            destroy_meteo) != BGS_OK) {
//        printf("okino\n");
//        destroy_meteo(meteo);
//        return (RET_ERR_MALLOC);
//    }
//    create_meteo_obj(scene);
    return (RET_OK);
}
