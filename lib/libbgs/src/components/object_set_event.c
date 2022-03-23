/*
** EPITECH PROJECT, 2022
** Defender
** File description:
** object set event
*/

#include <stdlib.h>
#include "my_strings.h"
#include "my_bgs.h"
#include "my_bgs_components.h"
#include "../include/libbgs_private.h"

void destroy_event(void *data)
{
    set_event_t *event = data;
    list_t *elem = NULL;

    if (event == NULL) {
        return;
    }
    if (event->list_event == NULL) {
        free(event);
        return;
    }
    elem = event->list_event->start;
    for (int i = 0; i < event->list_event->len; i++, elem = elem->next) {
        free(elem->var);
    }
    free_list(event->list_event);
    free(event);
}

int object_set_event(object_t *object, set_event_t *event)
{
    char key[255] = {0};

    my_strcpy(key, SET_EVENT);
    if (object == NULL || event == NULL) {
        return BGS_ERR_INPUT;
    }
    if (event == NULL) {
        return BGS_ERR_MALLOC;
    }
    get_id_generator_cat(key);
    object->components = dico_t_add_data(object->components, key, event,
        &destroy_event);
    return (BGS_OK);
}
