/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** header for ennemy
*/

#ifndef ENNEMY_H_
    #define ENNEMY_H_

    #include "my_json.h"
    #include "my_bgs.h"

int create_amongus(scene_t *scene, int pos_x, int pos_y);

int change_amongus_rect(any_t *dico, object_t *obj, window_t *win);

#endif
