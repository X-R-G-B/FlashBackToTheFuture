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
#include "my_strings.h"

static const char stage_path_start[] = "./assets/data/story_mode/stage_";
static const int start_len = 31;
static const char stage_path_end[] = ".json";
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

static char *get_stage_path(int current_stage)
{
    char *number = my_itoa(current_stage);
    char *res = NULL;
    int number_len = 0;

    if (number == NULL) {
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

int launch_story_mode(window_t *win, const char save_path[])
{
    any_t *save = parse_json_file(save_path);
    any_t *current_stage = NULL;
    char *stage_path = NULL;

    if (save == NULL) {
        printf("save path: %s\n", save_path);
        return RET_ERR_INPUT;
    }
    current_stage = dico_t_get_any(save->value.dict, "current stage");
    win->components = dico_t_add_data(win->components, SAVE, save,
        destroy_any);
    if (win->components == NULL || current_stage == NULL ||
        current_stage->type != INT) {
        return RET_ERR_INPUT;
    }
    stage_path = get_stage_path(current_stage->value.i);
    if (stage_path == NULL) {
        return RET_ERR_INPUT;
    }
    return launch_stage(win, stage_path, current_stage->value.i);
}
