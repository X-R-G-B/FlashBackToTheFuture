/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** path finding for ennemy
*/

#ifndef ENNEMY_PATHFIND_H_
    #define ENNEMY_PATHFIND_H_

typedef struct pathfind_impl_s pathfind_impl_t;

struct pathfind_impl_s {
    char **origins;
    char **buffer;
    int size_x;
    int size_y;
    char end_char;
    char start_char;
};

#endif
