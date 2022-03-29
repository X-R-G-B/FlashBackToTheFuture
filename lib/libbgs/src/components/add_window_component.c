/*
** EPITECH PROJECT, 2022
** window add component
** File description:
** add_window_component
*/

#include "my_bgs_components.h"
#include "my_bgs.h"

int window_add_component(window_t *win, void *data, char key[],
    void (*destroy)(void *))
{
    if (win == NULL || data == NULL || key == NULL) {
        return BGS_ERR_INPUT;
    }
    win->components = dico_t_add_data(win->components, key, data,
        destroy);
    if (win->components == NULL || win->components->last == NULL) {
        return BGS_ERR_MALLOC;
    }
    return BGS_OK;
}
