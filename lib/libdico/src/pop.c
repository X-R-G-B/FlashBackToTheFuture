/*
** EPITECH PROJECT, 2022
** LIBLIST
** File description:
** pop elem
*/

#include <stdlib.h>
#include "my_dico.h"

void *dico_t_pop_value(dico_t *dico, char const *key)
{
    void *tmp;
    dico_t *elem;

    elem = dico_t_get_elem(dico, key);
    if (elem == NULL) {
        return (NULL);
    }
    if (elem->last != NULL) {
        elem->last->next = elem->next;
    }
    if (elem->next != NULL) {
        elem->next->last = elem->last;
    }
    elem->last = NULL;
    elem->next = NULL;
    tmp = elem->value;
    free(elem);
    return (tmp);
}

dico_t *dico_t_pop_elem(dico_t *dico, char const *key)
{
    dico_t *elem;

    elem = dico_t_get_elem(dico, key);
    if (elem == NULL) {
        return (NULL);
    }
    if (elem->last != NULL) {
        elem->last->next = elem->next;
    }
    if (elem->next != NULL) {
        elem->next->last = elem->last;
    }
    elem->last = NULL;
    elem->next = NULL;
    return (elem);
}
