/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** add new non playable character
*/

#include <SFML/System/Vector2.h>
#include <stdlib.h>
#include "macro.h"
#include "my_bgs.h"
#include "my_dico.h"
#include "my_json.h"
#include "my_rpg.h"
#include "npc.h"

const char npc_json[] = "NPC JSON";

const char npc_data_callback[] = "NPC DATA";

static int fill_pos_rect(any_t *json, sfIntRect *rect, sfVector2f *pos)
{
    float *rects = NULL;
    float *poss = NULL;

    if (json == NULL) {
        return (RET_ERR_INPUT);
    }
    poss = get_any_float_array(get_from_any(json, "da", "pos", 0));
    if (poss == NULL || get_from_any(json, "da", "pos", 1) == NULL) {
        return (RET_ERR_INPUT);
    }
    rects = get_any_float_array(get_from_any(json, "da", "rects", 0));
    if (rects == NULL || get_from_any(json, "daa", "rects", 0, 3) == NULL) {
        *rect = (sfIntRect) {-1, -1, -1, -1};
    } else {
        *rect = (sfIntRect) {rects[0], rects[1], rects[2], rects[3]};
    }
    *pos = (sfVector2f) {poss[0], poss[1]};
    return (RET_OK);
}

static int add_components(any_t *json, object_t *npc,
    void (*callback)(object_t *npc, scene_t *scene, window_t *win))
{
    npc_data_func_t *data = NULL;

    if (npc == NULL || json == NULL) {
        return (RET_ERR_INPUT);
    }
    if (object_add_components(npc, json, npc_json, &destroy_any) != BGS_OK) {
        destroy_any(json);
    }
    data = malloc(sizeof(npc_data_func_t));
    if (data == NULL) {
        return (RET_ERR_MALLOC);
    }
    data->callback = callback;
    if (object_add_components(npc, data, npc_data_callback, free) != BGS_OK) {
        free(data);
    }
    return (RET_OK);
}

static object_t *create_object_npc(sfIntRect rect, sfVector2f pos, any_t *json,
    scene_t *scene)
{
    object_t *npc = NULL;
    any_t *path = NULL;

    path = get_from_any(json, "d", "sprite path");
    if (path == NULL || path->type != STR) {
        return (NULL);
    }
    npc = create_object(&update_npc, NULL, scene, LAYER_ENNEMY);
    if (npc == NULL) {
        return (NULL);
    }
    if (object_set_sprite(npc, path->value.str, rect, pos) != BGS_OK) {
        return (NULL);
    }
    path = get_from_any(json, "d", "scale");
    if (path != NULL && path->type == FLOAT) {
        sfSprite_setScale(npc->drawable.sprite, (sfVector2f) {path->value.i,
            path->value.i});
    }
    return (npc);
}

int add_npc(scene_t *scene, const char *path,
    void (*callback)(object_t *npc, scene_t *scene, window_t *win))
{
    sfIntRect rect = {0};
    sfVector2f pos = {0};
    any_t *json = NULL;
    object_t *npc = NULL;

    if (scene == NULL || path == NULL) {
        return (RET_ERR_INPUT);
    }
    json = parse_json_file(path);
    if (fill_pos_rect(json, &rect, &pos) != RET_OK) {
        destroy_any(json);
        return (RET_ERR_INPUT);
    }
    npc = create_object_npc(rect, pos, json, scene);
    if (add_components(json, npc, callback) != RET_OK) {
        return (RET_ERR_MALLOC);
    }
    return (RET_OK);
}
