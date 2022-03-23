/*
** EPITECH PROJECT, 2022
** libjson
** File description:
** dup a any_t with malloc
*/

#include <stdlib.h>
#include "my_json.h"
#include "my_puts.h"

void check_nb(any_t *any, any_t *new)
{
    if (any->type == INT) {
        new->value.i = any->value.i;
    } else if (any->type == FLOAT) {
        new->value.f = any->value.f;
    }
}

static any_t *fill_any(any_t *any, any_t *new)
{
    if (new == NULL || any == NULL) {
        return NULL;
    }
    switch (any->type) {
        case STR:
            new->value.str = any->value.str;
            break;
        case ARRAY:
            new->value.array = any->value.array;
            break;
        case DICT:
            new->value.dict = any->value.dict;
            break;
        default:
            break;
    }
    check_nb(any, new);
    return (new);
}

any_t *any_dup(any_t *any)
{
    any_t *new = NULL;

    if (any == NULL) {
        return NULL;
    }
    new = malloc(sizeof(any_t));
    if (new == NULL) {
        return (NULL);
    }
    new->type = any->type;
    if (fill_any(any, new) == NULL) {
        return NULL;
    }
    return new;
}
