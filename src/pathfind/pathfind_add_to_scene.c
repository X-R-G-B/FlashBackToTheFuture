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
#include <SFML/System/Vector2.h>

static sfVector2i get_player_pos_in_map(object_t *obj)
{
    sfVector2f pos = obj->bigdata.sprite_bigdata.pos;
    int pos_y = pos.y + (obj->bigdata.sprite_bigdata.rect.height / 2.0);

    return (sfVector2i) {pos.x / SQUARE_SIZE, pos_y / SQUARE_SIZE};
}

int pathfind_add_to_scene(scene_t *scene, object_t *obj)
{
    char **collision_array = NULL;
    char tmp = '\0';
    sfVector2i vect = {0};

    if (scene == NULL || obj == NULL) {
        return (RET_ERR_INPUT);
    }
    collision_array = dico_t_get_value(scene->components, COLLISION_ARRAY);
    if (collision_array == NULL) {
        return (RET_ERR_INPUT);
    }
    vect = get_player_pos_in_map(obj);
    tmp = collision_array[vect.y][vect.x];
    collision_array[vect.y][vect.x] = 'P';
    init_pathfind(collision_array, '#', 'P', scene);
    collision_array[vect.y][vect.x] = tmp;
    return (RET_OK);
}
