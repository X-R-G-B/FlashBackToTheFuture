/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** add new non playable character
*/

#include <SFML/System/Vector2.h>
#include <stdlib.h>
#include "my_strings.h"
#include "macro.h"
#include "my_bgs.h"
#include "my_dico.h"
#include "my_json.h"
#include "my_rpg.h"
#include "npc.h"

const char npc_json[] = "NPC JSON";

const char npc_data_callback[] = "NPC DATA";

extern const char npc_path_key[];

static int fill_pos_rect(any_t *json, sfIntRect *rect)
{
    int *rects = NULL;

    if (json == NULL) {
        return (RET_ERR_INPUT);
    }
    rects = get_any_int_array(get_from_any(json, "da", "rects", 0));
    if (rects == NULL || get_from_any(json, "daa", "rects", 0, 3) == NULL) {
        *rect = (sfIntRect) {-1, -1, -1, -1};
    } else {
        *rect = (sfIntRect) {rects[0], rects[1], rects[2], rects[3]};
    }
    free(rects);
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
    scene_t *scene, const char *path_root)
{
    object_t *npc = NULL;
    any_t *path = NULL;

    path = get_from_any(json, "d", "sprite path");
    if (path == NULL || path->type != STR) {
        return (NULL);
    }
    npc = create_object(&update_npc, NULL, scene, LAYER_ENNEMY);
    if (object_set_sprite(npc, path->value.str, rect, pos, path_root) != BGS_OK) {
        return (NULL);
    }
    path = get_from_any(json, "d", "scale");
    if (path != NULL && path->type == FLOAT) {
        sfSprite_setScale(npc->drawable.sprite, (sfVector2f) {path->value.f,
            path->value.f});
    }
    sfSprite_setTextureRect(npc->drawable.sprite,
        npc->bigdata.sprite_bigdata.rect);
    return (npc);
}

object_t *add_npc(scene_t *scene, const char *path, sfVector2f pos,
    void (*callback)(object_t *npc, scene_t *scene, window_t *win), const char *path_root)
{
    sfIntRect rect = {0};
    any_t *json = NULL;
    object_t *npc = NULL;

    if (scene == NULL || path == NULL) {
        return NULL;
    }
    json = parse_json_file(resolve_path(path_root, path));
    if (fill_pos_rect(json, &rect) != RET_OK) {
        destroy_any(json);
        return NULL;
    }
    npc = create_object_npc(rect, pos, json, scene, path_root);
    if (add_components(json, npc, callback) != RET_OK) {
        return NULL;
    }
    if (object_add_components(npc, my_strdup(path),
            npc_path_key, free) != RET_OK) {
        return NULL;
    }
    return npc;
}
