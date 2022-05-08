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
#include "macro.h"

static int itter_add_text(window_t *win, char *const *arr_text,
    void (*callback)(const char *str, scene_t *scene, window_t *win,
    void *data), void *data)
{
    text_dialog_t *text_dialog = NULL;
    char *tmp = NULL;

    for (int i = 0; arr_text[i] != NULL; i++) {
        tmp = parseprety(arr_text[i]);
        if (tmp == NULL) {
            return RET_ERR_MALLOC;
        }
        text_dialog = add_text_dialog(win, tmp, true, NULL);
        free(tmp);
    }
    if (text_dialog != NULL) {
        text_dialog->callback = callback;
        text_dialog->data = data;
    } else {
        my_putstr(2, "error text dialog add");
    }
    return (RET_OK);
}

static int add_text_dialog_itter(window_t *win, any_t *json,
    void (*callback)(const char *str, scene_t *scene, window_t *win,
    void *data), void *data)
{
    char **arr_text = NULL;
    arr_text = get_any_string_array(get_from_any(json, "d", "dialogus"));
    int status = 0;

    if (arr_text == NULL) {
        my_putstr(2, "need 'dialogus' element array of string");
        return RET_ERR_INPUT;
    }
    if (arr_text[0] == NULL) {
        return (RET_ERR_INPUT);
    }
    status = itter_add_text(win, arr_text, callback, data);
    my_wordarray_free(arr_text);
    return (status);
}

int add_text_dialog_json(window_t *win, const char *path,
    void (*callback)(const char *str, scene_t *scene, window_t *win,
        void *data), void *data)
{
    any_t *json = NULL;
    char **arr_text = NULL;

    if (win == NULL || path == NULL) {
        return RET_ERR_INPUT;
    }
    json = parse_json_file(path);
    if (json == NULL) {
        return RET_ERR_INPUT;
    }
    add_text_dialog_itter(win, json, callback, data);
    my_wordarray_free(arr_text);
    destroy_any(json);
    return RET_OK;
}
