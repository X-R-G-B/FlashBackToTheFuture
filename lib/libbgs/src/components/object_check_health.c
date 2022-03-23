/*
** EPITECH PROJECT, 2022
** defender
** File description:
** object check health
*/

#include "my_bgs.h"
#include "my_bgs_components.h"

void object_check_health(object_t *object, scene_t *scene,
    window_t *win)
{
    sprite_health_t *health = NULL;

    if (object == NULL || win == NULL) {
        return;
    }
    health = dico_t_get_value(object->components, COMP_HEALTH);
    if (health == NULL) {
        return;
    }
    if (health->life <= 0 && health->is_alive == true) {
        health->is_alive = false;
        health->dead(object, scene, win);
    }
}
