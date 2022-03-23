/*
** EPITECH PROJECT, 2022
** libgs
** File description:
** andle events
*/

#include <SFML/Graphics.h>
#include "my_strings.h"
#include "my_bgs.h"
#include "my_bgs_components.h"

int window_update_event(window_t *win, scene_t *scene)
{
    dico_t *cursor = NULL;

    if (win == NULL || win->components == NULL || scene == NULL) {
        return (BGS_ERR_INPUT);
    }
    cursor = win->components;
    if (cursor == NULL) {
        return (BGS_OK);
    }
    do {
        if (my_strstartswith(cursor->key, SET_EVENT) == 1) {
            check_event(cursor->value, NULL, win, scene);
        }
        cursor = cursor->next;
    } while (cursor != win->components);
    return (BGS_OK);
}

int event_handling(sfRenderWindow *win, window_t *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(win, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(win);
        } else if (event.type == sfEvtMouseButtonReleased &&
            event.mouseButton.button == sfMouseLeft) {
            window->click_prev_call = false;
        }
    }
    return BGS_OK;
}

int scene_update_event(window_t *win, scene_t *scene)
{
    dico_t *cursor = NULL;

    if (scene == NULL || scene->components == NULL || win == NULL) {
        return BGS_OK;
    }
    cursor = scene->components;
    do {
        if (my_strstartswith(cursor->key, SET_EVENT) == 1) {
            check_event(cursor->value, NULL, win, scene);
        }
        cursor = cursor->next;
    } while (cursor != scene->components);
    return (BGS_OK);
}
