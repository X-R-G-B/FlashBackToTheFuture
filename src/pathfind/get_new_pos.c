/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** get new position to reach
*/

#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include "my_bgs.h"
#include "my_dico.h"
#include "my_rpg.h"
#include "ennemy_pathfind.h"

static dir_t get_next_case(int x, int y, pathfind_t *path)
{
    sfVector2i poss[5] = {{x, y}, {x, y - 1}, {x - 1, y},
        {x, y + 1}, {x + 1, y}};
    int condd[5] = {1, y > 0, x > 0, y + 1 < path->sizey, x + 1 < path->sizex};
    int max_i = 0;
    int max_i_val = path->map[poss[0].y][poss[0].x];

    for (int i = 1; i < 5; i++) {
        if (!condd[i]) {
            continue;
        }
        if (path->map[poss[i].y][poss[i].x] > max_i_val) {
            max_i = i;
            max_i_val = path->map[poss[i].y][poss[i].x];
        }
    }
    return (max_i - 1);
}

static dir_t get_new_dir(pathfind_t *path, sfVector2f cur_pos)
{
    int cur_x = ((int) cur_pos.x) / 1920;
    int cur_y = ((int) cur_pos.y) / 1080;
    dir_t dir = UNKNOWN_STATE;

    if (path == NULL) {
        return (UNKNOWN_STATE);
    }
    if (cur_x >= path->sizex || cur_x < 0 ||
            cur_y >= path->sizey || cur_y < 0) {
        return (UNKNOWN_STATE);
    }
    dir = get_next_case(cur_x, cur_y, path);
    return (dir);
}

dir_t get_path_find_dir(object_t *obj, scene_t *scene)
{
    sfVector2f pos = {0};
    pathfind_t *path = NULL;
    dir_t current = UNKNOWN_STATE;

    if (obj == NULL || scene == NULL) {
        return (UNKNOWN_STATE);
    }
    printf("ici\n");
    pos = obj->bigdata.sprite_bigdata.pos;
    path = dico_t_get_value(scene->components, SCENE_PATHFIND_PATH);
    if (path == NULL) {
        return (UNKNOWN_STATE);
    }
    printf("icietla\n");
    current = get_new_dir(path, pos);
    return (current);
}
