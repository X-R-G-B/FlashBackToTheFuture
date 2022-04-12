/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** check_collision
*/

#include "my_rpg.h"
#include "my_strings.h"
#include "my_wordarray.h"
#include <SFML/System/Vector2.h>
#include <stdbool.h>

static sfVector2i get_player_pos_in_map(object_t *obj)
{
    sfVector2f pos = obj->bigdata.sprite_bigdata.pos;
    int pos_y = pos.y + (obj->bigdata.sprite_bigdata.rect.height / 2.0);

    return (sfVector2i) {pos.x / SQUARE_SIZE, pos_y / SQUARE_SIZE};
}

static bool check_char_in_player_direction(char **map,
    sfVector2i pos, player_t *player)
{
    bool (*funcs[4])(object_t *player, char **map, sfVector2i pos) = {
        &check_up_collision, &check_left_collision,
        &check_down_collision, &check_right_collision
    };

    if (player->dir == UNKNOWN_STATE) {
        return (true);
    }
    return (funcs[player->dir](player->obj, map, pos));
}

bool check_collision(player_t *player, scene_t *scene)
{
    sfVector2i player_pos_in_map = {0};
    char **map = NULL;

    if (player == NULL || scene == NULL) {
        return true;
    }
    map = dico_t_get_value(scene->components, COLLISION_ARRAY);
    if (map == NULL) {
        return true;
    }
    player_pos_in_map = get_player_pos_in_map(player->obj);
    return check_char_in_player_direction(map, player_pos_in_map, player);
}
