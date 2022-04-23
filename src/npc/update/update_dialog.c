/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** update dialog
*/

#include <stdbool.h>
#include <stdlib.h>
#include <SFML/Graphics/Text.h>
#include "list.h"
#include "my_rpg.h"
#include "my_strings.h"
#include "my_bgs.h"
#include "my_dico.h"
#include "npc.h"

extern const char compo_dialog[];

static void set_new_text(dialog_manager_t *dialog, text_dialog_t *text)
{
    int is_updating = false;

    if (dialog->text == NULL) {
        is_updating = true;
    } else if (my_strcmp(dialog->text, text->str) != 0) {
        is_updating = true;
        free(dialog->text);
    }
    if (is_updating == true) {
        dialog->text = my_strdup(text->str);
    }
}

int add_text_dialog(scene_t *scene, const char *text, bool need_pause,
    void (*callback)(const char *str, scene_t *scene, window_t *win))
{
    dialog_manager_t *dialog = NULL;
    list_t *text_d = NULL;

    if (scene == NULL || text == NULL) {
        return (RET_ERR_INPUT);
    }
    dialog = dico_t_get_value(scene->components, compo_dialog);
    if (dialog == NULL) {
        return (RET_ERR_INPUT);
    }
    text_d = list_add_to_end(dialog->dialogues, malloc(sizeof(text_dialog_t)));
    if (text_d == NULL) {
        return (RET_ERR_MALLOC);
    }
    ((text_dialog_t *) text_d->var)->str = my_strdup(text);
    ((text_dialog_t *) text_d->var)->need_pause = need_pause;
    ((text_dialog_t *) text_d->var)->callback = callback;
    return (RET_OK);
}

void update_text_dialog(object_t *obj, scene_t *scene,
    __attribute((unused)) window_t *win,
    __attribute((unused)) float dtime)
{
    static char *tmp = NULL;
    dialog_manager_t *dialog = NULL;

    if (scene == NULL || obj == NULL || scene->pause == true) {
        return;
    }
    dialog = dico_t_get_value(scene->components, compo_dialog);
    if (dialog == NULL || dialog->dialogues == NULL ||
            dialog->dialogues->len <= 0) {
        obj->is_visible = false;
        return;
    }
    if (tmp == dialog->text || tmp == NULL) {
        return;
    }
    obj->is_visible = true;
    tmp = dialog->text;
    sfText_setString(obj->drawable.text, tmp);
}

void update_dialog(object_t *obj, scene_t *scene,
    __attribute__((unused)) window_t *win,
    __attribute__((unused)) float dtime)
{
    dialog_manager_t *dialog = NULL;
    text_dialog_t *text = NULL;

    if (scene == NULL || obj == NULL || scene->pause == true) {
        return;
    }
    dialog = dico_t_get_value(scene->components, compo_dialog);
    if (dialog == NULL || dialog->dialogues == NULL ||
            dialog->dialogues->len <= 0) {
        obj->is_visible = false;
        return;
    }
    obj->is_visible = true;
    text = dialog->dialogues->start->var;
    set_new_text(dialog, text);
}
