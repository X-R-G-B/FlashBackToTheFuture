/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** launch stage
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_conversions.h"
#include "main_menu.h"
#include "my_strings.h"
#include "my_bgs_button_generator.h"

static char stage_name_start[] = "stage_";
static int start_len = 6;

static void click_pause(__attribute__((unused)) object_t *obj, scene_t *scene,
    window_t *win, __attribute__((unused)) set_event_t *evt)
{
    player_t *player = dico_t_get_value(win->components, "player");

    if (player == NULL) {
        return;
    }
    scene->pause = (scene->pause == true) ? false : true;
    set_stop(player);
    toggle_pop_up(win->components, "pause");
}

static char *get_stage_name(int stage_id)
{
    char *number = my_itoa(stage_id);
    int number_len = 0;
    char *res = NULL;

    if (number == NULL) {
        return NULL;
    }
    number_len = my_strlen(number);
    res = malloc(sizeof(char) * (number_len + start_len + 1));
    if (res == NULL) {
        return NULL;
    }
    res[number_len + start_len] = '\0';
    for (int i = 0; i < number_len + start_len; i++) {
        res[i] = (i < start_len) ? stage_name_start[i] : number[i - start_len];
    }
    free(number);
    return res;
}

static int temp_pause_button(window_t *win, list_ptr_t *pause_menu,
    scene_t *scene)
{
    object_t *object = create_object(NULL, NULL, scene, 0);
    int ret = RET_OK;

    if (object == NULL ||
        object_set_sprite(object,
            "./assets/image/menu/main_menu/default_screen/Retour_button.png",
        (sfIntRect) {-1, -1, -1, -1}, (sfVector2f) {50, 50}) != BGS_OK) {
        return RET_ERR_INPUT;
    }
    object->is_visible = false;
    win->components = dico_t_add_data(win->components, "pause",
        pause_menu, free_pop_up);
    ret = event_add_node(create_event(NULL, true, object, click_pause),
        (node_params_t) {sfMouseLeft, sfKeyA, MOUSE});
    if (win->components == NULL || ret != RET_OK) {
        return RET_ERR_MALLOC;
    }
    toggle_pop_up(win->components, "pause");
    return event_add_node(create_event(NULL, false, object, click_pause),
        (node_params_t) {sfMouseLeft, sfKeyEscape, KEY});
}

static scene_t *init_scene(char *stage_path, window_t *win, char *stage_name)
{
    any_t *data = parse_json_file(stage_path);
    scene_t *scene = create_scene(win, sfBlack, stage_name);

    if (data == NULL || scene == NULL) {
        return NULL;
    }
    scene->components = dico_t_add_data(scene->components, SAVE, data,
        destroy_any);
    if (scene->components == NULL) {
        return NULL;
    }
    return scene;
}

int launch_stage(window_t *win, char *stage_path, int stage_id)
{
    scene_t *scene = NULL;
    list_ptr_t *pause_menu = NULL;
    char *stage_name = get_stage_name(stage_id);

    scene = init_scene(stage_path, win, stage_name);
    if (scene == NULL || create_player(win, scene, PLAYER_DATA) == NULL ||
        create_map(scene) != RET_OK ||
        add_collision_array_in_scene(scene) != RET_OK) {
        return RET_ERR_MALLOC;
    }
    pause_menu = create_pause_menu(scene);
    if (window_change_scene(win, stage_name) != BGS_OK ||
        temp_pause_button(win, pause_menu, scene) != RET_OK ||
        init_dead_menu(win, scene) != RET_OK) {
        return RET_ERR_INPUT;
    }
    free(stage_path);
    free(stage_name);
    return RET_OK;
}
