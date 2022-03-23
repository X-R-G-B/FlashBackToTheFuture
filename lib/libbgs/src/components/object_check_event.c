/*
** EPITECH PROJECT, 2022
** defender
** File description:
** object check event
*/

#include <stdlib.h>
#include "my_bgs.h"
#include "my_strings.h"
#include "my_bgs_components.h"
#include "../include/libbgs_private.h"

static bool check_node(event_node_t *node)
{
    if (node->event_type == MOUSE) {
        if (sfMouse_isButtonPressed(node->event_code.mouse) == sfTrue) {
            return true;
        }
    } else if (node->event_type == KEY) {
        if (sfKeyboard_isKeyPressed(node->event_code.key) == sfTrue) {
            return true;
        }
    }
    return false;
}

static bool check_event_nodes(set_event_t *set_event, object_t *object,
    window_t *win)
{
    bool check = true;
    event_node_t *node = NULL;
    list_t *elem = NULL;

    if (set_event->hover == true) {
        check = check_hover(object, win);
    }
    if (set_event->list_event != NULL) {
        elem = set_event->list_event->start;
    }
    for (int i = 0; elem != NULL && i < set_event->list_event->len &&
        check == true; i++, elem = elem->next) {
        node = ((event_node_t *) elem->var);
        check = check_node(node);
    }
    return (check);
}

void check_event(set_event_t *set_event, object_t *object,
    window_t *win, scene_t *scene)
{
    bool check = true;

    if ((set_event->list_event == NULL && set_event->hover == false) ||
        set_event == NULL) {
        return;
    }
    check = check_event_nodes(set_event, object, win);
    check = check_click_prev_call(check, win, set_event);
    if (check == true && set_event->prev_call == false) {
        if (set_event->on != NULL) {
            set_event->on(object, scene, win, set_event);
        }
    }
    if (set_event->prev_call == true && check == false) {
        if (set_event->off != NULL) {
            set_event->off(object, scene, win, set_event);
        }
    }
    set_event->prev_call = check;
}

void object_check_event(object_t *object, scene_t *scene,
    window_t *win)
{
    dico_t *cursor = object->components;

    if (cursor == NULL) {
        return;
    }
    do {
        if (my_strstartswith(cursor->key, SET_EVENT) == 1) {
            check_event(cursor->value, object, win, scene);
        }
        cursor = cursor->next;
    } while (cursor != object->components);
}
