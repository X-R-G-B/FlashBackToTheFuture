/*
** EPITECH PROJECT, 2022
** defender
** File description:
** object add solid components
*/

#include <stdlib.h>
#include "my_bgs.h"
#include "my_bgs_components.h"
#include "libbgs_private.h"

static void free_list_abstract(void *list_ptr)
{
    free_list((list_ptr_t *) list_ptr);
}

int scene_add_solid_list(scene_t *scene)
{
    void *value = NULL;

    value = dico_t_get_value(scene->components, ON_COLLISION);
    if (value == NULL) {
        scene->components = dico_t_add_data(scene->components, ON_COLLISION,
            list_create(), &free_list_abstract);
        if (scene->components == NULL) {
            return BGS_ERR_MALLOC;
        }
    }
    return BGS_OK;
}

void free_col(void *data)
{
    on_collision_t *collision = data;

    if (collision == NULL) {
        return;
    }
    dico_t_destroy(collision->collisions_dico);
    free(collision);
}

list_ptr_t *create_square_list(object_t *object)
{
    list_ptr_t *list = list_create();
    char **arr = NULL;

    if (object->type != SPRITE) {
        return NULL;
    }
    arr = check_image_pixel(object->bigdata.sprite_bigdata.image);
    if (squares_handling(arr, list) != BGS_OK) {
        return NULL;
    }
    return list;
}

int object_add_collision(object_t *object, scene_t *scene,
    void (*collision)(object_t *this, object_t *other, scene_t *scene,
    window_t *win), bool is_pixel)
{
    on_collision_t *on_collision = NULL;

    if (object == NULL || scene == NULL ||
        (object->type != SPRITE && object->type != TEXT)) {
        return BGS_ERR_INPUT;
    }
    on_collision = malloc(sizeof(on_collision_t));
    if (on_collision == NULL) {
        return BGS_ERR_MALLOC;
    }
    get_id_generator(on_collision->key);
    on_collision->is_pixel = is_pixel;
    on_collision->solid_squares = create_square_list(object);
    on_collision->collision = collision;
    on_collision->collisions_dico = NULL;
    if (scene_add_solid_list(scene) != BGS_OK || list_add_to_end(
        dico_t_get_value(scene->components, ON_COLLISION), object) == NULL) {
        return BGS_ERR_MALLOC;
    }
    return object_add_components(object, on_collision, ON_COLLISION, free_col);
}
