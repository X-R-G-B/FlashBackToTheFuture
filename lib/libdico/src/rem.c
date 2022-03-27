/*
** EPITECH PROJECT, 2022
** LIBLIST
** File description:
** remove elem from list
*/

#include <stdlib.h>
#include "my_dico.h"

dico_t *dico_t_rem(dico_t *dico, char const *key)
{
    dico_t *elem = dico_t_get_elem(dico, key);
    dico_t *tmp = NULL;

    if (elem == NULL) {
        return (dico);
    }
    if (elem->last != NULL) {
        elem->last->next = elem->next;
        tmp = elem->last;
    }
    if (elem->next != NULL) {
        elem->next->last = elem->last;
        tmp = elem->next;
    }
    if (elem->destroy != NULL) {
        elem->destroy(elem->value);
    }
    free(elem);
    return ((elem == dico) ? tmp : dico);
}

dico_t *dico_t_rem_ptr(dico_t *dico, void *ptr)
{
    if (dico == NULL) {
        return (NULL);
    }
    for (dico_t *tmp = dico->next; tmp != dico; tmp = tmp->next) {
        if (tmp->value == ptr) {
            return (dico_t_rem(dico, tmp->key));
        }
    }
    return (dico);
}
