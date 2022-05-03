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

void callback_npc(__attribute__((unused)) object_t *npc,
    scene_t *scene,
    __attribute__((unused)) window_t *win)
{
    char *path = NULL;

    path = (char *) dico_t_get_value(npc->components, npc_path_key);
    if (path == NULL) {
        return;
    }
    add_text_dialog_json(scene, path);
    npc->components = dico_t_rem(npc->components, npc_path_key);
}
