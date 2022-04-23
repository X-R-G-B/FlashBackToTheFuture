/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** npc header file
*/

#ifndef NPC_RPG_H_
    #define NPC_RPG_H_

    #include "my_bgs.h"
    #include "my_json.h"

void update_npc(object_t *obj, scene_t *scene, window_t *win,
    float dtime);

int aplly_rect_npc(any_t *jsonrect, any_t *current, object_t *npc);

#endif
