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
static const char path_images_json[] =
    "./assets/data/menu/making_of_data.json";
static const char elem_json_paths[] = "paths";

static float time_update_frame = 1;

static const sfVector2f pos_images = {
    WIN_SIZE_X - (1 / 3.0 * WIN_SIZE_X),
    WIN_SIZE_Y / 2.0
};

static bool check_pop_up_true(dico_t *dico, char *key)
{
    list_t *elem = NULL;
    list_ptr_t *list = dico_t_get_value(dico, key);

    if (list == NULL) {
        return (false);
    }
    elem = list->start;
    if (((object_t *) elem->var)->is_visible == true) {
        return (true);
    }
    return (false);
}

static void update_manager_making(object_t *obj, scene_t *scene, window_t *win,
    float dtime)
{
    static float time_update = 0;
    int *index_curr_image = NULL;

    if (obj == NULL || scene == NULL || win == NULL) {
        return;
    }
    time_update += dtime;
    if (time_update < time_update_frame) {
        return;
    }
    time_update -= time_update_frame;
    index_curr_image = dico_t_get_value(scene->components, index_image_compo);
    if (index_curr_image == NULL) {
        return;
    }
    *index_curr_image = *index_curr_image + 1;
}

static void update_images(object_t *obj, scene_t *scene, window_t *win,
    __attribute__((unused)) float dtime)
{
    int index_our_image = 0;
    int *index_curr_image = NULL;

    if (obj == NULL || scene == NULL || win == NULL) {
        return;
    }
    index_curr_image = dico_t_get_value(scene->components, index_image_compo);
    if (index_curr_image == NULL) {
        return;
    }
    index_our_image = (int) dico_t_get_value(obj->components,
        index_image_compo);
    if (*index_curr_image != index_our_image ||
            check_pop_up_true(win->components, SETTINGS_MENU) == true ||
            check_pop_up_true(scene->components, PLAY) == true) {
        obj->is_visible = false;
    } else {
        obj->is_visible = true;
    }
}

static int init_all_images(scene_t *scene)
{
    any_t *json = NULL;
    char **arr = NULL;
    sfIntRect rect = {-1, -1, -1, -1};
    object_t *obj = NULL;

    json = parse_json_file(path_images_json);
    if (json == NULL) {
        return (RET_ERR_MALLOC);
    }
    arr = get_any_string_array(get_from_any(json, "d", elem_json_paths));
    if (arr != NULL) {
        for (int i = 0; arr[i] != NULL; i++) {
            obj = create_object(update_images, NULL, scene, 2);
            object_set_sprite(obj, arr[i], rect, pos_images);
            object_add_components(obj, (void *) i, index_image_compo, NULL);
        }
    }
    my_wordarray_free(arr);
    destroy_any(json);
    return (RET_OK);
}

int init_making_of(scene_t *scene)
{
    int *index_image = NULL;

    if (scene == NULL) {
        return (RET_ERR_INPUT);
    }
    if (object_set_custom(create_object(update_manager_making, NULL,
            scene, LAYER_HUD)) != BGS_OK) {
        return (RET_ERR_MALLOC);
    }
    index_image = malloc(sizeof(int));
    if (index_image == NULL) {
        return (RET_ERR_MALLOC);
    }
    *index_image = 0;
    if (scene_add_components(scene, index_image, index_image_compo, free)) {
        return (RET_ERR_MALLOC);
    }
    init_all_images(scene);
    return (RET_OK);
}
