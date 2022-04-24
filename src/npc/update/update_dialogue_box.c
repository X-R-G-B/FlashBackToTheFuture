/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** update dialog box
*/

#include <stdbool.h>
#include <stdlib.h>
#include "my_bgs.h"
#include "my_dico.h"
#include "my_rpg.h"
#include "my_strings.h"
#include "npc.h"

static void set_new_text(dialog_manager_t *dialog, text_dialog_t *text,
    window_t *win)
{
    int is_updating = false;
    player_t *player = NULL;

    if (win == NULL) {
        return;
    }
    player = dico_t_get_value(win->components, PLAYER);
    if (dialog->text == NULL) {
        is_updating = true;
    } else if (my_strcmp(dialog->text, text->str) != 0) {
        is_updating = true;
        free(dialog->text);
    }
    if (is_updating == true) {
        dialog->text = my_strdup(text->str);
    }
    if (player != NULL && text->need_pause == true) {
        player->state = IN_POP_UP;
    }
}

void update_dialog(object_t *obj, scene_t *scene,
    window_t *win,
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
    set_new_text(dialog, text, win);
}
