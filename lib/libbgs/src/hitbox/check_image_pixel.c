/*
** EPITECH PROJECT, 2022
** defender
** File description:
** check image pixel
*/

#include <stdlib.h>
#include "my_bgs_components.h"
#include "my_bgs.h"

static void fill_arr(char **arr, const sfUint8 *pixels, unsigned int x,
    unsigned int y)
{
    unsigned int cur_x = 0;
    int cur_y = 0;

    for (int i = 0; i < (int) y; i++) {
        arr[i] = malloc(sizeof(char) * (x + 1));
        if (arr[i] == NULL) {
            return;
        }
        arr[i][x] = '\0';
    }
    for (unsigned int i = 0; i < x * y * 4; i++) {
        if (cur_x >= x && cur_y < (int) y) {
            cur_y += 1;
            cur_x = 0;
        }
        if (arr[cur_y]) {
            arr[cur_y][cur_x++] = (pixels[i] == 0) ? '0' : '1';
        }
    }
}

char **check_image_pixel(sfImage *image)
{
    const sfUint8 *pixels;
    sfVector2u size;
    char **arr = NULL;

    if (image == NULL) {
        return NULL;
    }
    pixels = sfImage_getPixelsPtr(image);
    size = sfImage_getSize(image);
    arr = malloc(sizeof(char *) * (size.y + 1));
    if (arr == NULL) {
        return (NULL);
    }
    arr[size.y] = NULL;
    if (arr == NULL) {
        return NULL;
    }
    fill_arr(arr, pixels, size.x, size.y);
    return (arr);
}
