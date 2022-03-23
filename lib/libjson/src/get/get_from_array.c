/*
** EPITECH PROJECT, 2022
** defender
** File description:
** get from array
*/

#include <stddef.h>
#include <stdlib.h>
#include "my_strings.h"
#include "my_json.h"

char **fill_ret(char **ret, list_ptr_t *array)
{
    any_t *any = NULL;
    list_t *elem = array->start;

    for (int i = 0; i < array->len; i++, elem = elem->next) {
        any = elem->var;
        if (any->type != STR) {
            return NULL;
        }
        ret[i] = my_strdup(any->value.str);
    }
    return ret;
}

float *get_any_float_array(any_t *array)
{
    float *ret = NULL;
    list_t *elem = NULL;
    any_t *any = NULL;

    if (array == NULL || array->type != ARRAY) {
        return NULL;
    }
    ret = malloc(sizeof(float) * array->value.array->len);
    if (ret == NULL) {
        return NULL;
    }
    elem = array->value.array->start;
    for (int i = 0; i < array->value.array->len; i++, elem = elem->next) {
        any = elem->var;
        if (any->type != FLOAT) {
            return NULL;
        }
        ret[i] = any->value.f;
    }
    return ret;
}

char **get_any_string_array(any_t *array)
{
    char **ret = NULL;

    if (array == NULL || array->type != ARRAY) {
        return NULL;
    }
    ret = malloc(sizeof(char *) * (array->value.array->len + 1));
    if (ret == NULL) {
        return NULL;
    }
    ret[array->value.array->len] = NULL;
    return fill_ret(ret, array->value.array);
}

int *get_any_int_array(any_t *array)
{
    int *ret = NULL;
    list_t *elem = NULL;
    any_t *any = NULL;

    if (array == NULL || array->type != ARRAY) {
        return NULL;
    }
    ret = malloc(sizeof(int) * array->value.array->len);
    if (ret == NULL) {
        return NULL;
    }
    elem = array->value.array->start;
    for (int i = 0; i < array->value.array->len; i++, elem = elem->next) {
        any = elem->var;
        if (any->type != INT) {
            return NULL;
        }
        ret[i] = any->value.i;
    }
    return ret;
}
