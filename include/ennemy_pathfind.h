/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** path finding for ennemy
*/

#ifndef ENNEMY_PATHFIND_H_
    #define ENNEMY_PATHFIND_H_

    #include "list.h"
    #include "my_bgs.h"
    #include "my_rpg.h"

    #define SCENE_PATHFIND_PATH "SCENE_PATHFIND_PATH"

typedef struct pathfind_impl_s pathfind_impl_t;
typedef struct vect2i_s vect2i_t;
typedef struct pathfind_s pathfind_t;

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
    char wall_char;
    vect2i_t end;
};

struct pathfind_s {
    char **map;
    int sizex;
    int sizey;
    vect2i_t end;
    char wall_char;
};

int put_distance_buffer(pathfind_impl_t *maps);

void destroy_pathfind(void *path_void);

pathfind_t *init_pathfind(char **array, char end, char start, scene_t *scene);

dir_t get_path_find_dir(object_t *obj, scene_t *scene);

/**
** @brief add to scene the pathfind
**
** @param scene scene where need the pathfind
** @param obj obj representing the player
**
** @return {
** RET_ERR_INPUT : scene or obj is NULL,
** RET_OK : pathfind is init
** }
**/
int pathfind_add_to_scene(scene_t *scene);

#endif
