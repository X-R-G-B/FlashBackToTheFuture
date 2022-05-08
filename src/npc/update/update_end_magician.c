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

static const char path_magician_ennemy[] = "jsp_guillaume";

static const char key_position[] = "KEY NPC POSITION";

static void go_to_next_stage(const char *str, scene_t *scene, window_t *win,
    void *data)
{
    object_t *object = data;
    sfVector2f *position = NULL;

    if (str == NULL || scene == NULL || win == NULL || data == NULL) {
        return;
    }
    position = dico_t_get_value(object->components, key_position);
    if (position == NULL) {
        return;
    }
    object->components = dico_t_rem(object->components, bool_check_key);
    create_ennemy(scene, path_magician_ennemy, *position);
}

static void callback_end_magician(__attribute__((unused)) object_t *npc,
    __attribute__((unused)) scene_t *scene, window_t *win)
{
    char *path = NULL;
    bool check = false;
    sfVector2f *position = NULL;

    path = (char *) dico_t_get_value((npc == NULL) ? NULL : npc->components,
        npc_path_key);
    check = (bool) dico_t_get_value((npc == NULL) ? NULL : npc->components,
        bool_check_key);
    if (path == NULL || check == true) {
        return;
    }
    position = malloc(sizeof(sfVector2f));
    if (position == NULL) {
        return;
    }
    position->x = npc->bigdata.sprite_bigdata.pos.x;
    position->y = npc->bigdata.sprite_bigdata.pos.y;
    object_add_components(npc, position, key_position, free);
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
        &callback_end_magician);
    if (npc != NULL) {
        call_callback_npc(npc, scene, win);
    }
    obj->components = dico_t_rem(obj->components, npc_path_key);
}
