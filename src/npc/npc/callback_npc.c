/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** add npc magician
*/

#include <stdbool.h>
#include "my_bgs.h"
#include "my_rpg.h"
#include "npc.h"

const char npc_path_key[] = "npc path";
const char bool_check_key[] = "bool check";

void reaload_dialogs(const char *str, scene_t *scene, window_t *win, void *data)
{
    object_t *object = data;

    if (str == NULL || scene == NULL || win == NULL || data == NULL) {
        return;
    }
    object->components = dico_t_rem(object->components, bool_check_key);
}

void callback_npc(object_t *npc, scene_t *scene,
    __attribute__((unused)) window_t *win)
{
    char *path = NULL;
    bool check = false;

    if (npc == NULL || scene == NULL) {
        return;
    }
    path = dico_t_get_value(npc->components, npc_path_key);
    check = (bool) dico_t_get_value(npc->components, bool_check_key);
    if (path == NULL || check == true) {
        return;
    }
    add_text_dialog_json(win, path, &reaload_dialogs, npc);
    object_add_components(npc, (void *) true, bool_check_key, NULL);
}
