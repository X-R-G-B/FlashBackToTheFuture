/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** stage_map_to_collision_array.c
*/

#include "my_rpg.h"
#include "my_wordarray.h"
#include "my_json.h"

char **stage_map_to_collision_array(scene_t *scene)
{
    any_t *stage_data = NULL;
    any_t *map = NULL;
    char **stage_map = NULL;

    if (scene == NULL) {
        return NULL;
    }
    stage_data = dico_t_get_any(scene->components, SAVE);
    if (stage_data == NULL) {
        return NULL;
    }
    map = get_from_any(stage_data, "dd", "map data", "map");
    if (map == NULL || map->type != ARRAY) {
        return NULL;
    }
    stage_map = get_any_string_array(map);
    if (stage_map == NULL) {
        return NULL;
    }
    return stage_map;
}
