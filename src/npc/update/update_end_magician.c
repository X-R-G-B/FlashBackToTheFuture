/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** update end magician
*/

#include <SFML/System/Vector2.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ennemies.h"
#include "my_bgs.h"
#include "my_dico.h"
#include "my_rpg.h"
#include "npc.h"
#include "maths_function.h"

extern const char npc_path_key[];
extern const char bool_check_key[];
extern const char npc_path_key[];

const char end_boss_key[] = "end boss";

const char end_magician_key[] = "end magician";

static const char path_magician_ennemy[] = "./assets/data/ennemy/magician.json";

static void go_to_next_stage(const char *str, scene_t *scene, window_t *win,
    void *data)
{
    object_t *object = data;
    ennemy_t *ennemy = NULL;

    if (str == NULL || scene == NULL || win == NULL || data == NULL) {
        return;
    }
    object->components = dico_t_rem(object->components, bool_check_key);
    ennemy = create_ennemy(scene, path_magician_ennemy,
        object->bigdata.sprite_bigdata.pos, win->path_root);
    scene->components = dico_t_add_data(scene->components, end_boss_key,
        ennemy, NULL);
    list_add_to_end(scene->to_remove, object);
}

static void callback_end_magician(__attribute__((unused)) object_t *npc,
    __attribute__((unused)) scene_t *scene, window_t *win)
{
    char *path = NULL;
    bool check = false;

    if (npc == NULL) {
        return;
    }
    path = (char *) dico_t_get_value(npc->components, npc_path_key);
    check = (bool) dico_t_get_value(npc->components, bool_check_key);
    if (path == NULL || check == true) {
        return;
    }
    add_text_dialog_json(win, path, &go_to_next_stage, npc);
    object_add_components(npc, (void *) true, bool_check_key, NULL);
}

void update_end_magician(object_t *obj, scene_t *scene, window_t *win,
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
        &callback_end_magician, win->path_root);
    if (npc != NULL) {
        call_callback_npc(npc, scene, win);
    }
    scene->components = dico_t_add_data(scene->components, end_magician_key,
        obj, NULL);
    obj->components = dico_t_rem(obj->components, npc_path_key);
}
