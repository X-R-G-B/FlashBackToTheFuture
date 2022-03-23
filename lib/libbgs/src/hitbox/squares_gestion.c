/*
** EPITECH PROJECT, 2022
** defender
** File description:
** squares gestion
*/

#include <stdlib.h>
#include "my_bgs.h"
#include "libbgs_private.h"
#include "my_bgs_components.h"
#include "my_wordarray.h"

int add_float_rect_to_list(sfFloatRect *rect, list_ptr_t *solid_square)
{
    sfFloatRect *new = NULL;
    if (rect == NULL || solid_square == NULL) {
        return (BGS_ERR_INPUT);
    }
    new = malloc(sizeof(sfFloatRect));
    if (new == NULL) {
        return (BGS_ERR_MALLOC);
    }
    new->left = rect->left;
    new->top = rect->top;
    new->width = rect->width;
    new->height = rect->height;
    list_add_to_end(solid_square, new);
    return (BGS_OK);
}

int squares_handling(char **arr, list_ptr_t *solid_squares)
{
    sfFloatRect rect;

    if (arr == NULL) {
        return BGS_ERR_INPUT;
    }
    rect = find_higher_pixels_group(arr);
    while (rect.height != -1 && rect.height != 0) {
        add_float_rect_to_list(&rect, solid_squares);
        rect = find_higher_pixels_group(arr);
    }
    my_wordarray_free(arr);
    return (BGS_OK);
}
