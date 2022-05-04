/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** add text from json
*/

#include <stdlib.h>
#include "my_bgs.h"
#include "my_json.h"
#include "my_wordarray.h"
#include "my_puts.h"
#include "npc.h"
#include "my_rpg.h"

static int add_text_dialog_itter(scene_t *scene, any_t *json)
{
    char **arr_text = NULL;
    char *tmp = NULL;
    arr_text = get_any_string_array(get_from_any(json, "d", "dialogus"));

    if (arr_text == NULL) {
        my_putstr(1, "need 'dialogus' element array of string");
        return (RET_ERR_INPUT);
    }
    for (int i = 0; arr_text[i] != NULL; i++) {
        tmp = parseprety(arr_text[i]);
        if (tmp == NULL) {
            my_wordarray_free(arr_text);
            return (RET_ERR_MALLOC);
        }
        add_text_dialog(scene, tmp, false, NULL);
        free(tmp);
    }
    my_wordarray_free(arr_text);
    return (RET_OK);
}

int add_text_dialog_json(scene_t *scene, const char *path)
{
    any_t *json = NULL;
    char **arr_text = NULL;
    int status = 0;

    if (scene == NULL || path == NULL) {
        return (RET_ERR_INPUT);
    }
    json = parse_json_file(path);
    if (json == NULL) {
        return (RET_ERR_MALLOC);
    }
    status = add_text_dialog_itter(scene, json);
    my_wordarray_free(arr_text);
    destroy_any(json);
    return (status);
}
