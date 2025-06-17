/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** init and update the making of
*/

#include <SFML/Graphics/Rect.h>
#include <SFML/System/Vector2.h>
#include <stdbool.h>
#include <stdlib.h>
#include "main_menu.h"
#include "my_wordarray.h"
#include "my_bgs.h"
#include "my_dico.h"
#include "my_json.h"
#include "my_rpg.h"
#include "macro.h"

static const char index_image_compo[] = "index_image_compo";

static const char compo_number_images[] = "compo_number images";

static const char path_images_json[] = "./assets/data/menu/making_of_data.json";

static const char elem_json_paths[] = "paths";

static const float update_time_clock = 1.0;

static const sfVector2f pos_images = {
    WIN_SIZE_X - (1 / 3.0 * WIN_SIZE_X),
    WIN_SIZE_Y / 2.0
};

static bool check_pop_up_true(dico_t *dico, const char *key)
{
    list_t *elem = NULL;
    list_ptr_t *list = dico_t_get_value(dico, key);

    if (list == NULL) {
        return (false);
    }
    elem = list->start;
    if (elem == NULL || elem->var == NULL) {
        return (false);
    }
    if (((object_t *) elem->var)->is_visible == true) {
        return (true);
    }
    return (false);
}

static void update_manager_making(object_t *obj, scene_t *scene, window_t *win,
    float dtime)
{
    static float time_update = 0;
    dico_t *curr = NULL;

    if (obj == NULL || scene == NULL || win == NULL) {
        return;
    }
    time_update += dtime;
    if (time_update < update_time_clock) {
        return;
    }
    time_update -= update_time_clock;
    curr = dico_t_get_elem(scene->components, index_image_compo);
    if (curr == NULL) {
        return;
    }
    curr->value = (void *) ((int) curr->value + 1);
    curr->value = (void *) ((int) curr->value % (int) dico_t_get_value(
        scene->components, compo_number_images));
}

static void update_images(object_t *obj, scene_t *scene, window_t *win,
    __attribute__((unused)) float dtime)
{
    int index_our_image = 0;
    int index_curr_image = 0;

    if (obj == NULL || scene == NULL || win == NULL) {
        return;
    }
    index_curr_image = (int) dico_t_get_value(scene->components,
        index_image_compo);
    index_our_image = (int) dico_t_get_value(obj->components,
        index_image_compo);
    if (index_curr_image != index_our_image ||
            check_pop_up_true(win->components, SETTINGS_MENU) == true ||
            check_pop_up_true(scene->components, PLAY) == true) {
        obj->is_visible = false;
    } else {
        obj->is_visible = true;
    }
}

static int init_all_images(scene_t *scene, const char *path_root)
{
    any_t *json = NULL;
    char **arr = NULL;
    sfIntRect rect = {-1, -1, -1, -1};
    object_t *obj = NULL;

    json = parse_json_file(resolve_path(path_root, path_images_json));
    if (json == NULL) {
        return (RET_ERR_MALLOC);
    }
    arr = get_any_string_array(get_from_any(json, "d", elem_json_paths));
    for (int i = 0; arr != NULL && arr[i] != NULL; i++) {
        obj = create_object(update_images, NULL, scene, 2);
        object_set_sprite(obj, arr[i], rect, pos_images, path_root);
        object_add_components(obj, (void *) i, index_image_compo, NULL);
    }
    scene_add_components(scene, (void *) my_wordarray_len(arr),
        compo_number_images, NULL);
    my_wordarray_free(arr);
    destroy_any(json);
    return (RET_OK);
}

int init_making_of(scene_t *scene, const char *path_root)
{
    dico_t *dict = NULL;

    if (scene == NULL) {
        return (RET_ERR_INPUT);
    }
    if (object_set_custom(create_object(update_manager_making, NULL,
            scene, LAYER_HUD)) != BGS_OK) {
        return (RET_ERR_MALLOC);
    }
    if (scene_add_components(scene, (void *) 1, index_image_compo, NULL) !=
            BGS_OK) {
        return (RET_ERR_MALLOC);
    }
    dict = dico_t_get_elem(scene->components, index_image_compo);
    if (dict == NULL) {
        return (RET_ERR_INPUT);
    }
    dict->value = NULL;
    init_all_images(scene, path_root);
    return (RET_OK);
}
