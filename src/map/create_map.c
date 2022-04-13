/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** create map
*/

#include "ennemies.h"
#include "my_rpg.h"
#include "my_wordarray.h"
#include "my_json.h"
#include "macro.h"
#include "my_bgs_components.h"

static void (*event_array_on[])(object_t *, scene_t *, window_t *,
    set_event_t *) = {
        knockback
};

static void (*event_array_off[])(object_t *, scene_t *, window_t *,
    set_event_t *);

static const char square_type_on[] = "r";

static const char square_type_off[] = "\0";

static int square_set_event(object_t *square, char current_char)
{
    void (*event_on)(object_t *, scene_t *, window_t *, set_event_t*) = NULL;
    void (*event_off)(object_t *, scene_t *, window_t *, set_event_t*) = NULL;

    for (int i = 0; square_type_on[i] != '\0' && event_on != NULL; i++) {
        if (current_char == square_type_on[i]) {
            event_on = event_array_on[i];
        }
    }
    for (int i = 0; square_type_off[i] != '\0' && event_off != NULL; i++) {
        if (current_char == square_type_off[i]) {
            event_off = event_array_off[i];
        }
    }
    
    if (event_on != NULL || event_off != NULL) {
        if (event_add_node(create_event()))
    }
}

static int init_square(scene_t *scene, char current_char, dico_t *char_type,
    sfVector2f current_pos)
{
    object_t *square = NULL;
    char char_name[2] = {current_char, '\0'};
    any_t *square_data = dico_t_get_any(char_type, char_name);

    if (square_data == NULL || square_data->type != DICT) {
        return RET_ERR_INPUT;
    }
    any_t *path = dico_t_get_any(square_data->value.dict, "path");
    if (path == NULL || path->type != STR) {
        return RET_OK;
    }
    square = create_object(NULL, NULL, scene, PLAN_MAP);
    if (square == NULL || object_set_sprite(square, path->value.str,
        (sfIntRect) {-1, -1, -1, -1}, current_pos) != BGS_OK ||
        square_set_event(square, current_char) != RET_OK) {
        return RET_ERR_MALLOC;
    }
    return RET_OK;
}

static int browse_squares_pos(scene_t *scene, char **map, dico_t *char_type)
{
    sfVector2f current_pos = {SQUARE_SIZE / 2.0, SQUARE_SIZE / 2.0};
    int ret = RET_OK;

    for (int i = 0; map[i] != NULL && ret == RET_OK; i++) {
        for (int x = 0; map[i][x] != '\0' && ret == RET_OK; x++) {
            ret = init_square(scene, map[i][x], char_type, current_pos);
            current_pos.x += SQUARE_SIZE;
        }
        current_pos.x = SQUARE_SIZE / 2.0;
        current_pos.y += SQUARE_SIZE;
    }
    my_wordarray_free(map);
    create_amongus(scene, 500, 500);
    return ret;
}

int create_map(scene_t *scene)
{
    any_t *data = NULL;
    any_t *char_type = NULL;
    char **map = NULL;

    if (scene == NULL) {
        return RET_ERR_INPUT;
    }
    data = dico_t_get_any(scene->components, SAVE);
    if (data == NULL) {
        return RET_ERR_MALLOC;
    }
    map = get_any_string_array(get_from_any(data, "dd", "map data", "map"));
    char_type = get_from_any(data, "dd", "map data", "char type");
    if (char_type == NULL || char_type->type != DICT || map == NULL) {
        return RET_ERR_INPUT;
    }
    return browse_squares_pos(scene, map, char_type->value.dict);
}
