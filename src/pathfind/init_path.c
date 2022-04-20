/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** get distance
*/

#include <stdlib.h>
#include "ennemy_pathfind.h"
#include "list.h"

vect2i_t *create_vectpos(int x, int y)
{
    vect2i_t *new = NULL;

    new = malloc(sizeof(vect2i_t));
    if (new == NULL) {
        return (NULL);
    }
    new->x = x;
    new->y = y;
    return (new);
}

static int check_pos(vect2i_t *pos, list_ptr_t *tmp, pathfind_impl_t *maps)
{
    char curr = maps->buffer[pos->y][pos->x];
    vect2i_t poss[4] = {{pos->x + 1, pos->y}, {pos->x, pos->y + 1},
        {pos->x - 1, pos->y}, {pos->x, pos->y - 1}
    };
    int condd[4] = {pos->x + 1 < maps->size_x, pos->y + 1 < maps->size_y,
        pos->x > 0, pos->y > 0
    };

    curr = (curr + 1 == maps->wall_char) ? curr + 2 : curr + 1;
    for (int i = 0; i < 4; i++) {
        if (condd[i] != 0 && maps->buffer[poss[i].y][poss[i].x] == '\0') {
            maps->buffer[poss[i].y][poss[i].x] = curr;
            list_add_to_start(tmp, create_vectpos(poss[i].x, poss[i].y));
        }
    }
    free(pos);
    return (0);
}

static list_ptr_t *itterate_list(list_ptr_t *list, pathfind_impl_t *maps)
{
    list_ptr_t *tmp = NULL;

    tmp = list_create();
    while (list->len != 0) {
        check_pos(list->start->var, tmp, maps);
        rm_fst_elem(list);
    }
    return (tmp);
}

static int destroy_list_vect(list_ptr_t *list)
{
    list_t *tmp = NULL;

    if (list == NULL) {
        return (-1);
    }
    tmp = list->start;
    for (int i = 0; i < list->len; i++, tmp = tmp->next) {
        free(tmp->var);
    }
    free_list(list);
    return (0);
}

int put_distance_buffer(pathfind_impl_t *maps)
{
    list_ptr_t *list = NULL;
    list_ptr_t *tmp = NULL;

    list = list_create();
    list_add_to_start(list, create_vectpos(maps->end.x, maps->end.y));
    maps->buffer[maps->end.y][maps->end.x] = '\0';
    while (list != NULL && list->len != 0) {
        tmp = itterate_list(list, maps);
        destroy_list_vect(list);
        list = tmp;
    }
    return (destroy_list_vect(list));
}
