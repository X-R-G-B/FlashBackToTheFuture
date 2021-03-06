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
#include "my_json.h"
#include "my_strings.h"
#include "my_wordarray.h"
#include "npc.h"
#include "player.h"

static float time_until_destroy = 0.2;

static player_t *check_if_legit(text_dialog_t *dialog, bool force_quit,
    window_t *win)
{
    player_t *player = NULL;

    if (dialog == NULL || (dialog->time < time_until_destroy &&
            force_quit == false)) {
        return (NULL);
    }
    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL || (player->state == IN_POP_UP &&
            dialog->need_pause == false && force_quit == false)) {
        return (NULL);
    }
    return (player);
}

int destroy_text_dialog(void *dialog_void, scene_t *scene, window_t *win,
    bool force_quit)
{
    text_dialog_t *dialog = dialog_void;
    player_t *player = NULL;

    player = check_if_legit(dialog, force_quit, win);
    if (player == NULL) {
        return (false);
    }
    if (player->state == IN_POP_UP && dialog->need_pause == true) {
        set_stop(player);
    }
    if (dialog->callback != NULL && scene != NULL && win != NULL) {
        dialog->callback(dialog->str, scene, win, dialog->data);
    }
    if (dialog->str) {
        free(dialog->str);
    }
    free(dialog);
    return (true);
}

static void fill_dialog_text(text_dialog_t *text_d, const char *str,
    bool need_pause,
    void (*callback)(const char *str, scene_t *scene,
    window_t *win, void *data))
{
    text_d->callback = callback;
    text_d->need_pause = need_pause;
    text_d->str = parseprety(str);
    text_d->time = 0;
    text_d->data = NULL;
}

text_dialog_t *add_text_dialog(window_t *win, const char *text,
    bool need_pause,
    void (*callback)(const char *str, scene_t *scene,
    window_t *win, void *data))
{
    dialog_manager_t *dialog = NULL;
    list_t *text_d = NULL;

    if (win == NULL || text == NULL) {
        return NULL;
    }
    dialog = dico_t_get_value(win->components, compo_dialog);
    if (dialog == NULL) {
        return NULL;
    }
    text_d = list_add_to_end(dialog->dialogues, malloc(sizeof(text_dialog_t)));
    if (text_d == NULL) {
        return NULL;
    }
    fill_dialog_text(text_d->var, text, need_pause, callback);
    return text_d->var;
}
