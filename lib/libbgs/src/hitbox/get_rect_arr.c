/*
** EPITECH PROJECT, 2022
** defender
** File description:
** get other rect arr
*/

#include <stdlib.h>
#include "my_bgs.h"
#include "libbgs_private.h"
#include "my_bgs_components.h"

//sa rentre pas la ca marche pas
static list_ptr_t *check_pixels_in_rect(list_ptr_t *list,
    sfFloatRect object_bounce)
{
    list_t *elem = list->start;
    list_ptr_t *ret = list_create();

    if (elem == NULL || ret == NULL) {
        return NULL;
    }
    for (int i = 0; i < list->len; i++, elem = elem->next) {
        if (sfFloatRect_intersects(&object_bounce, elem->var, NULL) == sfTrue) {
            list_add_to_end(ret, elem->var);
        }
    }
    return ret;
}

sfFloatRect *get_rect_arr(list_ptr_t *list, object_t *object,
    sfFloatRect object_bounce)
{
    sfFloatRect *rect_arr = NULL;
    list_t *elem = NULL;
    list_ptr_t *valid_list = check_pixels_in_rect(list, object_bounce);

    if (list == NULL || object == NULL || valid_list == NULL) {
        return NULL;
    }
    elem = valid_list->start;
    rect_arr = malloc(sizeof(sfFloatRect) * (valid_list->len + 1));
    if (rect_arr == NULL) {
        return NULL;
    }
    rect_arr[valid_list->len] = (sfFloatRect) {-2, -2, -2, -2};
    for (int i = 0; i < valid_list->len; i++, elem = elem->next) {
        rect_arr[i] = get_right_checkbox(object, elem->var);
    }
    return rect_arr;
}
