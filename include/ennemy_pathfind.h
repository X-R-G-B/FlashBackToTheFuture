/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** path finding for ennemy
*/

#ifndef ENNEMY_PATHFIND_H_
    #define ENNEMY_PATHFIND_H_

    #include "list.h"

typedef struct pathfind_impl_s pathfind_impl_t;
typedef struct vect2i_s vect2i_t;

struct vect2i_s {
    int x;
    int y;
};

struct pathfind_impl_s {
    char **origins;
    char **buffer;
    int size_x;
    int size_y;
    char end_char;
    char start_char;
    vect2i_t end;
    vect2i_t start;
};

int put_distance_buffer(pathfind_impl_t *maps);

int check_start_in_list(list_ptr_t *list, vect2i_t *start);

#endif
