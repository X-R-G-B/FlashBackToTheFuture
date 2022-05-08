/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** change the meteo with data in json
*/

#include "my_bgs.h"
#include "my_dico.h"
#include "my_strings.h"
#include "my_json.h"
#include "my_rpg.h"
#include "meteo.h"

static const char *meteos_keys[] = {
    "sun", "SUN",
    "snow", "SNOW",
    "leaf", "LEAF",
    NULL
};

static const enum meteo_type_e meteos_value[] = {
    SUN, SUN,
    SNOW, SNOW,
    LEAF, LEAF
};

int change_meteo_to_json(window_t *win, scene_t *scene)
{
    any_t *meteo = NULL;
    any_t *stage_data = NULL;

    if (scene == NULL || win == NULL) {
        return (RET_ERR_INPUT);
    }
    stage_data = dico_t_get_value(scene->components, STAGE_DATA);
    meteo = get_from_any(stage_data, "d", "meteo");
    if (meteo == NULL || meteo->type != STR) {
        return (RET_OK);
    }
    for (int i = 0; meteos_keys[i] != NULL; i++) {
        if (my_strcmp(meteos_keys[i], meteo->value.str) == 0) {
            change_meteo(win, meteos_value[i]);
        }
    }
    return (RET_OK);
}
