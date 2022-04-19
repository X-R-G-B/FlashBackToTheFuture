/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** add_component
*/

#include "main_menu.h"

void add_scene_pop_up_component(scene_t *scene, list_ptr_t *buttons, char *key)
{
    if (scene == NULL || buttons == NULL || key == NULL) {
        return;
    }
    scene->components = dico_t_add_data(scene->components,
        key, buttons, free_pop_up);
}
