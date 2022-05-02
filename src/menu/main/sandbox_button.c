/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** sandbox button
*/

#include "my_rpg.h"

static const char sandbox_world_path[] =
    "./assets/data/story_mode/sandbox.json";

void sandbox_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    launch_stage(win, sandbox_world_path, 0, scene);
}
