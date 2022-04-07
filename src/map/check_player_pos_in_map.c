/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** check player pos in map
*/

#include "my_rpg.h"

bool check_right_collision(object_t *player, char **map, sfVector2i pos)
{
    sfVector2f pos_f = player->bigdata.sprite_bigdata.pos;
    int pos_y = pos_f.y + (player->bigdata.sprite_bigdata.rect.height / 2);

    pos_y = (pos_y + 13) / SQUARE_SIZE;
    if (pos.x + 1 == '\0' || map[pos_y - 1][pos.x + 1] == '#' ||
        map[pos.y][pos.x + 1] == '#') {
        return true;
    }
    return false;
}

bool check_left_collision(object_t *player, char **map, sfVector2i pos)
{
    sfVector2f pos_f = player->bigdata.sprite_bigdata.pos;
    int pos_y = pos_f.y + (player->bigdata.sprite_bigdata.rect.height / 2);

    pos_y = (pos_y + 13) / SQUARE_SIZE;
    if (pos.x < 0 || map[pos_y - 1][pos.x - 1] == '#' ||
        map[pos.y][pos.x - 1] == '#') {
        return true;
    }
    return false;
}

bool check_up_collision(object_t *player, char **map, sfVector2i pos)
{
    int fst_pos_x = player->bigdata.sprite_bigdata.pos.x +
        (player->bigdata.sprite_bigdata.rect.width / 4);
    int scd_pos_x = player->bigdata.sprite_bigdata.pos.x -
        (player->bigdata.sprite_bigdata.rect.width / 4);

    fst_pos_x = fst_pos_x / SQUARE_SIZE;
    scd_pos_x = scd_pos_x / SQUARE_SIZE;
    if (pos.y < 0 || map[pos.y - 1][fst_pos_x] == '#' ||
        map[pos.y - 1][scd_pos_x] == '#') {
        return true;
    }
    return false;
}

bool check_down_collision(object_t *player, char **map)
{
    int pos_y = (player->bigdata.sprite_bigdata.pos.y +
        (player->bigdata.sprite_bigdata.rect.height / 2) + 8);
    int fst_pos_x = player->bigdata.sprite_bigdata.pos.x +
        (player->bigdata.sprite_bigdata.rect.width / 4);
    int scd_pos_x = player->bigdata.sprite_bigdata.pos.x -
        (player->bigdata.sprite_bigdata.rect.width / 4);

    pos_y = pos_y / SQUARE_SIZE;
    fst_pos_x = fst_pos_x / SQUARE_SIZE;
    scd_pos_x = scd_pos_x / SQUARE_SIZE;
    if (map[pos_y] == NULL || map[pos_y][fst_pos_x] == '#' ||
        map[pos_y][scd_pos_x] == '#') {
        return true;
    }
    return false;
}

