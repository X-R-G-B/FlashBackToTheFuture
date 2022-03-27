/*
** EPITECH PROJECT, 2022
** LIBLIST
** File description:
** remove elem from list
*/

#include <stdlib.h>
#include "my_dico.h"

int dico_t_rem(dico_t *dico, char const *key)
{
    dico_t *elem = dico_t_get_elem(dico, key);

    if (elem == NULL) {
        return (0);
    }
    if (elem->last != NULL) {
        elem->last->next = elem->last;
    }
    if (elem->next != NULL) {
        elem->next->last = elem->last;
    }
    if (elem->destroy != NULL) {
        elem->destroy(elem->value);
    }
    elem->last = NULL;
    elem->next = NULL;
    free(elem);
    return (1);
}

int dico_t_rem_ptr(dico_t *dico, void *ptr)
{
    if (dico == NULL) {
        return (0);
    }
    for (dico_t *tmp = dico->next; tmp != dico; tmp = tmp->next) {
        if (tmp->value == ptr) {
            return (dico_t_rem(dico, tmp->key));
        }
    }
    return (0);
}
