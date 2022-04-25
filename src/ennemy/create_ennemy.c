/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** create ennemy
*/

#include <stdlib.h>
#include "my_json.h"
#include "my_rpg.h"
#include "main_menu.h"
#include "macro.h"
#include "ennemies.h"

static int set_rect(ennemy_t *ennemy, list_ptr_t *stop_rect)
{
    int *rect = get_any_int_array(get_element_i_var(stop_rect, ennemy->dir));

    if (rect == NULL) {
        return RET_ERR_INPUT;
    }
    ennemy->obj->bigdata.sprite_bigdata.rect =
        (sfIntRect) {rect[0], rect[1], rect[2], rect[3]};
    sfSprite_setOrigin(ennemy->obj->drawable.sprite,
        (sfVector2f) {rect[2] / 2, rect[3] / 2});
    free(rect);
    return RET_OK;
}

int ennemy_set_stop(ennemy_t *ennemy)
{
    any_t *ennemy_data = NULL;
    any_t *stop_rect = NULL;

    if (ennemy == NULL || ennemy->obj == NULL) {
        return RET_ERR_INPUT;
    }
    ennemy_data = dico_t_get_value(ennemy->obj->components, ENNEMY_DATA);
    if (ennemy_data == NULL) {
        return RET_ERR_INPUT;
    }
    stop_rect = dico_t_get_any(ennemy_data->value.dict, "stop");
    if (stop_rect == NULL || stop_rect->type != ARRAY) {
        return RET_ERR_INPUT;
    }
    ennemy->state = STOP;
    return set_rect(ennemy, stop_rect->value.array);
}

static ennemy_t *add_new_ennemy_struct(scene_t *scene, object_t *obj,
    any_t *ennemy_data)
{
    ennemy_t *ennemy = malloc(sizeof(ennemy_t));
    any_t *life = dico_t_get_any(ennemy_data->value.dict, "life");

    if (ennemy == NULL || life == NULL || life->type != FLOAT) {
        return NULL;
    }
    ennemy->dir = DOWN;
    ennemy->life = life->value.f;
    ennemy->obj = obj;
    ennemy->state = STOP;
    if (add_to_ennemy_list(ennemy, scene) != RET_OK) {
        return NULL;
    }
    obj->components = dico_t_add_data(obj->components, "struct", ennemy, free);
    return (obj->components == NULL) ? NULL : ennemy;
}

static int ennemy_set_sprite(object_t *ennemy, any_t *ennemy_data,
    scene_t *scene, sfVector2f pos)
{
    any_t *sprite = dico_t_get_any(ennemy_data->value.dict, "sprite path");
    ennemy_t *ennemy_struct = NULL;

    if (sprite == NULL || sprite->type != STR) {
        list_add_to_end(scene->to_remove, ennemy);
        return RET_ERR_INPUT;
    }
    if (object_set_sprite(ennemy, sprite->value.str,
        (sfIntRect) {-1, -1, -1, -1}, pos) != BGS_OK ||
        sprite_set_change(ennemy, ennemy_data) != RET_OK) {
        list_add_to_end(scene->to_remove, ennemy);
        return RET_ERR_MALLOC;
    }
    ennemy_struct = add_new_ennemy_struct(scene, ennemy, ennemy_data);
    if (ennemy_struct == NULL || ennemy_set_stop(ennemy_struct) != RET_OK) {
        return RET_ERR_MALLOC;
    }
    ennemy_struct->obj->bigdata.sprite_bigdata.pos = pos;
    return RET_OK;
}

int create_ennemy(scene_t *scene, const char *path, sfVector2f pos)
{
    object_t *ennemy = NULL;
    any_t *ennemy_data = NULL;

    if (scene == NULL || path == NULL) {
        return RET_ERR_INPUT;
    }
    ennemy = create_object(update_ennemy, NULL, scene, LAYER_ENNEMY);
    ennemy_data = parse_json_file(path);
    if (ennemy == NULL || ennemy_data == NULL) {
        return RET_ERR_MALLOC;
    }
    ennemy->components = dico_t_add_data(ennemy->components, ENNEMY_DATA,
        ennemy_data, destroy_any);
    if (ennemy->components == NULL) {
        return RET_ERR_MALLOC;
    }
    return ennemy_set_sprite(ennemy, ennemy_data, scene, pos);
}
