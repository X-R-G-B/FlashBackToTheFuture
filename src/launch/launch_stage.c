/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** launch stage
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_conversions.h"
#include "my_strings.h"

static char stage_name_start[] = "stage_";
static int start_len = 6;

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

int launch_stage(window_t *win, char *stage_path, int stage_id)
{
    scene_t *scene = NULL;
    char *stage_name = get_stage_name(stage_id);

    if (stage_name == NULL) {
        return RET_ERR_INPUT;
    }
    scene = create_scene(win, sfBlack, stage_name);
    if (scene == NULL) {
        return RET_ERR_MALLOC;
    }
    create_player(win, scene, PLAYER_DATA);
    free(stage_path);
    if (window_change_scene(win, stage_name) != BGS_OK) {
        return RET_ERR_INPUT;
    }
    free(stage_name);
    return RET_OK;
}
