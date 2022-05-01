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

static void set_potion_text(window_t *win)
{
    any_t *text_potion = NULL;

    if (win == NULL) {
        return;
    }
    text_potion = dico_t_get_value(win->components, SAVE);
    text_potion = get_from_any(text_potion, "d", POTIONS);
    if (text_potion == NULL) {
        return;
    }
    modif_potion_value(win, text_potion->value.i);
}

void use_heal_potion(__attribute__((unused)) object_t *obj,
    __attribute__((unused)) scene_t *scene,
    window_t *win,
    __attribute__((unused)) set_event_t *event)
{
    any_t *save_data = NULL;
    any_t *potions = NULL;

    if (win == NULL) {
        return;
    }
    save_data = dico_t_get_value(win->components, SAVE);
    potions = get_from_any(save_data, "d", POTIONS);
    if (potions == NULL) {
        return;
    }
    if (potions->value.i != 0) {
        heal(win);
    }
}

void open_inventory(__attribute__((unused)) object_t *obj,
    __attribute__((unused)) scene_t *scene,
    window_t *win,
    __attribute__((unused)) set_event_t *event)
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
    get_potions(win);
    set_potion_text(win);
    sfRenderWindow_setView(win->win, sfRenderWindow_getDefaultView(win->win));
}

void close_inventory(__attribute__((unused)) object_t *obj,
    __attribute__((unused)) scene_t *scene,
    window_t *win, __attribute__((unused)) set_event_t *event)
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
