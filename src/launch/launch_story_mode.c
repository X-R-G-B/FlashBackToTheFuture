/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** launch story mode
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_json.h"
#include "my_conversions.h"
#include "audio.h"
#include "my_strings.h"

static const char stage_path_start[] = "./assets/data/story_mode/stage_";
static const int start_len = 31;
static const char stage_path_end[] = ".json";
static const char current_stage_key[] = "current stage";
static const int end_len = 5;

static void fill_string(int number_len, char *res, char *number)
{
    for (int i = 0; i < start_len + end_len + number_len; i++) {
        if (i < start_len) {
            res[i] = stage_path_start[i];
        } else if (i >= start_len + number_len) {
            res[i] = stage_path_end[i - (start_len + number_len)];
        } else {
            res[i] = number[i - start_len];
        }
    }
}

char *get_stage_path(int current_stage)
{
    char *number = my_itoa(current_stage);
    char *res = NULL;
    int number_len = 0;

    if (number == NULL || current_stage < 0) {
        return NULL;
    }
    number_len = my_strlen(number);
    res = malloc(sizeof(char) * (start_len + end_len + number_len + 1));
    if (res == NULL) {
        return NULL;
    }
    res[start_len + end_len + number_len] = '\0';
    fill_string(number_len, res, number);
    free(number);
    return res;
}

static int init_stage(any_t *save, any_t **current_stage, char **stage_path)
{
    *current_stage = dico_t_get_any(save->value.dict, current_stage_key);
    if (*current_stage == NULL || (*current_stage)->type != INT) {
        return RET_ERR_INPUT;
    }
    *stage_path = get_stage_path((*current_stage)->value.i);
    if ((*stage_path) == NULL) {
        return RET_ERR_INPUT;
    }
    return RET_OK;
}

int launch_story_mode(window_t *win, scene_t *scene)
{
    any_t *save = NULL;
    any_t *current_stage = NULL;
    char *stage_path = NULL;
    int ret = RET_OK;

    if (win == NULL || scene == NULL) {
        return RET_ERR_INPUT;
    }
    toggle_music_in_scene(scene);
    save = dico_t_get_any(win->components, SAVE);
    if (save == NULL || save->type != DICT) {
        return RET_ERR_INPUT;
    }
    init_stage(save, &current_stage, &stage_path);
    ret = launch_stage(win, stage_path, current_stage->value.i, scene);
    free(stage_path);
    return ret;
}
