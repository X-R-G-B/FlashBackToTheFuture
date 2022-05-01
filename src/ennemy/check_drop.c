/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** check drop
*/

#include <stdlib.h>
#include "ennemies.h"
#include "math.h"

static const char drop_rate_key[] = "drop rate";

static bool check_drop_chance(ennemy_t *ennemy)
{
    any_t *ennemy_data = NULL;
    any_t *drop_rate = NULL;

    if (ennemy == NULL) {
        return false;
    }
    ennemy_data = dico_t_get_value(ennemy->obj->components, ENNEMY_DATA);
    drop_rate = get_from_any(ennemy_data, "d", drop_rate_key);
    if (drop_rate == NULL || drop_rate->type != FLOAT) {
        return false;
    }
    if (randomise(0, 100) <= drop_rate->value.f) {
        return true;
    }
    return false;
}

static void update_86(object_t *obj, scene_t *scene, window_t *win, float dtime)
{
    player_t *player = NULL;

    if (obj == NULL || scene == NULL || win == NULL) {
        return;
    }
    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL) {
        return;
    }
    
}

static void create_86(ennemy_t *ennemy)
{
    object_t *obj = create_object()
}

void check_drop(ennemy_t *ennemy)
{
    if (check_drop_chance(ennemy) == false) {
        return;
    }
    create_86(ennemy);
}