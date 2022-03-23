/*
** EPITECH PROJECT, 2022
** LIBLIST
** File description:
** destroy all linked list
*/

#include <stdlib.h>
#include "my_dico.h"

void dico_t_destroy_void(void *data)
{
    dico_t_destroy((dico_t *) data);
}

void check_last(dico_t *cursor)
{
    if (cursor != NULL) {
        if (cursor->destroy != NULL) {
            cursor->destroy(cursor->value);
        }
        free(cursor);
    }
}

int dico_t_destroy(dico_t *dico)
{
    dico_t *tmp = NULL;
    dico_t *cursor = NULL;
    int nb = 0;

    if (dico == NULL) {
        return (0);
    }
    cursor = dico->next;
    for (; cursor != NULL && cursor != dico; nb++) {
        tmp = cursor->next;
        if (cursor->destroy != NULL) {
            cursor->destroy(cursor->value);
        }
        free(cursor);
        cursor = tmp;
    }
    check_last(cursor);
    return (nb + 1);
}
