/*
** EPITECH PROJECT, 2022
** defender
** File description:
** set window style
*/

#include "my_bgs_components.h"
#include "my_bgs.h"

static void destroy_image(void *data)
{
    sfImage_destroy(data);
}

int window_set_icon(window_t *win, char const path[])
{
    sfImage *image = NULL;
    const sfUint8 *pixels = NULL;
    sfVector2u size = {0};

    if (path == NULL || win == NULL) {
        return BGS_ERR_INPUT;
    }
    image = sfImage_createFromFile(path);
    if (image == NULL) {
        return BGS_ERR_PATH;
    }
    pixels = sfImage_getPixelsPtr(image);
    if (pixels == NULL) {
        return BGS_ERR_MALLOC;
    }
    size = sfImage_getSize(image);
    sfRenderWindow_setIcon(win->win, size.x, size.y, pixels);
    win->components = dico_t_add_data(win->components, SET_ICON, image,
        &destroy_image);
    return BGS_OK;
}
