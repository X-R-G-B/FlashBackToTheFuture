/*
** EPITECH PROJECT, 2022
** defender
** File description:
** object check event
*/

#include <stdbool.h>
#include <stdlib.h>
#include "my_bgs.h"
#include "my_strings.h"
#include "my_bgs_components.h"
#include "libbgs_private.h"

static bool check_node(event_node_t *node, set_event_t *set_event)
{
    if (node == NULL || set_event == NULL) {
        return (false);
    }
    if (node->event_type == MOUSE) {
        if (sfMouse_isButtonPressed(node->event_code.mouse) == sfTrue) {
            set_event->input_key.event_type = MOUSE;
            set_event->input_key.event_code.mouse = node->event_code.mouse;
            return true;
        }
    } else if (node->event_type == KEY) {
        if (sfKeyboard_isKeyPressed(node->event_code.key) == sfTrue) {
            set_event->input_key.event_type = KEY;
            set_event->input_key.event_code.key = node->event_code.key;
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

    if (set_event == NULL || object == NULL || win == NULL) {
        return (false);
    }
    if (set_event->hover == true) {
        check = check_hover(object, win);
    }
    if (set_event->list_event != NULL) {
        elem = set_event->list_event->start;
    }
    for (int i = 0; elem != NULL && i < set_event->list_event->len &&
        check == true; i++, elem = elem->next) {
        node = ((event_node_t *) elem->var);
        check = check_node(node, set_event);
    }
    return (check);
}

void check_off_event(set_event_t *set_event, object_t *obj,
    window_t *win, scene_t *scene)
{
    if (set_event == NULL || obj == NULL || win == NULL || scene == NULL) {
        return;
    }
    if (set_event->prev_call == true && sfRenderWindow_isOpen(win->win)) {
        if (set_event->off != NULL) {
            set_event->off(obj, scene, win, set_event);
        }
        if (win->click == set_event) {
            win->click = NULL;
        }
        scene_loading_handling(win);
    }
}

void check_event(set_event_t *set_event, object_t *object,
    window_t *win, scene_t *scene)
{
    bool check = true;

    if (set_event == NULL || object == NULL || win == NULL || scene == NULL ||
        (set_event->list_event == NULL && set_event->hover == false)) {
        return;
    }
    check = check_event_nodes(set_event, object, win);
    check = check_click_prev_call(check, win, set_event);
    if (check == true && set_event->on != NULL &&
        sfRenderWindow_isOpen(win->win)) {
        set_event->on(object, scene, win, set_event);
        scene_loading_handling(win);
    }
    if (check == false) {
        check_off_event(set_event, object, win, scene);
    }
    set_event->prev_call = check;
}

void object_check_event(object_t *object, scene_t *scene,
    window_t *win)
{
    dico_t *cursor = NULL;

    if (object == NULL || scene == NULL || win == NULL) {
        return;
    }
    cursor = object->components;
    if (cursor == NULL) {
        return;
    }
    do {
        if (my_strstartswith(cursor->key, SET_EVENT) == 1) {
            check_event(cursor->value, object, win, scene);
        }
        cursor = cursor->next;
    } while (cursor != object->components && sfRenderWindow_isOpen(win->win));
}
