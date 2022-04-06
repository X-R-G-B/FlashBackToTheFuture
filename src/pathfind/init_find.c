/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** init the find path
*/

#include <stdlib.h>
#include "list.h"
#include "my_wordarray.h"
#include "my_strings.h"
#include "ennemy_pathfind.h"

static int init_new_buffer(pathfind_impl_t *maps)
{
    int sizex = 0;

    sizex = maps->size_x;
    for (int i = 0; i < maps->size_y * sizex; i++) {
        if (maps->buffer[i / sizex][i % sizex] != maps->end_char &&
                maps->buffer[i / sizex][i % sizex] != maps->wall_char) {
            maps->buffer[i / sizex][i % sizex] = '\0';
        }
    }
    return (0);
}

static int fill_vect_pos(pathfind_impl_t *maps)
{
    int sizex = 0;
    int count = 0;

    sizex = maps->size_x;
    for (int i = 0; i < maps->size_y * sizex; i++) {
        if (maps->origins[i / sizex][i % sizex] == maps->end_char) {
            maps->end.x = i % sizex;
            maps->end.y = i / sizex;
            count += 1;
        }
    }
    if (count == 2) {
        return (0);
    }
    return (-1);
}

static pathfind_t *create_pathfind(pathfind_impl_t *maps)
{
    pathfind_t *path = NULL;

    path = malloc(sizeof(pathfind_t));
    if (path == NULL) {
        return (NULL);
    }
    path->end = maps->end;
    path->map = maps->buffer;
    path->sizex = maps->size_x;
    path->sizey = maps->size_y;
    return (path);
}

static int fill_pathfind_impl(pathfind_impl_t *maps, char **array, char end,
        char wall)
{
    if (array == NULL) {
        return (-1);
    }
    maps->origins = array;
    maps->wall_char = wall;
    maps->end_char = end;
    maps->size_y = my_wordarray_len(array);
    if (maps->size_y == 0 || end == '\0' || wall == '\0') {
        return (-1);
    }
    maps->size_x = my_strlen(array[0]);
    maps->buffer = my_wordarray_from_wordarray(array);
    if (maps->buffer == NULL) {
        return (-1);
    }
    return (0);
}

pathfind_t *init_pathfind(char **array, char end, char wall)
{
    pathfind_impl_t maps = {0};
    pathfind_t *path = NULL;

    if (fill_pathfind_impl(&maps, array, end, wall)) {
        return (NULL);
    }
    if (init_new_buffer(&maps) || fill_vect_pos(&maps) ||
            put_distance_buffer(&maps)) {
        return (NULL);
    }
    path = create_pathfind(&maps);
    my_wordarray_free(maps.buffer);
    return (path);
}
