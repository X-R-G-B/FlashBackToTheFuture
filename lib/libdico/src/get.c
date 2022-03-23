/*
** EPITECH PROJECT, 2022
** LIBDICO
** File description:
** get value from key
*/

#include <stddef.h>
#include "my_json.h"
#include "my_strings.h"
#include "my_dico.h"

dico_t *dico_t_get_elem(dico_t *dico, char const *key)
{
    dico_t *cursor_last;
    dico_t *cursor;
    int is_found = 0;

    if (dico == NULL) {
        return (NULL);
    }
    cursor = dico;
    do {
        if (my_strcmp(cursor->key, key) == 0) {
            is_found = 1;
        }
        cursor_last = cursor;
        cursor = cursor->next;
    } while (cursor != NULL && is_found == 0 && cursor != dico);
    return ((is_found) ? cursor_last : NULL);
}

void *dico_t_get_value(dico_t *dico, char const *key)
{
    dico_t *elem;

    elem = dico_t_get_elem(dico, key);
    if (elem == NULL) {
        return (NULL);
    }
    return (elem->value);
}
