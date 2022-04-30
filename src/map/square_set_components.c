/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** square set components
*/

#include <stdlib.h>
#include "my_strings.h"
#include "my_bgs.h"
#include "my_json.h"

static const char components_dict_key[] = "components";

static void add_data_to_square(char key[255], any_t *value, object_t *square)
{
    if (value == NULL) {
        return;
    }
    if (value->type == STR) {
        printf("oui\n");
        square->components = dico_t_add_data(square->components, key,
            my_strdup(value->value.str), free);
    } else if (value->type == INT) {
        square->components = dico_t_add_data(square->components, key,
            (void *) value->value.i, NULL);
    }
}

static void add_components_to_square(object_t *square, dico_t *components_dict)
{
    dico_t *ptr = components_dict;

    do {
        add_data_to_square(ptr->key, ptr->value, square);
        ptr = ptr->next;
    } while (ptr != components_dict);
}

void square_set_components(object_t *square, dico_t *char_type)
{
    any_t *components_dict = NULL;

    if (square == NULL || char_type == NULL) {
        return;
    }
    components_dict = dico_t_get_any(char_type, components_dict_key);
    if (components_dict == NULL || components_dict->type != DICT) {
        return;
    }
    printf("??\n");
    add_components_to_square(square, components_dict->value.dict);
}