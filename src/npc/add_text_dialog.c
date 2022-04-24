/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** add text dialog to all dialogue
*/

#include <stdbool.h>
#include <stdlib.h>
#include "my_bgs.h"
#include "my_dico.h"
#include "my_strings.h"
#include "my_rpg.h"
#include "npc.h"

int destroy_text_dialog(void *dialog_void, scene_t *scene, window_t *win,
    bool force_quit)
{
    text_dialog_t *dialog = dialog_void;
    player_t *player = NULL;

    if (dialog_void == NULL) {
        return (false);
    }
    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL || (player->state == IN_POP_UP &&
            dialog->need_pause == false && force_quit == false)) {
        return (false);
    }
    if (player->state == IN_POP_UP && dialog->need_pause == true) {
        set_stop(player);
    }
    if (dialog->callback != NULL && scene != NULL && win != NULL) {
        dialog->callback(dialog->str, scene, win);
    }
    free(dialog->str);
    free(dialog);
    return (true);
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
