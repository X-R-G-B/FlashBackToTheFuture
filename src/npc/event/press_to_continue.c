/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** pass to next dialog on press A
*/

#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Mouse.h>
#include <stdbool.h>
#include "list.h"
#include "my_bgs.h"
#include "my_bgs_components.h"
#include "my_dico.h"
#include "my_rpg.h"
#include "npc.h"

static const sfKeyCode key_next = sfKeyA;
extern const char bool_check_key[];

void event_next_dialog_off(__attribute__((unused)) object_t *obj,
    scene_t *scene, window_t *win,
    __attribute__((unused)) set_event_t *event)
{
    dialog_manager_t *dialog = NULL;

    if (scene == NULL || scene->pause == true) {
        return;
    }
    dialog = dico_t_get_value(scene->components, compo_dialog);
    if (dialog == NULL || dialog->dialogues == NULL ||
            dialog->dialogues->len <= 0 || dialog->dialogues->start == NULL) {
        obj->components = dico_t_rem(obj->components, bool_check_key);
        return;
    }
    if (destroy_text_dialog(dialog->dialogues->start->var, scene, win,
            false) == true) {
        rm_fst_elem(dialog->dialogues);
    }
}

int add_event_continue_to_dialog(object_t *dialog)
{
    int status = 0;

    if (dialog == NULL) {
        return (RET_ERR_INPUT);
    }
    status = event_add_node(create_event(NULL, false, dialog,
        &event_next_dialog_off), (node_params_t) {.event = KEY,
        .key = key_next, .mouse = sfMouseLeft});
    return (status);
}
