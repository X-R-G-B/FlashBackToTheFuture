/*
** EPITECH PROJECT, 2022
** defender
** File description:
** check click prev call
*/

#include "my_bgs_components.h"

bool check_click_prev_call(bool check, window_t *win, set_event_t *set_event)
{
    event_node_t *event_node = NULL;

    if (set_event == NULL || set_event->list_event == NULL ||
        set_event->list_event->start == NULL) {
        return check;
    }
    event_node = set_event->list_event->start->var;
    if (set_event->list_event->len != 1 || event_node->event_type != MOUSE ||
        event_node->event_code.mouse != sfMouseLeft) {
        return check;
    }
    if (check == true && win->click_prev_call == true) {
        check = false;
    }
    if (check == true) {
        win->click_prev_call = true;
    }
    return check;
}
