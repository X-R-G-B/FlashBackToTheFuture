/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** inventory_event
*/

#include "my_rpg.h"
#include "my_bgs_components.h"
#include "my_strings.h"
#include <stdlib.h>

const char ACTUAL_SCENE[] = "actual scene";

void use_heal_potion(object_t *obj, scene_t *scene,
    window_t *win, set_event_t *event)
{
    heal(win);
}

void open_inventory(object_t *obj, scene_t *scene,
    window_t *win, set_event_t *event)
{
    char *actual_scene = NULL;

    if (win == NULL || win->current_scene == NULL) {
        return;
    }
    actual_scene = my_strdup(win->current_scene);
    if (actual_scene == NULL) {
        return;
    }
    window_add_component(win, actual_scene, ACTUAL_SCENE, free);
    window_change_scene(win, INV_SCENE);
    toggle_key_obj(win);
    sfRenderWindow_setView(win->win, sfRenderWindow_getDefaultView(win->win));
}

void close_inventory(object_t *obj, scene_t *scene,
    window_t *win, set_event_t *event)
{
    char *actual_scene = NULL;

    if (win == NULL || win->components == NULL) {
        return;
    }
    actual_scene = dico_t_get_value(win->components, ACTUAL_SCENE);
    if (actual_scene == NULL) {
        return;
    }
    window_change_scene(win, actual_scene);
    win->components = dico_t_rem(win->components, ACTUAL_SCENE);
}
