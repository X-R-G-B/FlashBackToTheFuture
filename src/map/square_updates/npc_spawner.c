/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** npc_spawner
*/

#include "my_bgs.h"
#include "my_rpg.h"
#include "npc.h"

extern const char npc_path_key[];

void init_npc_spawner(object_t *obj, scene_t *scene, window_t *win,
    __attribute__((unused)) float time)
{
    char *npc_path = NULL;

    if (obj == NULL || obj->components == NULL ||
            scene == NULL || win == NULL) {
        return;
    }
    npc_path = dico_t_get_value(obj->components, npc_path_key);
    if (npc_path == NULL) {
        return;
    }
    add_npc(scene, npc_path, obj->bigdata.sprite_bigdata.pos,
        &callback_npc);
    obj->components = dico_t_rem(obj->components, npc_path_key);
}
