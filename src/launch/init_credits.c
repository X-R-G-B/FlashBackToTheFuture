/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** init credits scene
*/

#include "list.h"
#include "my_bgs.h"
#include "my_bgs_button_generator.h"
#include "my_puts.h"
#include "my_rpg.h"

static const char credits_scene_name[] = "CREDITS";

static const char path_credits_button[] = "./assets/data/menu/credits.json";

int init_credits(window_t *win)
{
    scene_t *scene = NULL;
    list_ptr_t *list_btn = NULL;

    if (win == NULL) {
        return (RET_ERR_INPUT);
    }
    scene = create_scene(win, sfBlue, credits_scene_name);
    if (scene == NULL) {
        return (RET_ERR_MALLOC);
    }
    list_btn = create_button(scene, path_credits_button);
    if (list_btn == NULL) {
        return (RET_ERR_MALLOC);
    }
    free_list(list_btn);
    return (RET_OK);
}

void go_to_credits(__attribute__((unused)) object_t *obj,
    __attribute__((unused)) scene_t *scene, window_t *win,
    __attribute__((unused)) set_event_t *evt)
{
    my_putstr(1, "\n");
    if (win == NULL) {
        return;
    }
    if (window_change_scene(win, credits_scene_name) != BGS_OK) {
        my_putstr(2, "scene is not found, error\n");
    }
}

void go_to_home_direct(__attribute__((unused)) object_t *obj,
    __attribute__((unused)) scene_t *scene, window_t *win,
    __attribute__((unused)) set_event_t *evt)
{
    if (win == NULL) {
        return;
    }
    if (window_change_scene(win, "MAIN MENU") != BGS_OK) {
        my_putstr(2, "scene is not found, error\n");
    }
}
