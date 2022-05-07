/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** update grandpa
*/

#include "npc.h"

extern const char npc_path_key[];

void update_grandpa(object_t *obj, scene_t *scene, window_t *win,
    __attribute((unused)) float dtime)
{
    char *npc_path = NULL;
    object_t *npc = NULL;

    if (obj == NULL || obj->components == NULL ||
            scene == NULL || win == NULL) {
        return;
    }
    npc_path = dico_t_get_value(obj->components, npc_path_key);
    if (npc_path == NULL) {
        return;
    }
    npc = add_npc(scene, npc_path, obj->bigdata.sprite_bigdata.pos,
        &callback_npc);
    if (npc != NULL) {
        call_callback_npc(npc, scene, win);
    }
    obj->components = dico_t_rem(obj->components, npc_path_key);
}
