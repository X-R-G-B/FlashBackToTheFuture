/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** check if start is in list of check
*/

#include <stddef.h>
#include "ennemy_pathfind.h"
#include "list.h"

int check_start_in_list(list_ptr_t *list, vect2i_t *start)
{
    list_t *tmp = NULL;
    vect2i_t *pos = NULL;

    if (list == NULL) {
        return (0);
    }
    tmp = list->start;
    for (int i = 0; i < list->len; i++, tmp = tmp->next) {
        pos = tmp->var;
        if (pos->y == start->y && pos->x == start->x) {
            return (1);
        }
    }
    return (0);
}
