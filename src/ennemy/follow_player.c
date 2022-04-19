/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** follow player
*/

#include "my_bgs.h"
#include "ennemy_pathfind.h"
#include "ennemies.h"
#include "my_dico.h"
#include "my_rpg.h"

int follow_player(object_t *obj, scene_t *scene, float dtime)
{
    dir_t current = UNKNOWN_STATE;
    sfVector2f move[4] = {{0, -1 * dtime}, {-1 * dtime, 0}, {0, 1 * dtime},
        {1 * dtime, 0}};

    if (obj == NULL || scene == NULL) {
        return (RET_ERR_INPUT);
    }
    current = get_path_find_dir(obj, scene);
    if (current == UNKNOWN_STATE) {
        return (RET_ERR_INPUT);
    }
    obj->bigdata.sprite_bigdata.pos.x += move[current].x * SPEED_ENN_AMONGUS;
    obj->bigdata.sprite_bigdata.pos.y += move[current].y * SPEED_ENN_AMONGUS;
    return (RET_OK);
}
