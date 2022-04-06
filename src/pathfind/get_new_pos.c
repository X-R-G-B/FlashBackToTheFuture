/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** get new position to reach
*/

#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include "ennemy_pathfind.h"

static int check_greater(int values[3], int *cur_max_value,
        pathfind_t *path)
{
    if (values[0] != path->wall_char && values[1] == -1) {
        *cur_max_value = values[0];
        return (values[2]);
    }
    if (values[0] != path->wall_char && values[1] != -1 &&
            values[0] > *cur_max_value) {
        *cur_max_value = values[0];
        return (values[2]);
    }
    return (values[3]);
}

static sfVector2i get_right_next(int x, int y, pathfind_t *path)
{
    sfVector2i poss[4] = {{x + 1, y}, {x, y + 1}, {x - 1, y}, {x, y - 1}};
    int condd[4] = {x + 1 < path->sizex, y + 1 < path->sizey,
        x - 1 >= 0, y - 1 >= 0
    };
    int find_one = -1;
    int curr_value = 0;
    int cur_max_value = 0;

    for (int i = 0; i < 4; i++) {
        if (!condd[i]) {
            continue;
        }
        curr_value = path->map[poss[i].y][poss[i].x];
        if (curr_value != path->wall_char && find_one == -1) {
            find_one = i;
            cur_max_value = curr_value;
        }
        if (curr_value != path->wall_char && find_one != -1 &&
                curr_value > cur_max_value) {
            find_one = i;
            cur_max_value = curr_value;
        }
    }
    if (find_one == -1) {
        return ((sfVector2i) {x, y});
    }
    return (poss[find_one]);
}

sfVector2f get_new_pos(pathfind_t *path, sfVector2f cur_pos)
{
    int cur_x = ((int) cur_pos.x) / 1920;
    int cur_y = ((int) cur_pos.y) / 1080;
    sfVector2i new = {0};

    if (path == NULL) {
        return (cur_pos);
    }
    if (cur_x >= path->sizex || cur_x < 0 ||
            cur_y >= path->sizey || cur_y < 0) {
        return (cur_pos);
    }
    new = get_right_next(cur_x, cur_y, path);
    return ((sfVector2f) {new.x, new.y});
}
