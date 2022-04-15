/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** pathfind add to scene
*/

#include "ennemy_pathfind.h"
#include "my_bgs.h"
#include "my_dico.h"
#include "my_rpg.h"

int pathfind_add_to_scene(scene_t *scene)
{
    char **collision_array = NULL;

    if (scene == NULL) {
        return (RET_ERR_INPUT);
    }
    collision_array = dico_t_get_value(scene->components, COLLISION_ARRAY);
    if (collision_array == NULL) {
        return (RET_ERR_INPUT);
    }
    init_pathfind(collision_array, '#', '#', scene);
}
