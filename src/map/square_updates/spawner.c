/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** spawner
*/

#include "ennemies.h"

static const char ennemy_path_key[] = "ennemy path";
static const char ennemy[] = "ennemy";

static void check_init(object_t *obj, char *ennemy_path, scene_t *scene)
{
    ennemy_t *ennemy = dico_t_get_value(obj->components, ennemy);
    list_ptr_t *spawner_list = NULL;

    if (ennemy == NULL && init_ennemy(obj, ennemy_path) != RET_OK) {
        return;
    }
    spawner_list = dico_t_get_value(scene->)
}

void update_spawner(object_t *obj, scene_t *scene, window_t *win,
    float time)
{
    char *ennemy_path = NULL;

    if (obj == NULL || scene == NULL || win == NULL) {
        return;
    }
    ennemy_path = dico_t_get_value(obj->components, ennemy_path_key);
    if (ennemy_path == NULL) {
        return;
    }
    check_init_ennemy(obj, ennemy_path, scene);
}