/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** sandbox button
*/

#include "my_rpg.h"
#include "main_menu.h"
#include "npc.h"
#include "audio.h"
#include "macro.h"
#include "stage.h"

static const char sandbox_world_path[] =
    "./assets/data/story_mode/sandbox.json";

static const char sandbox_player_stats[] =
    "./assets/data/player/sandbox_stats.json";

static int init_new_scene_objects(window_t *win, scene_t *scene)
{
    if (create_map(scene) != RET_OK ||
        create_player(win, scene, sandbox_player_stats) == NULL ||
        init_hud_elements(win, scene) != RET_OK ||
        add_collision_array_in_scene(scene) != RET_OK ||
        init_dialog(scene, win) != RET_OK ||
        init_stat_upgrade_pop_up(scene,
        dico_t_get_value(win->components, HUD_ELEMENTS), win) != RET_OK ||
        create_inventory(win) != RET_OK) {
        return RET_ERR_MALLOC;
    }
    return (scene->components == NULL) ? RET_ERR_MALLOC : RET_OK;
}

static void launch_sandbox_mode(window_t *win, const char *stage_path,
    scene_t *scene)
{
    scene_t *sandbox_scene = init_scene(stage_path, win, "SANDBOX");

    if (scene == NULL || move_object_between_scene(win, scene, sandbox_scene) !=
        RET_OK || init_new_scene_objects(win, sandbox_scene) != RET_OK) {
        return;
    }
    window_change_scene(win, "SANDBOX");
}

void sandbox_button_off(object_t *obj, scene_t *scene, window_t *win,
    __attribute__((unused)) set_event_t *evt)
{
    if (obj == NULL || scene == NULL || win == NULL) {
        return;
    }
    set_is_visible_false(dico_t_get_value(scene->components, PLAY));
    set_is_visible_false(dico_t_get_value(win->components, SETTINGS_MENU));
    toggle_music_in_scene(scene);
    launch_sandbox_mode(win, sandbox_world_path, scene);
    obj->bigdata.sprite_bigdata.rect.left = 0;
}
