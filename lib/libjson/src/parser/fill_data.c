/*
** EPITECH PROJECT, 2022
** json parser
** File description:
** fill data
*/

#include "my_json.h"

void fill_data(char origin, char *end, any_t *any)
{
    switch (origin) {
    case 34:
        *end = 34;
        any->type = STR;
        break;
    case '{':
        *end = '}';
        any->type = DICT;
        break;
    case '[':
        *end = ']';
        any->type = ARRAY;
        break;
    default:
        *end = 21;
        any->type = INT;
        break;
    }
}
