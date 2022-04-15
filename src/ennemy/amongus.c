/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** create among us adn destroy it
*/

#include "ennemy_pathfind.h"
#include "my_bgs.h"
#include "my_bgs_components.h"
#include "my_dico.h"
#include "macro.h"
#include "my_json.h"
#include "my_conversions.h"
#include "ennemies.h"
#include <SFML/System/Vector2.h>

static const char ennemy_among_us[] = "ENNEMY_AMONG_US";
static const char ennemy_among_us_json[] = "./assets/json/amongus.json";
static const char ennemy_among_us_png[] = "./assets/amongus.png";

static const float time_max = 1 / 5.0;

static int update_among_us_time(any_t *dico, float dtime)
{
    any_t *value = get_from_any(dico, "d", "time");

    if (value == NULL || value->type != FLOAT) {
        return (0);
    }
    value->value.f += dtime;
    if (value->value.f < time_max) {
        return (0);
    }
    value->value.f -= time_max;
    return (1);
}

static void update_among_us(object_t *obj,
        __attribute__((unused)) scene_t *scn, window_t *win,
        float dtime)
{
    int update = 0;
    any_t *dico = dico_t_get_value(obj->components, ennemy_among_us);

    if (dico == NULL) {
        return;
    }
    update = update_among_us_time(dico, dtime);
    if (update == 0) {
        return;
    }
    change_amongus_rect(dico, obj, win);
    follow_player(obj, scn, dtime);
}

int create_amongus(scene_t *scene, int pos_x, int pos_y)
{
    object_t *obj = NULL;
    sfVector2f pos = {pos_x, pos_y};

    if (scene == NULL) {
        return (BGS_ERR_INPUT);
    }
    obj = create_object(update_among_us, NULL, scene, PLAN_ENNEMY);
    if (obj == NULL) {
        return (BGS_ERR_MALLOC);
    }
    if (object_set_sprite(obj, ennemy_among_us_png,
            (sfIntRect) {-1, -1, -1, -1}, pos) != BGS_OK ||
        object_add_components(obj, parse_json_file(ennemy_among_us_json),
            ennemy_among_us, &destroy_any) != BGS_OK) {
        return (BGS_ERR_MALLOC);
    }
    sfSprite_setScale(obj->drawable.sprite, (sfVector2f) {2, 2});
    return (BGS_OK);
}
