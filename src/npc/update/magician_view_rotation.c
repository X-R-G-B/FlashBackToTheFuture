/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** magician view rotation
*/

#include <SFML/Window/Keyboard.h>
#include <stdbool.h>
#include "my_bgs.h"
#include "my_bgs_components.h"
#include "my_dico.h"
#include "npc.h"
#include "macro.h"
#include "rpg_struct.h"
#include "stage.h"
#include "player.h"

static const char view_rotation_data[] = "./assets/data/npc/rotation_data.json";

const char rotation_data_key[] = "rotation data";

const char total_time_key[] = "total time";

static const char actualisation_time_key[] = "actualisation time";

static const char rotation_key[] = "rotation";

static const char zoom_key[] = "zoom";

static bool check_can_go_next_stage(window_t *win)
{
    player_t *player = NULL;

    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL) {
        return (false);
    }
    if (player-> state != STOP) {
        return (false);
    }
    return (true);
}

static void update_view(player_t *player, any_t *rotation_data, float *time)
{
    any_t *rotation = get_from_any(rotation_data, "d", rotation_key);
    any_t *zoom = get_from_any(rotation_data, "d", zoom_key);
    any_t *actualisation_time = get_from_any(rotation_data, "d",
        actualisation_time_key);
    sfVector2f current_size = {0};

    if (player == NULL || player->view == NULL || actualisation_time == NULL ||
            actualisation_time->type != FLOAT || rotation == NULL ||
            rotation->type != FLOAT || zoom == NULL || zoom->type != FLOAT) {
        return;
    }
    while (*time >= actualisation_time->value.f) {
        *time -= actualisation_time->value.f;
        current_size = sfView_getSize(player->view);
        sfView_setRotation(player->view, rotation->value.f);
        sfView_setSize(player->view, (sfVector2f) {current_size.x -
            (zoom->value.f / 2), current_size.y - (zoom->value.f / 2)});
    }
}

static bool check_end(float *since_start, any_t *rotation_data, window_t *win,
    float *time)
{
    any_t *total_time = get_from_any(rotation_data, "d", total_time_key);
    player_t *player = dico_t_get_value(win->components, PLAYER);

    if (total_time == NULL || total_time->type != FLOAT || player == NULL ||
            player->view == NULL) {
        return true;
    } else if (*since_start < total_time->value.f) {
        return false;
    }
    sfView_setSize(player->view, (sfVector2f) {WIN_SIZE_X, WIN_SIZE_Y});
    sfView_setRotation(player->view, 0);
    *since_start = 0;
    *time = 0;
    launch_next_stage(win);
    return true;
}

static void update_rotation(object_t *obj, scene_t *scene, window_t *win,
    float dtime)
{
    static float since_start = 0;
    static float time = 0;
    any_t *rotation_data = NULL;

    if (obj == NULL || scene == NULL || win == NULL) {
        return;
    }
    time += dtime;
    since_start += dtime;
    rotation_data = dico_t_get_value(obj->components, rotation_data_key);
    if (rotation_data == NULL || rotation_data->type != DICT ||
            check_end(&since_start, rotation_data, win, &time) == true) {
        return;
    }
    update_view(dico_t_get_value(win->components, PLAYER),
        rotation_data, &time);
}

void create_view_rotation(scene_t *scene, const char *path_root)
{
    object_t *obj = NULL;
    window_t *win = NULL;
    any_t *rotation_data = NULL;

    win = dico_t_get_value(scene->components, WINDOW);
    if (win == NULL || check_can_go_next_stage(win) == false) {
        return;
    }
    obj = create_object(update_rotation, NULL, scene, 0);
    if (object_set_custom(obj) != BGS_OK) {
        return;
    }
    event_add_node(create_event(skip_event_magician_tp, false, obj, NULL),
        (node_params_t) {sfMouseLeft, sfKeyReturn, KEY});
    rotation_data = parse_json_file(resolve_path(path_root, view_rotation_data));
    if (rotation_data == NULL || rotation_data->type != DICT) {
        return;
    }
    obj->components = dico_t_add_data(obj->components, rotation_data_key,
        rotation_data, destroy_any);
}
