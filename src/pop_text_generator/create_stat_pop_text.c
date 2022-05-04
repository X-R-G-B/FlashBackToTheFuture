/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** create stat pop text
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_conversions.h"
#include "my_strings.h"

int create_stat_pop_text_from_window(window_t *win, int stat, const char *path,
    sfVector2f pos)
{
    scene_t *scene = NULL;

    if (win == NULL) {
        return RET_ERR_INPUT;
    }
    scene = dico_t_get_value(win->scenes, win->current_scene);
    if (scene == NULL) {
        return RET_ERR_INPUT;
    }
    return create_stat_pop_text(scene, stat, path, pos);
}

static char *add_pos_sign(char *text)
{
    int len = my_strlen(text);
    char *new = NULL;

    if (len < 0) {
        return NULL;
    }
    new = malloc(sizeof(char) * len + 1);
    if (new == NULL) {
        return NULL;
    }
    new[0] = '+';
    new[1] = '\0';
    new = my_strcat(new, text);
    free(text);
    return new;
}

int create_stat_pop_text(scene_t *scene, int stat, const char *path,
    sfVector2f pos)
{
    char *text = NULL;
    int ret = RET_OK;

    if (scene == NULL || path == NULL) {
        return RET_ERR_INPUT;
    }
    text = my_itoa(stat);
    if (text == NULL) {
        return RET_ERR_MALLOC;
    }
    if (text[0] != '-') {
        text = add_pos_sign(text);
        if (text == NULL) {
            return RET_ERR_MALLOC;
        }
    }
    ret = create_pop_text(scene, path, pos, text);
    free(text);
    return ret;
}
