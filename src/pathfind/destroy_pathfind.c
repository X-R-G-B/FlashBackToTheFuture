/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** detsroy pathfind
*/

#include <stdlib.h>
#include "my_wordarray.h"
#include "ennemy_pathfind.h"

void destroy_pathfind(void *path_void)
{
    pathfind_t *path = path_void;

    if (path_void == NULL) {
        return;
    }
    my_wordarray_free(path->map);
    free(path);
}
