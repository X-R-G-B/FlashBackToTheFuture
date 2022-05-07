/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** update grandpa
*/

#include <stdbool.h>
#include "my_bgs.h"
#include "my_rpg.h"
#include "npc.h"

extern const char npc_path_key[];
extern const char bool_check_key[];
extern const char npc_path_key[];

static void go_to_next_stage(const char *str, scene_t *scene, window_t *win,
    void *data)
{
    object_t *object = data;

    if (str == NULL || scene == NULL || win == NULL || data == NULL) {
        return;
    }
    object->components = dico_t_rem(object->components, bool_check_key);
    create_view_rotation(scene);
}

static void callback_intro_magician(__attribute__((unused)) object_t *npc,
    __attribute__((unused)) scene_t *scene, window_t *win)
{
    char *path = NULL;
    bool check = false;

    path = (char *) dico_t_get_value(npc->components, npc_path_key);
    check = (bool) dico_t_get_value(npc->components, bool_check_key);
    if (path == NULL || check == true) {
        return;
    }
    add_text_dialog_json(win, path, &go_to_next_stage, npc);
    object_add_components(npc, (void *) true, bool_check_key, NULL);
}

void update_intro_magician(object_t *obj, scene_t *scene, window_t *win,
    __attribute((unused)) float dtime)
{
    char *npc_path = NULL;
    object_t *npc = NULL;

    if (obj == NULL || obj->components == NULL ||
            scene == NULL || win == NULL) {
        return;
    }
    npc_path = dico_t_get_value(obj->components, npc_path_key);
    if (npc_path == NULL) {
        return;
    }
    npc = add_npc(scene, npc_path, obj->bigdata.sprite_bigdata.pos,
        &callback_intro_magician);
    if (npc != NULL) {
        call_callback_npc(npc, scene, win);
    }
    obj->components = dico_t_rem(obj->components, npc_path_key);
}
