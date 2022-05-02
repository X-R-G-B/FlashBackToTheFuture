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
#include "meteo.h"
#include "my_bgs_button_generator.h"
#include "ennemy_pathfind.h"
#include "audio.h"
#include "npc.h"

static const int back_color[] = {51, 136, 238};

static const char stage_name_start[] = "stage_";

static const int start_len = 6;

char *get_stage_name(int stage_id)
{
    char *number = my_itoa(stage_id);
    int number_len = 0;
    char *res = NULL;

    if (number == NULL || stage_id < 0) {
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

scene_t *init_scene(const char *stage_path, window_t *win, char *stage_name)
{
    any_t *data = NULL;
    scene_t *scene = NULL;

    data = parse_json_file(stage_path);
    scene = create_scene(win, sfColor_fromRGB(back_color[0], back_color[1],
        back_color[2]), stage_name);
    if (data == NULL || scene == NULL) {
        return NULL;
    }
    scene->components = dico_t_add_data(scene->components, STAGE_DATA, data,
        destroy_any);
    if (scene->components == NULL) {
        return NULL;
    }
    create_meteo_handler(win, scene);
    return scene;
}

static int init_new_scene_objects(window_t *win, scene_t *scene)
{
    if (create_map(scene) != RET_OK ||
        create_player(win, scene, PLAYER_STATS_PATH) == NULL ||
        init_hud_elements(win, scene) != RET_OK ||
        add_collision_array_in_scene(scene) != RET_OK ||
        init_dialog(scene) != RET_OK ||
        add_npc(scene, json_magician, &callback_magician) != RET_OK ||
        init_stat_upgrade_pop_up(scene,
        dico_t_get_value(win->components, HUD_ELEMENTS), win) != RET_OK ||
        create_inventory(win) != RET_OK) {
        return RET_ERR_MALLOC;
    }
    return (scene->components == NULL) ? RET_ERR_MALLOC : RET_OK;
}

int launch_stage(window_t *win, const char *stage_path, int stage_id,
    scene_t *prev_scene)
{
    scene_t *scene = NULL;
    char *stage_name = get_stage_name(stage_id);

    scene = init_scene(stage_path, win, stage_name);
    if (scene == NULL || move_object_between_scene(win, prev_scene,
        scene) != RET_OK || init_new_scene_objects(win, scene) != RET_OK) {
        return RET_ERR_MALLOC;
    }
    if (window_change_scene(win, stage_name) != BGS_OK) {
        free(stage_name);
        return RET_ERR_INPUT;
    }
    free(stage_name);
    return RET_OK;
}
