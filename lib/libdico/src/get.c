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
    if (dico == NULL) {
        return (NULL);
    }
    if (my_strcmp(dico->key, key) == 0) {
        return (dico);
    }
    for (dico_t *tmp = dico->next; tmp != NULL &&
            tmp != dico; tmp = tmp->next) {
        if (my_strcmp(tmp->key, key) == 0) {
            return (tmp);
        }
    }
    return (NULL);
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

dico_t *dico_t_get_elem_ptr(dico_t *dico, void *ptr)
{
    if (dico == NULL) {
        return (NULL);
    }
    if (dico->value == ptr) {
        return (dico);
    }
    for (dico_t *tmp = dico->next; tmp != dico; tmp = tmp->next) {
        if (tmp->value == ptr) {
            return (tmp);
        }
    }
    return (NULL);
}
