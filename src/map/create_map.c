/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** create map
*/

#include "ennemies.h"
#include "my_rpg.h"
#include "my_puts.h"
#include "my_wordarray.h"
#include "my_json.h"
#include "macro.h"
#include "my_bgs_components.h"

static void (*square_updates[])(object_t *, scene_t *, window_t *, float) = {
    knockback, next_stage, activate_scale_with_height
};

static const char square_type_update[] = "pzQ";

static void get_square_update(char current_char,
    void (**update)(object_t *, scene_t *, window_t *, float))
{
    for (int i = 0; square_type_update[i] != '\0'; i++) {
        if (current_char == square_type_update[i]) {
            *update = square_updates[i];
            return;
        }
    }
    return;
}

static int init_sprite(object_t *square, any_t *path, sfVector2f current_pos,
    dico_t *square_data)
{
    any_t *rotation = dico_t_get_any(square_data, "rotation");

    if (square == NULL || object_set_sprite(square, path->value.str,
        (sfIntRect) {-1, -1, -1, -1}, current_pos) != BGS_OK) {
        my_putstr(1, "wrong square sprite path\n");
        return RET_ERR_MALLOC;
    }
    if (rotation != NULL && rotation->type == FLOAT) {
        sfSprite_setRotation(square->drawable.sprite, rotation->value.f);
    }
    return RET_OK;
}

static int init_square(scene_t *scene, char current_char, dico_t *char_type,
    sfVector2f current_pos)
{
    object_t *square = NULL;
    void (*update)(object_t *, scene_t *, window_t *, float) = NULL;
    char char_name[2] = {current_char, '\0'};
    any_t *square_data = dico_t_get_any(char_type, char_name);
    any_t *path = NULL;

    if (square_data == NULL || square_data->type != DICT) {
        return RET_ERR_INPUT;
    }
    path = dico_t_get_any(square_data->value.dict, "path");
    get_square_update(current_char, &update);
    if ((path != NULL && path->type == STR) || update != NULL) {
        square = create_object(update, NULL, scene, LAYER_MAP);
        if (square == NULL) {
            return RET_ERR_MALLOC;
        }
    }
    return (path != NULL && path->type == STR) ?
        init_sprite(square, path, current_pos,
        square_data->value.dict) : RET_OK;
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
    create_ennemy(scene, "./assets/data/ennemy/amongus.json",
        (sfVector2f) {590, 500});
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
    data = dico_t_get_any(scene->components, STAGE_DATA);
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
