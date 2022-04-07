/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** create map
*/

#include "my_rpg.h"
#include "my_json.h"

int create_map(scene_t *scene)
{
    any_t *data = NULL;
    any_t *char_type = NULL;
    any_t *map = NULL;

    if (scene == NULL) {
        return RET_ERR_INPUT;
    }
    data = dico_t_get_any(scene->components, SAVE);
    if (data == NULL) {
        return RET_ERR_MALLOC;
    }
    map = get_from_any(data, "dd", "map data", "map");
    char_type = get_from_any(data, "dd", "map data", "char type");
    if (char_type == NULL || char_type->type != DICT || map == NULL ||
        map->type != ARRAY) {
        return RET_ERR_INPUT;
    }
}