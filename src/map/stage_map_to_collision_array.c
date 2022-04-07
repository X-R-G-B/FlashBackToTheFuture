/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** stage_map_to_collision_array.c
*/

#include "my_rpg.h"
#include "my_wordarray.h"
#include "my_strings.h"
#include "my_json.h"

static char check_char_type(any_t *char_dict)
{
    any_t *collision = dico_t_get_any(char_dict->value.dict, "col");

    if (collision == NULL || collision->type != INT ||
        collision->value.i == 0) {
        return '.';
    } else {
        return '#';
    }
}

static int fill_current_string(char **map, int i, any_t *char_type, char **new)
{
    char current_char[2] = {'\0', '\0'};
    int str_len = my_strlen(map[i]);
    any_t *char_dict = NULL;

    for (int x = 0; x < str_len; x++) {
        current_char[0] = map[i][x];
        char_dict = dico_t_get_any(char_type->value.dict, current_char);
        if (char_dict == NULL && map[i][x] != ' ') {
            return RET_ERR_INPUT;
        } else if (map[i][x] == ' ') {
            new[i][x] = '#';
        } else {
            new[i][x] = check_char_type(char_dict);
        }
    }
    return RET_OK;
}

static void get_right_char(char **map, any_t *char_type, scene_t *scene)
{
    int arr_len = my_wordarray_len(map);
    char **new = create_new_map(map);

    if (char_type == NULL || char_type->type != DICT || new == NULL) {
        if (new != NULL) {
            my_wordarray_free(new);
        }
        return NULL;
    }
    for (int i = 0; i < arr_len; i++) {
        fill_current_string(map, i, char_type, new);
    }
    scene->components = dico_t_add_data(scene->components, COLLISION_ARRAY,
        new, my_wordarray_free);
}

void add_collision_array_in_scene(scene_t *scene)
{
    any_t *stage_data = NULL;
    any_t *map = NULL;
    char **stage_map = NULL;

    if (scene == NULL) {
        return;
    }
    stage_data = dico_t_get_any(scene->components, SAVE);
    map = get_from_any(stage_data, "dd", "map data", "map");
    if (map == NULL || map->type != ARRAY) {
        return;
    }
    stage_map = get_any_string_array(map);
    if (stage_map == NULL) {
        return;
    }
    get_right_char(stage_map, get_from_any(stage_data, "dd", "map data",
        "char type"), scene);
    my_wordarray_free(stage_map);
}
