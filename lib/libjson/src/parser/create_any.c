/*
** EPITECH PROJECT, 2022
** json parser
** File description:
** create any
*/

#include <stdlib.h>
#include "my_bgs.h"
#include "my_fs.h"
#include "my_bgs_components.h"
#include "my_json.h"

any_t *create_any(char c)
{
    any_t *any = malloc(sizeof(any_t));

    if (any == NULL) {
        return NULL;
    }
    any->type = CHAR;
    any->value.c = c;
    return any;
}
