/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** check if wall
*/

#include "ennemies.h"
#include "my_bgs.h"
#include "my_rpg.h"
#include "my_wordarray.h"
#include "my_json.h"
#include "my_strings.h"
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Vector2.h>
#include <stdbool.h>

static bool check_point_x_y(sfVector2f border, sfVector2f new,
    char *const *map)
{
    int x = (border.x - new.x) / SQUARE_SIZE;
    int y = (border.y - new.y) / SQUARE_SIZE;

    if (x < 0 || y < 0 || y >= my_wordarray_len(map) ||
            x >= my_strlen(map[y])) {
        return (true);
    }
    if (map[y][x] == '#') {
        return (true);
    }
    return (false);
}

static bool check_all_border(sfSprite *sprite, sfVector2f new,
    char *const *map)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);
    sfVector2f positions[9] = {
        {bounds.left, bounds.top},
        {bounds.left, bounds.top + bounds.height},
        {bounds.left + bounds.width, bounds.top},
        {bounds.left + bounds.width, bounds.top + bounds.height},
        {bounds.left, bounds.top + bounds.height / 2.0},
        {bounds.left + bounds.width, bounds.top + bounds.height / 2.0},
        {bounds.left + bounds.width / 2.0, bounds.top},
        {bounds.left + bounds.width / 2.0, bounds.top + bounds.height},
        {bounds.left + bounds.width / 2.0, bounds.top + bounds.height / 2.0},
    };

    for (int i = 0; i < 9; i++) {
        if (check_point_x_y(positions[i], new, map) == true) {
            return (true);
        }
    }
    return (false);
}

bool check_wall(ennemy_t *ennemy, sfVector2f new, window_t *win)
{
    scene_t *scene = NULL;
    char **map = NULL;

    if (win == NULL || ennemy == NULL || ennemy->obj == NULL) {
        return (true);
    }
    scene = dico_t_get_value(win->scenes, win->current_scene);
    map = dico_t_get_value((scene == NULL) ? NULL : scene->components,
        COLLISION_ARRAY);
    if (map == NULL) {
        return true;
    }
    return check_all_border(ennemy->obj->drawable.sprite, new, map);
}
