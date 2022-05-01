/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** add npc magician
*/

#include <stdbool.h>
#include "my_bgs.h"
#include "npc.h"

const char json_magician[] = "./assets/data/npc/magician.json";

void callback_magician(__attribute__((unused)) object_t *npc,
    scene_t *scene,
    __attribute__((unused)) window_t *win)
{
    static int countor = 0;

    if (countor == 0) {
        add_text_dialog_json(scene, json_magician);
    }
    countor++;
}
