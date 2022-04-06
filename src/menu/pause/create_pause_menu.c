/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** create pause menu
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_json.h"
#include "my_bgs.h"

static const char button_path[] = "./assets/data/menu/pause.json";
static const char data_path[] = "./assets/data/menu/pressed.json";

static int button_set_rect(object_t *obj, any_t *file, int *rect, int *origin)
{
    obj->components = dico_t_add_data(obj->components, "data", file,
        destroy_any);
    if (obj->components == NULL) {
        return RET_ERR_MALLOC;
    }
    obj->bigdata.sprite_bigdata.rect = (sfIntRect) {rect[0], rect[1], rect[2],
        rect[3]};
    sfSprite_setOrigin(obj->drawable.sprite, (sfVector2f) {origin[0],
        origin[1]});
    return RET_OK;
}

static list_ptr_t *browse_list(list_ptr_t *list, int *rect, int *origin,
    any_t *json)
{
    any_t *file = NULL;
    int ret = RET_OK;
    list_t *elem = NULL;

    elem = list->start->next;
    for (int i = 1; i < list->len && ret == RET_OK; i++, elem = elem->next) {
        file = parse_json_file(data_path);
        if (file == NULL) {
            return NULL;
        }
        ret = button_set_rect(elem->var, file, rect, origin);
    }
    free(rect);
    free(origin);
    destroy_any(json);
    return list;
}

list_ptr_t *create_pause_menu(scene_t *scene)
{
    list_ptr_t *list = NULL;
    any_t *file = parse_json_file(data_path);
    any_t *data = NULL;
    int *rect = NULL;
    int *origin = NULL;

    list = create_button(scene, button_path);
    if (list == NULL || file == NULL) {
        return NULL;
    }
    data = dico_t_get_any(file->value.dict, "off");
    if (data == NULL) {
        return NULL;
    }
    rect = get_any_int_array(data->value.array->start->var);
    origin = get_any_int_array(data->value.array->end->var);
    if (rect == NULL || origin == NULL) {
        return NULL;
    }
    return browse_list(list, rect, origin, file);
}
