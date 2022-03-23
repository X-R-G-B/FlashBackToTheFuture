/*
** EPITECH PROJECT, 2022
** defender
** File description:
** find higher pixels group
*/

#include "my_bgs.h"
#include "my_wordarray.h"
#include "libbgs_private.h"

char **remove_square_in_map(char **map, square_t square)
{
    for (int i = 0; i < square.size; i++) {
        for (int x = 0; x < square.size; x++) {
            map[square.y + i][square.x + x] = '0';
        }
    }
    return map;
}

int find_obstacle(int i, int x, char **map, int sq_size)
{
    for (int c = 0; c < sq_size; c++)
        if (map[i][x + c] == '\0' || map[i][x + c] == '0')
            return 1;
    return 0;
}

int find_square(int y, int x, char **map, int sq_size)
{
    for (int i = 0; i < sq_size; i++) {
        if (map[y + i] == NULL || find_obstacle(i + y, x, map, sq_size))
            return sq_size - 1;
    }
    return find_square(y, x, map, sq_size + 1);
}

int browse_arr(char **arr, int i, square_t *square)
{
    int sq_size = 0;

    if (arr == NULL || square == NULL || i < 0) {
        return BGS_ERR_INPUT;
    }
    for (int x = 0; arr[i] != NULL && arr[i][x] != '\0'; x++) {
        if (arr[i][x] != '1' && arr[i][x] != '0') {
            return BGS_ERR_INPUT;
        } else if (arr[i][x] == '1') {
            sq_size = find_square(i, x, arr, square->size + 1);
        }
        if (sq_size > square->size) {
            *square = (square_t) {i, x, sq_size};
        }
    }
    return BGS_OK;
}

sfFloatRect find_higher_pixels_group(char **arr)
{
    square_t square;
    sfFloatRect rect;

    if (arr == NULL) {
        return (sfFloatRect) {-1, -1, -1, -1};
    }
    square = (square_t) {0, 0, 0};
    for (int i = 0; arr[i] != NULL; i++) {
        if (browse_arr(arr, i, &square) != BGS_OK) {
            return (sfFloatRect) {-1, -1, -1, -1};
        }
    }
    rect = (sfFloatRect) {square.x, square.y, square.size, square.size};
    remove_square_in_map(arr, square);
    my_wordarray_write(arr, "tests/res.txt");
    return rect;
}
