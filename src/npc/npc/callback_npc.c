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

void callback_npc(__attribute__((unused)) object_t *npc,
    scene_t *scene,
    __attribute__((unused)) window_t *win)
{
    char *path = NULL;
    bool check = false;

    path = (char *) dico_t_get_value(npc->components, npc_path_key);
    check = (bool) dico_t_get_value(npc->components, bool_check_key);
    if (path == NULL || check == true) {
        return;
    }
    add_text_dialog_json(scene, path);
    dico_t_add_data(npc->components, bool_check_key, (void *) true, NULL);
}
