/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** basic scene for loading time
*/

#include "my_bgs.h"
#include <SFML/Graphics/Rect.h>
#include <SFML/System/Vector2.h>

static const char background_path[] =
    "./assets/image/menu/main_menu/default_screen/background.jpg";

int create_scene_loading_basic(window_t *win)
{
    scene_t *scene = create_scene(win, sfBlack, "SCENE_LOADING_BASIC");
    object_t *obj = NULL;

    if (scene == NULL) {
        return (-1);
    }
    obj = create_object(NULL, NULL, scene, 0);
    if (obj == NULL) {
        return (-1);
    }
    object_set_sprite(obj, background_path, (sfIntRect) {-1, -1, -1, -1},
        (sfVector2f) {960, 540});
    return (0);
}
