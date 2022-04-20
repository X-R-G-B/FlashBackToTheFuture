/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** launch_next_stage
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_json.h"

static const int back_color[] = {51, 136, 238};

static int increment_current_stage_data(any_t *save)
{
    any_t *current_stage = dico_t_get_any(save->value.dict, "current stage");

    if (current_stage == NULL || current_stage->type != INT) {
        return -1;
    }
    current_stage->value.i += 1;
    if (write_json(save, STORY_DATA_PATH) != JS_OK) {
        return -1;
    }
    return current_stage->value.i;
}

static int create_scene_objects(window_t *win, scene_t *prev_scene,
    scene_t *scene)
{
    int *spawn = NULL;
    player_t *player = dico_t_get_value(win->components, "player");

    if (move_object_between_scene(win, prev_scene, scene) != RET_OK ||
        create_map(scene) != RET_OK ||
        add_collision_array_in_scene(scene) != RET_OK) {
        return RET_ERR_MALLOC;
    }
    spawn = get_player_spawn(scene);
    if (player == NULL || spawn == NULL) {
        return RET_ERR_INPUT;
    }
    player->obj->bigdata.sprite_bigdata.pos = (sfVector2f) {spawn[0], spawn[1]};
    free(spawn);
    return RET_OK;
}

static int create_new_scene(char *stage_path, char *stage_name, window_t *win,
    scene_t *prev_scene)
{
    scene_t *scene = NULL;
    any_t *stage_data = NULL;

    if (stage_name == NULL || stage_path == NULL) {
        return RET_ERR_INPUT;
    }
    stage_data = parse_json_file(stage_path);
    scene = create_scene(win, sfColor_fromRGB(back_color[0], back_color[1],
        back_color[2]), stage_name);
    free(stage_path);
    if (scene == NULL || window_change_scene(win, stage_name) != BGS_OK ||
        stage_data == NULL) {
        free(stage_name);
        return RET_ERR_MALLOC;
    }
    free(stage_name);
    scene->components = dico_t_add_data(scene->components, STAGE_DATA,
        stage_data, destroy_any);
    return (scene->components == NULL) ? RET_ERR_MALLOC :
        create_scene_objects(win, prev_scene, scene);
}

int launch_next_stage(window_t *win)
{
    scene_t *current_scene = NULL;
    any_t *save = NULL;
    int new_stage = -1;

    if (win == NULL) {
        return RET_ERR_INPUT;
    }
    launch_scene_loading(win, "SCENE_LOADING_BASIC");
    save = dico_t_get_any(win->components, SAVE);
    current_scene = dico_t_get_value(win->scenes, win->current_scene);
    if (current_scene == NULL || save == NULL) {
        return RET_ERR_INPUT;
    }
    new_stage = increment_current_stage_data(save);
    if (new_stage < 0) {
        return RET_ERR_INPUT;
    }
    list_add_to_end(win->to_remove, current_scene);
    return create_new_scene(get_stage_path(new_stage),
        get_stage_name(new_stage), win, current_scene);
}
