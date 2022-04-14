/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** launch_next_stage
*/

#include "my_rpg.h"
#include "my_json.h"

static int increment_current_stage_data(any_t *save)
{
    any_t *current_stage = dico_t_get_any(save, "current stage");

    if (current_stage == NULL || current_stage->type != INT) {
        return -1;
    }
    current_stage->value.i += 1;
    if (write_json(save, STORY_DATA_PATH) != JS_OK) {
        return -1;
    }
    return current_stage->value.i;
}

static int create_new_scene(char *stage_path, char *stage_name, window_t *win)
{
    scene_t *scene = NULL;
    any_t *stage_data = NULL;

    if (stage_name == NULL || stage_path == NULL) {
        return RET_ERR_INPUT;
    }
    stage_data = parse_json_file(stage_path);
    scene = create_scene(win, sfBlack, stage_name);
    if (scene == NULL || stage_data == NULL) {
        return RET_ERR_MALLOC;
    }
    scene->components = dico_t_add_data(scene, STAGE_DATA, stage_data,
        destroy_any);
    if (scene->components == NULL) {
        return RET_ERR_MALLOC;
    }
    free(stage_name);
    free(stage_path);
    return RET_OK;
}

int launch_next_stage(window_t *win)
{
    scene_t *current_scene = NULL;
    any_t *save = NULL;
    int new_stage = -1;

    if (win == NULL) {
        return RET_ERR_INPUT;
    }
    save = dico_t_get_any(win->components, SAVE);
    current_scene = dico_t_get_value(win->components, win->current_scene);
    if (current_scene == NULL || save == NULL) {
        return RET_ERR_INPUT;
    }
    new_stage = increment_current_stage_data(save);
    list_add_to_end(win->to_remove, current_scene);
    return create_new_scene(get_stage_path(new_stage),
        get_stage_name(new_stage), win);
}
