/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** spawner
*/

#include "ennemies.h"

static const char ennemy_path_key[] = "ennemy path";

static void destroy_ennemy_cast(void *data)
{
    scene_t *scene = NULL;
    ennemy_t *ennemy = NULL;

    if (data == NULL) {
        return;
    }
    ennemy = data;
    if (ennemy->obj == NULL) {
        return;
    }
    scene = dico_t_get_value(ennemy->obj->components, SCENE);
    destroy_ennemy(ennemy, scene);
}

static int init_ennemy(object_t *obj, char *ennemy_path, scene_t *scene)
{
    ennemy_t *ennemy = create_ennemy(scene, ennemy_path,
        obj->bigdata.sprite_bigdata.pos);
    printf("create ennemy %s\n", ennemy_path);

    if (ennemy == NULL) {
        return RET_ERR_MALLOC;
    }
    obj->components = dico_t_add_data(obj->components, ENNEMY_KEY, ennemy,
        destroy_ennemy_cast);
    return (obj->components == NULL) ? RET_ERR_MALLOC : RET_OK;
}

static void check_is_obj_in_list(list_ptr_t *spawner_list, object_t *obj)
{
    list_t *elem = spawner_list->start;
    bool is_in_list = false;

    for (int i = 0; i < spawner_list->len; i++, elem = elem->next) {
        if (elem->var == obj) {
            is_in_list = true;
        }
    }
    if (is_in_list == false) {
        list_add_to_end(spawner_list, obj);
    }
}

static list_ptr_t *init_spawner_list(scene_t *scene)
{
    list_ptr_t *spawner_list = list_create();

    if (spawner_list == NULL) {
        return NULL;
    }
    scene->components = dico_t_add_data(scene->components, SPAWNER_LIST,
        spawner_list, free_pop_up);
    return (scene->components == NULL) ? NULL : spawner_list;
}

static void check_init(object_t *obj, char *ennemy_path, scene_t *scene)
{
    ennemy_t *ennemy = dico_t_get_value(obj->components, ENNEMY_KEY);
    list_ptr_t *spawner_list = NULL;

    if (ennemy == NULL && init_ennemy(obj, ennemy_path, scene) != RET_OK) {
        return;
    }
    spawner_list = dico_t_get_value(scene->components, SPAWNER_LIST);
    if (spawner_list == NULL) {
        spawner_list = init_spawner_list(scene);
        if (spawner_list == NULL) {
            return;
        }
    }
    check_is_obj_in_list(spawner_list, obj);
}

void update_spawner(object_t *obj, scene_t *scene, window_t *win,
    __attribute__((unused)) float time)
{
    char *ennemy_path = NULL;

    if (obj == NULL || obj->type != SPRITE || scene == NULL || win == NULL) {
        return;
    }
    ennemy_path = dico_t_get_value(obj->components, ennemy_path_key);
    if (ennemy_path == NULL) {
        return;
    }
    check_init(obj, ennemy_path, scene);
}
