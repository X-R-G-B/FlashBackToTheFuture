/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** check restart end magician
*/

#include <stdlib.h>
#include "my_bgs.h"
#include "my_strings.h"

extern const char npc_path_key[];

extern const char end_boss_key[];

extern const char end_magician_key[]; 

static const char end_magician_path[] = "./assets/data/npc/magician_end.json";

void check_restart_end_magician(scene_t *scene)
{
    object_t *end_magician_spawner = NULL;

    if (scene == NULL) {
        return;
    }
    end_magician_spawner = dico_t_get_value(scene->components,
        end_magician_key);
    if (end_magician_spawner == NULL) {
        return;
    }
    end_magician_spawner->components =
        dico_t_add_data(end_magician_spawner->components, npc_path_key,
        end_magician_path, NULL);
    scene->components = dico_t_rem(scene->components, end_boss_key);
}
