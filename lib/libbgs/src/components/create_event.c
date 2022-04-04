/*
** EPITECH PROJECT, 2022
** defender
** File description:
** set event
*/

#include <stdlib.h>
#include "my_bgs.h"
#include "my_bgs_components.h"

int event_add_node(set_event_t *event, node_params_t params)
{
    event_node_t *node = malloc(sizeof(event_node_t));

    if (event == NULL) {
        return BGS_ERR_INPUT;
    } else if (node == NULL) {
        return BGS_ERR_MALLOC;
    }
    if (params.event == MOUSE) {
        node->event_code.mouse = params.mouse;
    } else if (params.event == KEY) {
        node->event_code.key = params.key;
    }
    node->event_type = params.event;
    if (list_add_to_end(event->list_event, node) == NULL) {
        return BGS_ERR_MALLOC;
    }
    return BGS_OK;
}

set_event_t *create_event(void (*on)(object_t *, scene_t *, window_t *,
    set_event_t *), bool hover, object_t *object,
    void (*off)(object_t *, scene_t *, window_t *, set_event_t *))
{
    set_event_t *event = malloc(sizeof(set_event_t));

    if (event == NULL) {
        return NULL;
    }
    event->on = on;
    event->off = off;
    event->prev_call = false;
    event->hover = hover;
    event->list_event = list_create();
    if (event->list_event == NULL) {
        return NULL;
    }
    if (object_set_event(object, event) != BGS_OK) {
        return NULL;
    }
    return event;
}
