/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** init the find path
*/

#include <stddef.h>
#include "my_wordarray.h"
#include "my_strings.h"
#include "ennemy_pathfind.h"

static int init_new_buffer(pathfind_impl_t *maps)
{
    int sizex = 0;

    sizex = maps->size_x;
    for (int i = 0; i < maps->size_y * sizex; i++) {
        if (maps->buffer[i % sizex][i / sizex] != maps->end_char &&
                maps->buffer[i % sizex][i / sizex] != maps->start_char) {
            maps->buffer[i % sizex][i / sizex] = '\0';
        }
    }
    return (0);
}

static int put_distance_buffer(pathfind_impl_t *maps)
{
    int sizex = 0;

    sizex = maps->size_x;
    for (int i = 0; i < maps->size_y * sizex; i++) {
        if (maps->buffer[i % sizex][i / sizex] != maps->end_char &&
                maps->buffer[i % sizex][i / sizex] != maps->start_char &&
                maps->buffer[i % sizex][i / sizex] != '\0') {
            maps->buffer[i % sizex][i / sizex] = '\0';
        }
    }
    return (0);
}

int init_pathfind(char **array, char end, char start)
{
    pathfind_impl_t maps = {
        .origins = array,
        .start_char = start,
        .end_char = end
    };

    maps.size_y = my_wordarray_len(array);
    if (maps.size_y == 0 || end == '\0' || start == '\0') {
        return (-1);
    }
    maps.size_x = my_strlen(array[0]);
    maps.buffer = my_wordarray_from_wordarray(array);
    if (maps.buffer == NULL || init_new_buffer(&maps)) {
        return (-1);
    }
    return (0);
}
