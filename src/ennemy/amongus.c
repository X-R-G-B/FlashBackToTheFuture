/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** create among us adn destroy it
*/

#include "my_bgs.h"
#include "my_bgs_components.h"
#include "my_dico.h"
#include "macro.h"
#include "my_json.h"
#include "my_conversions.h"
#include "ennemies.h"

static const char ennemy_among_us[] = "ENNEMY_AMONG_US";
static const char ennemy_among_us_json[] = "./assets/json/amongus.json";
static const char ennemy_among_us_png[] = "./assets/amongus.png";

static const float time_max = 1 / 5.0;

static void update_among_us_time(object_t *obj, any_t *dico, float dtime,
        window_t *win)
{
    any_t *value = get_from_any(dico, "d", "time");

    value->value.f += dtime;
    if (value->value.f < time_max) {
        return;
    }
    value->value.f -= time_max;
    change_amongus_rect(dico, obj, win);
}

static void update_among_us(object_t *obj,
        __attribute__((unused)) scene_t *scn, window_t *win,
        float dtime)
{
    any_t *dico = dico_t_get_value(obj->components, ennemy_among_us);

    update_among_us_time(obj, dico, dtime, win);
}

int create_amongus(scene_t *scene, int pos_x, int pos_y)
{
    object_t *obj = NULL;
    sfVector2f pos = {pos_x, pos_y};

    if (scene == NULL) {
        return (BGS_ERR_INPUT);
    }
    obj = create_object(update_among_us, NULL, scene, PLAN_ENNEMY);
    object_set_sprite(obj, ennemy_among_us_png, (sfIntRect) {-1, -1, -1, -1},
            pos);
    object_add_components(obj, parse_json_file(ennemy_among_us_json),
            ennemy_among_us, &destroy_any);
    return (BGS_OK);
}
